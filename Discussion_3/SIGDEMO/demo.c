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
  // I do nothing!
}

int
main (int argc, char *argv[])
{
  // signal (SIGINT, do_nothing);
  // signal (SIGQUIT, do_nothing);
  // signal (SIGTERM, do_nothing);
  // signal (SIGKILL, do_nothing);

  while (1)
  {
    printf ("I love CS 162!\n");
    sleep (1);
  }
}
