/*
** best_driver.c for  in /home/fossae_t/rendu/CPE_2015_n4s
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Wed Apr 27 15:18:36 2016 Thomas Fossaert
** Last update Thu Apr 28 10:25:49 2016 Thomas Fossaert
*/

#include		"../inc/my.h"
#include		"get_next_line.h"

/*void			power_left(float *info, char *s)
{
  if ()
    {
      my_putstr("WHEELS_DIR:-0.3\n");
      s = get_next_line(0);
    }
  else if ()
  }*/

void			my_best_driver(float *info, char *s)
{
  if (info[31] <= 450)
    {
      my_putstr("WHEELS_DIR:0.3\n");
      s = get_next_line(0);
      }
  if (info[0] <= 450)
    {
      my_putstr("WHEELS_DIR:-0.3\n");
      s = get_next_line(0);
    }
  my_putstr("CYCLYE_WAIT:7\n");
  s = get_next_line(0);
}
