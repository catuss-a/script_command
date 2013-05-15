/*
** xfork.c for xfork in /home/catuss_a//Desktop/my_script
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Feb 26 23:32:30 2011 axel catusse
** Last update Sat Feb 26 23:34:06 2011 axel catusse
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

pid_t				xfork(void)
{
  int				pid;

  pid = fork();
  if (pid == -1)
    {
      fprintf(stderr, "error: pid(): An error has occured.\n");
      exit(EXIT_FAILURE);
    }
  return (pid);
}
