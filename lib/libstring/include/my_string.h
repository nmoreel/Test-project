/*
** my_string.h for my_string in /home/moreel_a/Documents/prepare/libstring
**
** Made by Nicolas MOREEL
** Login   <moreel_a@epitech.net>
**
** Started on  Fri Feb 24 19:32:13 2017 Nicolas MOREEL
** Last update Tue Jun 13 11:55:17 2017 Nicolas MOREEL
*/

#ifndef			__STRING_H__
# define		__STRING_H__

char*			my_strcpy(char* dest, const char* src);
char*			my_strncpy(char* dest, const char* src, unsigned int size);
unsigned int		my_strlen(const char*);
char*			my_strdup(const char*);
int			my_getnbr(const char*);
char*			epurstr(char*);
char**			my_str_to_wordtab(const char*, char sep);

#endif			/* __STRING_H__ */
