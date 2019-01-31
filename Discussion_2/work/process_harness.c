/* To be paired with Discussion 2 of CS 162. Harness for counting
   number of processes spawned through the fork command.

   Created by Jonathan Murata 01/05/2019 for CS 162 Spring 2019.
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "process_harness.h"
#include "basic_loop.h"
#include "stack_allocation.h"

/* Variables shared among processes to keep track of total spawns.
   This is necessary becuase otherwise we could only know the number
   of processes one particular process spawns instead of the total
   number of spawns for an entire program. */
int *glob_var;
sem_t *sem;

/* Fork that will allow use to see how many processes are actually created.
   This is a wrapper for the the built 'fork' command to work with the harness. */
pid_t
harness_fork ()
{
  /* Increment the shared counter. Need synchronization primitives to avoid
     nondeterministic race conditions. */
  sem_wait (sem);
  (*glob_var)++;
  sem_post (sem);

  /* Call built in fork () command and return its result. */
  return fork ();
}

/* Main function to be run from the commandline.
   Will support any program that has up to 10 children processes.
   Not guaranteed to be synched for more (but can modify). */
int
main (int argc, char *argv[])
{
  if (argc < 2) {
    printf ("Please specify what you would like to run. The command should look something like './main basic'\n");
    return 0;
  }

  /* Main process initializes shared memory */
  glob_var = mmap (NULL, sizeof *glob_var, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  *glob_var = 1; // 1 process created - the current one

  sem = mmap (NULL, sizeof (sem_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  sem_init (sem, 1, 1);

  /* Want to know what the 'main' process is */
  pid_t current = getpid ();

  /* Run different programs */
  if (!strcmp (argv[1], "basic"))
    {
      printf("Running basic loop:\n");
      basic_loop ();
    }
  else if (!strcmp (argv[1], "stack"))
    {
      printf("Running Stack Allocation Question:\n");
      stack_allocation ();
    }
  else if (!strcmp (argv[1], "stack2"))
    {
      printf("Running Stack Allocation Question 500 Times:\n");
      FILE *sfile = fopen ("sfile.txt", "w+");
      dup2 (fileno(sfile), 1);
      pid_t og = getpid ();
      for (int i = 0; i < 500; i++)
        {
          stack_allocation ();
          if (getpid () != og)
            return 0;
        }
    }

    /* Wait for all child process (up to 10) are finished */
    for (int i = 0; i < 10; i++)
      wait (NULL);

    /* Only print results if current process is 'main' */
    if (getpid () == current)
      printf("Total threads created (including first one) = %d\n", *glob_var);

    return 0;
}
