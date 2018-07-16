/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/moreel_a/Documents/Tek1/Piscine/Soutien
**
** Made by Nicolas MOREEL
** Login   <moreel_a@epitech.net>
**
** Started on  Tue Oct 21 16:57:59 2014 Nicolas MOREEL
** Last update Tue Jun 13 11:43:42 2017 Nicolas MOREEL
*/

#include	<stdlib.h>
#include	"my_string.h"

static int	count_word(const char* str, char sep)
{
  int		i;
  int		cnt;

  i = 0;
  cnt = 0;
  while (str[i] != '\0')
    {
      if (str[i] == sep)
	++cnt;
      ++i;
      if (str[i] == '\0')
	++cnt;
    }
  return cnt;
}

static char*	getNextWord(const char* str, int endWord)
{
  static int	j = 0;
  char*		word;

  if ((word = malloc(sizeof(*word) * (endWord - j + 1))) != NULL)
    {
      word = my_strncpy(word, str + j, endWord - j);
      j = endWord + 1;
    }
  return word;
}

char**		my_str_to_wordtab(const char* str, char sep)
{
  char**	result = NULL;
  int		i = 0;
  int		index = 0;

  if (str == NULL)
    return NULL;
  if ((result = malloc(sizeof(*result) * (count_word(str, sep) + 1))) == NULL)
    return NULL;
  while (str[i]) {
    if (str[i] == sep) {
      if ((result[index] = getNextWord(str, i)) == NULL)
      	return NULL;
      index += 1;
      }
    ++i;
  }
  if ((result[index] = getNextWord(str, i)) == NULL)
    return NULL;
  index += 1;
  result[index] = NULL;
  return result;
}
