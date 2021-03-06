/*
** gere_window.c for gere_window in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri May 10 08:43:23 2013 remi robert
** Last update Sun May 26 03:12:25 2013 luc sinet
*/

#include "42sh.h"

int	get_window_size(char *cmd, int add_prompt)
{
  int	size;
  int	size_cmd;

  size_cmd = my_strlen(cmd) + add_prompt;
  size = return_x() * return_y();
  if (size <= size_cmd)
    return (0);
  return (1);
}

void	my_putstr_view(char *cmd, int add_prompt, t_param *param)
{
  int	size;
  int	size_cmd;

  size_cmd = my_strlen(cmd) + add_prompt;
  size = return_x() * return_y();
  if (size <= size_cmd && size >= my_strlen("Window too small"))
    {
      curseur(0, 0);
      my_putstr(param->termcap.str_cd, param->fd_tty, -1);
      my_putstr("Window too small", 1, -1);
    }
  else
    {
      my_putstr(cmd, 1, -1);
      curseur(param->x, param->y);
    }
}
