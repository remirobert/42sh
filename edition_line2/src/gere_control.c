/*
** gere_control.c for gere_controle in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon May  6 09:13:35 2013 remi robert
** Last update Fri May 10 18:45:38 2013 remi robert
*/

#include "termcap.h"

void	calc_end_param_x(char *cmd, t_param *param, int *x, int *y)
{
  int	size_x;
  int	size_y;
  int	indice;

  indice = param->pos;
  size_x = return_x();
  size_y = return_y();
  while (cmd[indice] != '\0')
    {
      indice += 1;
      *x += 1;
      if (*x == size_x)
	{
	  *x = 0;
	  if (*y < size_y)
	    *y += 1;
	}
    }
}

void	fct_control(char *cmd, t_param *param, int indice)
{
  void	(*t[6])(char *, t_param *);

  t[0] = &gere_control_k;
  t[1] = &gere_control_y;
  t[2] = &begin_cmd;
  t[3] = &end_cmd;
  t[4] = &clear_cmd;
  t[5] = &globb;
  if (indice >= 0 && indice < 6)
    t[indice](cmd, param);
}

int	return_gere_control_string(char *cmd, t_param *param, char *buff)
{
  if (str_cmp(buff, BEGIN_STR) == 1)
    {
      fct_control(cmd, param, 2);
      return (0);
    }
  if (str_cmp(buff, END_STR) == 1)
    {
      fct_control(cmd, param, 3);
      return (0);
    }
  return (1);
}

int	gere_control(char *cmd, t_param *param, char *buff)
{
  char	caractere[6];
  int	indice;

  caractere[0] = CTRLK;
  caractere[1] = CTRLY;
  caractere[2] = CTRLA;
  caractere[3] = CTRLE;
  caractere[4] = CTRLL;
  caractere[5] = '\t';
  indice = -1;
  while (++indice < 6)
    if (caractere[indice] == buff[0] && buff[1] == '\0')
      {
	fct_control(cmd, param, indice);
	return (0);
      }
  return (return_gere_control_string(cmd, param, buff));
}
