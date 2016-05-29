/*
** main.c for main.c in /home/fossae_t/rendu/CPE_2015_n4s
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue Apr 26 10:38:38 2016 Thomas Fossaert
** Last update Sun May 29 22:50:23 2016 Thomas Fossaert
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		"../inc/my.h"
#include		"get_next_line.h"

char			*epur_s(char *str, char *tmp)
{
  int			i;
  int			j;

  i = 0;
  j = 21;
  tmp = malloc(sizeof(char) * my_strlen(str) -21);
  while (str[j] != '\0')
    {
      tmp[i] = str[j];
      i++;
      j++;
    }
  return (tmp);
}

void		my_free_double(char **buffer)
{
  int		i;

  i = 0;
  while (buffer[i] != '\0')
    {
      free(buffer[i]);
      i++;
    }
  free(buffer);
}

int			*my_sto_info(int *info, char *s)
{
  int			i;
  char			*tmp;
  char			**tmp_dou;

  i = 0;
  tmp = epur_s(s, tmp);
  tmp_dou = my_str_to_wordtab(tmp, ":");
  info = malloc(sizeof(int) * 32);
  while (i != 32)
    {
      info[i] = my_getnbr(tmp_dou[i]);
      i++;
    }
  my_free_double(tmp_dou);
  return (info);
}

void			check_extreme(int *info, char *s)
{
  if (info[0] <= 150)
    {
      my_putstr("WHEELS_DIR:-0.05\n");
      s = get_next_line(0);
      my_putstr("CYCLE_WAIT:2\n");
      s = get_next_line(0);
    }
  if (info[31] <= 150)
    {
      my_putstr("WHEELS_DIR:0.05\n");
      s = get_next_line(0);
      my_putstr("CYCLE_WAIT:2\n");
      s = get_next_line(0);
    }
}

int			main(void)
{
  char			*s;
  int			*info;

  my_putstr("START_SIMULATION\n");
  s = get_next_line(0);
  my_putstr("CAR_FORWARD:0.5\n");
  s = get_next_line(0);
  while (42)
    {
      my_putstr("GET_INFO_LIDAR\n");
      s = get_next_line(0);
      info = my_sto_info(info, s);
      my_best_driver(info, s);
      free(info);
      my_puterror(s);
    }
  return (0);
}
