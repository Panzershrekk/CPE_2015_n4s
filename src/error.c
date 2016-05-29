/*
** error.c for error in /home/fossae_t/rendu/PSU_2015_minishell2
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Apr 14 19:11:32 2016 Thomas Fossaert
** Last update Sun May 29 18:07:20 2016 Thomas Fossaert
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"get_next_line.h"
#include	"../inc/my.h"

void		my_putcharerror(char c)
{
  write(2, &c, 1);
}

void		check_end(int j, char *s)
{
  if (j > 12)
    {
      my_putstr("CAR_BACKWARDS:0\n");
      s = get_next_line(0);
      my_putstr("CYCLE_WAIT:3\n");
      s = get_next_line(0);
      my_putstr("STOP_SIMULATION\n");
    }
}

void		my_puterror(char *str)
{
  int		i;
  int		j;
  char		*s;
  const char	*track;

  i = 0;
  j = 0;
  if (str[2] != 'O')
    write(2, str, my_strlen(str));
  track = "Track Cleared\0";
  while (str[i])
    {
      while (str[i] == track[j])
	{
	  i++;
	  j++;
	}
      i++;
    }
  check_end(j, s);
}
