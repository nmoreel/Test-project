/*
** my_getnbr.c for my_getnbr in /home/moreel_a/Documents/test-blih/test
**
** Made by Nicolas MOREEL
** Login   <moreel_a@epitech.net>
**
** Started on  Tue Oct  7 13:40:48 2014 Nicolas MOREEL
** Last update Fri Feb 24 19:44:30 2017 Nicolas MOREEL
*/

#include "my_string.h"

static int	slen(const char* str, char c)
{
  int	i;

  i = 0;
  while (str[i] != c && str[i] != '\0')
    ++i;
  return (i);
}

int	my_getnbr_base(char* str, const char* base)
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
      tmp *= slen(base, '\0');
      tmp += slen(base, str[i]);
    }
  return (tmp * flag);
}
