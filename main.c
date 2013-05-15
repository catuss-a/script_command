/*
** main.c for my_script in /home/catuss_a//Desktop/my_script
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Fri Feb 25 18:10:00 2011 axel catusse
** Last update Sat Feb 26 23:34:56 2011 axel catusse
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include "my_script.h"

static void			creat_processus(t_myscript *sct)
{
  int				pid;

  pid = xfork();
  if (pid == 0)
    {
      pid = xfork();
      if (pid == 0)
	read_on_master(sct);
      else
	execute_shell(sct);
    }
  else
    write_on_master(sct);
}

int				main(int ac, char **av)
{
  t_myscript			sct;

  memset(&sct, 0, sizeof(sct));
  get_ptr_sct(&sct);
  signal(SIGCHLD, signal_hand);
  getoptions_and_create_file(&sct, ac, av);
  tcgetattr(0, &sct.tt);
  ioctl(0, TIOCGWINSZ, (char *)&sct.win);
  if (my_openpty(&sct) == -1)
    {
      fprintf(stderr, OPENPTY_ERROR);
      return (EXIT_FAILURE);
    }
  print_start(0, &sct);
  set_tty_cfg(&sct.tt);
  creat_processus(&sct);
  return (1);
}
