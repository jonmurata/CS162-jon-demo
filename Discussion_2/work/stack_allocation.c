/* What can C print? */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "process_harness.h"
#include <string.h>
#include "basic_loop.h"
#include "stack_allocation.h"



int
stack_allocation ()
{
  int stuff = 7;
  pid_t pid = fork ();
  printf("Stuff is %d\n", stuff);
  if (pid == 0)
    stuff = 6;
}
