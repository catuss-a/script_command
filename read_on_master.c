/*
** read_on_master.c for scrpt in /home/catuss_a//Desktop/my_script
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Feb 26 23:26:37 2011 axel catusse
** Last update Sat Feb 26 23:27:42 2011 axel catusse
*/

#include <stdio.h>
#include <unistd.h>
#include "my_script.h"

void				read_on_master(t_myscript *sct)
{
  int				rret;
  char				buffer[BUFSIZ];
  int				wret;
  FILE				*ffd;

  close(sct->slave);
  close(0);
  ffd = fdopen(sct->filefd, CHECK_FLG(sct->options, FLAG_A) ? "a" : "w");
  while (42)
    {
      rret = read(sct->master, buffer, sizeof (buffer));
      if (rret <= 0)
	break;
      wret = write(1, buffer, rret);
      write(sct->filefd, buffer, rret);
      if (CHECK_FLG(sct->options, FLAG_F))
	fflush(ffd);
    }
  fclose(ffd);
  close(sct->filefd);
  close(sct->master);
}
