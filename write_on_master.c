/*
** write_on_master.c for script in /home/catuss_a//Desktop/my_script
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Feb 26 23:21:21 2011 axel catusse
** Last update Sat Feb 26 23:22:44 2011 axel catusse
*/

#include <unistd.h>
#include <stdio.h>
#include "my_script.h"

void				write_on_master(t_myscript *sct)
{
  int				rret;
  char				buffer[BUFSIZ];

  close(sct->slave);
  close(sct->filefd);
  while (42)
    {
      if ((rret = read(0, buffer, BUFSIZ)) > 0)
	write(sct->master, buffer, rret);
      else
	break ;
    }
  close(sct->master);
}
