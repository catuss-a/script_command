/*
** print_start.c for scruot in /home/catuss_a//Desktop/my_script
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Feb 26 23:27:57 2011 axel catusse
** Last update Sat Feb 26 23:28:35 2011 axel catusse
*/

#include <unistd.h>
#include <string.h>
#include "my_script.h"

void				print_start(int fd, t_myscript *sct)
{
  if (CHECK_FLG(sct->options, FLAG_Q) == 0)
    {
      write(fd, "Script started, file is ",
	    strlen("Script started, file is "));
      write(fd, sct->filename, strlen(sct->filename));
      write(fd, "\n", 1);
    }
}
