/*
** print_usage.c for print in /home/catuss_a//Desktop/my_script
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Feb 26 23:19:09 2011 axel catusse
** Last update Sat Feb 26 23:20:36 2011 axel catusse
*/

#include <stdio.h>
#include <stdlib.h>

void				print_usage(void)
{
  fprintf(stderr, "usage: script [-a] [-f] [-q] [-t] [file]\n");
  exit(EXIT_FAILURE);
}
