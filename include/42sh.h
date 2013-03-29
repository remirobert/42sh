/*
** 42sh.h for 42sh in /home/maxime/Bureau/projet/actu/42sh/include
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Mar 19 10:39:43 2013 maxime lavandier
** Last update Mon Mar 25 13:31:46 2013 maxime lavandier
*/

#ifndef		42SH_H
# define		42SH_H

typedef struct	s_fds
{
  int		stdin;
  int		stdout;
  int		stderr;
}		t_fds;

typedef struct	s_pid
{
  pid_t		sid;
  pid_t		pid;
  pid_t		pgid;
}		t_pid;

typedef struct	s_cmd
{
  char		*line;
  char		**argv;
  int		return_value;
  t_fds		fd;
  t_pid		pid;
}		t_cmd;

typedef struct	s_pipe
{
  t_fds		fd;
  t_pid		pid;
  char		*line;
  t_cmd		**cmds;
  int		running;
}		t_pipe;

typedef struct	s_sh
{
  t_pid		pid;
  char		**path;
  char		**env;
  t_pipe		**pipes;
  t_pipe		*forground;
}		t_sh;

#endif
