/*
** my_cpy.c for my_cpy in /home/moreel_a/Documents/prepare
**
** Made by Nicolas MOREEL
** Login   <moreel_a@epitech.net>
**
** Started on  Tue Nov 25 23:40:51 2014 Nicolas MOREEL
** Last update Fri Jun 28 11:04:15 2018 Nicolas MOREEL
*/

#include    <stdlib.h>
#include		"my_string.h"

char*			my_strcpy(char* dest, const char* src)
{
  unsigned int		i;

  i = 0;
  if (dest == NULL)
    return NULL;
  while (src && src[i] != '\0')
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return dest;
}

char*			my_strncpy(char* dest, const char* src, unsigned int size)
{
  unsigned int		i;

  i = 0;
  if (dest == NULL)
    return NULL;
  while (src && src[i] != '\0' && i < size)
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return dest;
}
