/*
** init_struct_param.c for para in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Apr  9 15:26:37 2013 remi robert
** Last update Tue Apr  9 22:07:48 2013 remi robert
*/

#include "../include/my_func.h"

void		init_struct_param(t_param *param)
{
  get_pos_curser(&(param->begin_pos.x), &(param->begin_pos.y));
  param->begin_pos.x += my_strlen(param->str_prompt);
  param->current_pos.x = param->begin_pos.x;
  param->current_pos.y = param->begin_pos.y;
  param->prompt.y = param->begin_pos.y;
  param->prompt.x = 0;
  curseur(param->current_pos.x, param->current_pos.y);
  param->string = NULL;
  param->len_string = 0;
  param->buff_copy[0] = END;
  mod_raw();
}