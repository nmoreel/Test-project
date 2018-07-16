/*
** my_putstr.c for workshop_tu in /home/nmoreel/documents/workshop_TUs/src
**
** Made by Nicolas MOREEL
** Login   <nicolas1.moreel-lebon@epitech.eu>
**
** Started on  Thu Jun 21 15:28:46 2018 Nicolas MOREEL
** Last update Thu Jun 21 15:28:46 2018 Nicolas MOREEL
*/

#include    <unistd.h>

int         my_strlen(const char*);

int         my_putstr(const char* str)
{
    return write(1, str, my_strlen(str));
}