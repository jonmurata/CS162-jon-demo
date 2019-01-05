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

int
main (int argc, char *argv[])
{
  // signal (SIGINT, do_nothing);

  // signal (SIGQUIT, print_hi);

  // signal (SIGTERM, SIG_IGN);
  // signal (SIGKILL, SIG_IGN);

  // signal (SIGINT, SIG_DFL);

  while (1)
  {
    printf ("I love CS 162!\n");
    sleep (1);
  }
}
