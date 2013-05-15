/*
** get_ptr_sct.c for get ptr sct in /home/catuss_a//Desktop/my_script
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Feb 26 20:39:21 2011 axel catusse
** Last update Sat Feb 26 20:42:39 2011 axel catusse
*/

#include <stdlib.h>

void				*get_ptr_sct(void *p)
{
  static void			*save = NULL;

  if (save == NULL)
    save = p;
  return (save);
}
