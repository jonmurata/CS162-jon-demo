/* To be paired with Discussion 3 of CS 162.
   This file contains a demo to explain signal handlers and signals.

   Created by Jonathan Murata 01/05/2019 for CS 162 Spring 2019.
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#define SIGINT 2
#define SIGQUIT 3
#define SIGTERM 15
#define SIGKILL 9

void
do_nothing ()
{
  /* I do nothing! */
}

void
print_hi ()
{
  printf ("Hi!\n");
}

/* Ininitely loop and print "I love CS 162!". Should be externally interrupted to terminate.*/
int
main (int argc, char *argv[])
{
  // signal (SIGINT, do_nothing); // 1

  // signal (SIGQUIT, print_hi); // 2

  // signal (SIGTERM, SIG_IGN); // 3
  // signal (SIGKILL, SIG_IGN);

  // signal (SIGINT, SIG_DFL); // 4

  while (1)
  {
    printf ("I love CS 162!\n");
    sleep (1);
  }
}
