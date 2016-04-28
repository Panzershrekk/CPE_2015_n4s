/*
** main.c for main.c in /home/fossae_t/rendu/CPE_2015_n4s
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue Apr 26 10:38:38 2016 Thomas Fossaert
** Last update Wed Apr 27 17:19:22 2016 Thomas Fossaert
*/

#include		<stdlib.h>
#include		"../inc/my.h"
#include		"get_next_line.h"

char			*epur_s(char *str, char *tmp)
{
  int			i;
  int			j;

  i = 0;
  j= 21;
  tmp = malloc(sizeof(char) * my_strlen(str) -21);
  while (str[j] != '\0')
    {
      tmp[i] = str[j];
      i++;
      j++;
    }
  return (tmp);
}

float			*my_sto_info(float *info, char *s)
{
  int			i;
  char			*tmp;
  char			**tmp_dou;

  i = 0;
  tmp = epur_s(s, tmp);
  tmp_dou = my_str_to_wordtab(tmp);
  info = malloc(sizeof(float) * 32);
  while (i != 32)
    {
      info[i] = my_getnbr(tmp_dou[i]);
      i++;
    }
  return (info);
}

int			main(void)
{
  char			*s;
  float			*info;

  my_putstr("START_SIMULATION\n");
  s = get_next_line(0);
  my_putstr("CAR_FORWARD:0.3\n");
  s = get_next_line(0);
  while (42)
    {
      my_putstr("GET_INFO_LIDAR\n");
      s = get_next_line(0);
      info = my_sto_info(info, s);
      my_best_driver(info, s);
    }
  return (0);
}
