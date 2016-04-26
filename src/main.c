/*
** main.c for main.c in /home/fossae_t/rendu/CPE_2015_n4s
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue Apr 26 10:38:38 2016 Thomas Fossaert
** Last update Tue Apr 26 14:29:42 2016 Thomas Fossaert
*/

#include		"my.h"
#include		"get_next_line.h"

int			main(void)
{
  char			*s;

  my_putstr("START_SIMULATION\n");
  s = get_next_line(0);
  my_puterror(s);
  my_putstr("CAR_FORWARD:");
  my_put_nbr(1);
  my_putchar('\n');
  s = get_next_line(0);
  my_puterror(s);
  while (0);
  return (0);
}
