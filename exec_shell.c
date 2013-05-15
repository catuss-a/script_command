/*
** exec_shell.c for script in /home/catuss_a//Desktop/my_script
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Feb 26 23:23:04 2011 axel catusse
** Last update Wed May 15 14:38:40 2013 axl
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_script.h"

void				execute_shell(t_myscript *sct)
{
  setsid();
  ioctl(sct->slave, TIOCSCTTY, 0);
  close(sct->master);
  close(sct->filefd);
  dup2(sct->slave, 0);
  dup2(sct->slave, 1);
  dup2(sct->slave, 2);
  close(sct->slave);
  if (CHECK_FLG(sct->options, FLAG_C) == 0)
    execlp("tcsh", "tcsh", NULL);
  else
    execlp("tcsh", "tcsh", "-c", sct->cmd_flgc, NULL);
  printf("error: execlp(): you prolly need tcsh installed.\n");
  exit(0);
}
