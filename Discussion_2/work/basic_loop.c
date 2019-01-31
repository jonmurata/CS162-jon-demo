/* Call fork in a loop */

#include <sys/types.h>
#include "process_harness.h"

int
basic_loop ()
{
  for (int i = 0; i < 3; i++)
    {
      pid_t temp = harness_fork ();
    }
}
