/*
** my_getnbr.c for my_getnbr in /home/moreel_a/Documents/test-blih/test
**
** Made by Nicolas MOREEL
** Login   <moreel_a@epitech.net>
**
** Started on  Tue Oct  7 13:40:48 2014 Nicolas MOREEL
** Last update Fri Feb 24 19:42:27 2017 Nicolas MOREEL
*/

#include "my_string.h"

int	my_getnbr(const char* str)
{
  int	flag;
  int	tmp;
  int	i;

  flag = 1;
  if (str[0] == '-')
    {
      flag = -1;
      i = 0;
    }
  else
    i = -1;
  tmp = 0;
  while (str[++i] != '\0')
    {
      tmp *= 10;
      tmp += str[i] - '0';
    }
  return (tmp * flag);
}
