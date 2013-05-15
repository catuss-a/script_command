/*
** my_opentty.c for my_openpty in /home/catuss_a//Desktop/my_script
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Feb 26 16:32:28 2011 axel catusse
** Last update Sat Feb 26 21:40:24 2011 axel catusse
*/

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include "my_script.h"

static char			*my_ptsname(int fd)
{
  unsigned int			pty_num;
  static char			buff[64];

  if (ioctl(fd, TIOCGPTN, &pty_num) != 0)
    return (NULL);
  snprintf(buff, sizeof(buff), "/dev/pts/%u", pty_num);
  return (buff);
}

static int			my_unlockpt(int fd)
{
  int				a;

  return (ioctl(fd, TIOCSPTLCK, &a));
}

int				my_openpty(t_myscript *sct)
{
  struct stat			st;
  char				*sname;

  if ((sct->master = open("/dev/ptmx", O_RDWR | O_NOCTTY)) < 0)
    return (-1);
  if (my_unlockpt(sct->master) < 0)
    return (-1);
  if ((fstat(sct->master, &st)) < 0)
    return (-1);
  if ((sname = my_ptsname(sct->master)) == NULL)
    return (-1);
  if ((chmod(sname, st.st_mode | S_IRUSR | S_IWUSR | S_IWGRP)) < 0)
    return (-1);
  if ((sct->slave = open(sname, O_RDWR)) < 0)
    return (-1);
  return (0);
}
