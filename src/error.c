/*
** error.c for error in /home/fossae_t/rendu/PSU_2015_minishell2
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Apr 14 19:11:32 2016 Thomas Fossaert
** Last update Tue Apr 26 15:54:24 2016 Thomas Fossaert
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"../inc/my.h"

void		my_putcharerror(char c)
{
  write(2, &c, 1);
}

void		my_puterror(char *str)
{
  write(2, str, my_strlen(str));
}
