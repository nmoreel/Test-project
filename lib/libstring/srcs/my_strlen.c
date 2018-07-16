/*
** my_strlen.c for my_strlen in /home/moreel_a/Documents/Tek1/Piscine/Soutien
**
** Made by Nicolas MOREEL
** Login   <moreel_a@epitech.net>
**
** Started on  Fri Oct 10 14:31:15 2014 Nicolas MOREEL
** Last update Fri Feb 24 19:34:45 2017 Nicolas MOREEL
*/

#include "my_string.h"

unsigned int	my_strlen(const char* str)
{
  unsigned int	index = 0;

  while (str && str[index] != '\0')
    ++index;
  return index;
}
