/*
** my_putstr.c for my_putstr in /home/remi/Projet/alum1/lib
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Feb  4 08:57:30 2013 remi robert
** Last update Tue Apr  9 17:12:06 2013 remi robert
*/

#include "../../include/my_func.h"

void	my_put_str(char *str)
{
  if (str == NULL)
    return ;
  write(1, str, my_strlen(str));
}