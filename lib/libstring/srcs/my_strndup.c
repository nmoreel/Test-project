/*
** my_strndup.c for my_strndup in /home/moreel_a/Documents/prepare/libstring
**
** Made by Nicolas MOREEL
** Login   <moreel_a@epitech.net>
**
** Started on  Fri Feb 24 19:54:29 2017 Nicolas MOREEL
** Last update Fri Feb 24 19:55:41 2017 Nicolas MOREEL
*/


#include	<stdlib.h>
#include	"my_string.h"

char*		my_strndup(const char* str, unsigned int bytes)
{
  char*		new;

  if (str == NULL)
    return NULL;
  if ((new = malloc(sizeof(*new) * (bytes + 1))) == NULL)
    return NULL;
  new = my_strncpy(new, str, bytes);
  return new;
}
