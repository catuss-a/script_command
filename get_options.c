/*
** get_options.c for get option in /home/catuss_a//Desktop/my_script
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Feb 26 19:22:03 2011 axel catusse
** Last update Sat Feb 26 23:04:30 2011 axel catusse
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include "my_script.h"

static void			creat_file(t_myscript *sct, int ac,
					   char **av)
{
  extern int			optind;

  sct->filename = ac - optind > 0 ? av[optind] : DFT_NAME;
  if ((sct->filefd = open(sct->filename,
			  CHECK_FLG(sct->options, FLAG_A) == 0 ?
			  OPEN_TRUNC : OPEN_APPEND
			  , RIGHT_FLAGS)) < 0)
    {
      fprintf(stderr, OPEN_ERROR);
      exit(EXIT_FAILURE);
    }
  return ;
}

void				getoptions_and_create_file(t_myscript *sct,
							   int ac,
							   char **av)
{
  int				c;

  sct->options = 0;
  while ((c = getopt(ac, av, "c:aftq")) != -1)
    {
      if (c == 'a')
	sct->options |= FLAG_A;
      else if (c == 'c')
	{
	  sct->cmd_flgc = optarg;
	  sct->options |= FLAG_C;
	}
      else if (c == 'f')
	sct->options |= FLAG_F;
      else if (c == 'q')
	sct->options |= FLAG_Q;
      else if (c == 't')
	sct->options |= FLAG_T;
      else if (c == '?')
	print_usage();
    }
  creat_file(sct, ac, av);
  return ;
}
