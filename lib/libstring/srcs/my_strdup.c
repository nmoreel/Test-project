/*
** my_strdup.c for my_strdup in /home/moreel_a/Documents/Tek1/Piscine/Soutien
**
** Made by Nicolas MOREEL
** Login   <moreel_a@epitech.net>
**
** Started on  Sun Oct 26 00:20:11 2014 Nicolas MOREEL
** Last update Fri Feb 24 19:37:20 2017 Nicolas MOREEL
*/

#include	<stdlib.h>
#include	"my_string.h"

char*		my_strdup(const char* str)
{
  char*		new;

  if ((new = malloc(sizeof(*new) * (my_strlen(str) + 1))) == NULL)
    return NULL;
  new = my_strcpy(new, str);
  return new;
}
