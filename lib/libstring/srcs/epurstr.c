/*
** epurstr.c for epurstr in /home/moreel_a/Documents/prepare/libstring
**
** Made by Nicolas MOREEL
** Login   <moreel_a@epitech.net>
**
** Started on  Fri Mar 31 19:29:59 2017 Nicolas MOREEL
** Last update Tue Jun 13 11:55:37 2017 Nicolas MOREEL
*/

#include	"my_string.h"

char*		epurstr(char* str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (str[0] == ' ' || str[0] == '\t')
    while (str[i] == ' ' || str[i] == '\t')
      ++i;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	while (str[i + 1] == ' ' || str[i + 1] == '\t')
	  ++i;
      if (str[i + 1] !=  '\0')
	str[j++] = str[i];
      if (str[i + 1] == '\0' && (str[i] == ' ' || str[i] == '\t'))
	str[j] = '\0';
      ++i;
    }
  str[j] = '\0';
  return str;
}
