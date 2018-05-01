#include <sys/prctl.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int     main(int argc, char **argv)
{
  write(1, "lol", 3);
  if (argc > 1)
    {
      if (argc == 3 && argv[2][0] == '1')
        {
          prctl(PR_SET_DUMPABLE, 0);
        }
      raise(strtol(argv[1], NULL, 10));
    }
  raise(1);
}

/*
Exemple:
> ./my_sig 11 0
lolSegmentation fault (core dumped)
> ./my_sig 11 1
lolSegmentation fault
*/
