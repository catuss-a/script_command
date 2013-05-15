/*
** my_signal.c for signal in /home/catuss_a//Desktop/my_script
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Feb 26 23:19:51 2011 axel catusse
** Last update Sat Feb 26 23:36:25 2011 axel catusse
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_script.h"

void				signal_hand(int sig)
{
  t_myscript			*sct;

  sct = get_ptr_sct(NULL);
  if (CHECK_FLG(sct->options, FLAG_Q) == 0)
    {
      tcsetattr(0, TCSADRAIN, &sct->tt);
      printf("Script done, file is %s\n", sct->filename);
    }
  signal(sig, signal_hand);
  exit(0);
}
