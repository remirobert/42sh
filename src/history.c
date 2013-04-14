/*
** history.c for history.c in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri Apr 12 19:14:58 2013 remi robert
** Last update Sun Apr 14 17:54:58 2013 remi robert
*/

#include "42sh.h"

int		view_history(char *path, char **argv, char **envp)
{
  t_history	*pcourant;

  if (argv[0] == NULL)
    return (-1);
  pcourant = (t_history*)argv[0];
  while (pcourant->next != NULL)
    pcourant = pcourant->next;
  while (pcourant != NULL)
    {
      my_putstr(" ", 1, -1);
      my_put_nbr(pcourant->nb_history);
      my_putstr("  ", 1, -1);
      my_putstr(pcourant->cmd, 1, -1);
      my_putstr("\n", 1, -1);
      pcourant = pcourant->back;
    }
  my_exit(0);
  return (-1);
}

void		clear_history(t_history *ptr)
{
  if (ptr == NULL)
    return ;
  while (ptr->next != NULL)
    {
      ptr = ptr->next;
      if (ptr->back->cmd != NULL)
	free(ptr->back->cmd);
      free(ptr->back);
    }
  if (ptr->cmd != NULL)
    free(ptr->cmd);
  free(ptr);
}
