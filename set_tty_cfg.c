/*
** set_tty_cfg.c for script in /home/catuss_a//Desktop/my_script
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Feb 26 23:28:52 2011 axel catusse
** Last update Sat Feb 26 23:36:35 2011 axel catusse
*/

#include "my_script.h"

void				set_tty_cfg(struct termios *tt)
{
  struct termios		rtt;

  rtt = *tt;
  cfmakeraw(&rtt);
  tcsetattr(0, TCSANOW, &rtt);
}
