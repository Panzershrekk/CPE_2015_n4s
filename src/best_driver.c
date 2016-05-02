/*
** best_driver.c for  in /home/fossae_t/rendu/CPE_2015_n4s
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Wed Apr 27 15:18:36 2016 Thomas Fossaert
** Last update Mon May  2 12:42:31 2016 Thomas Fossaert
*/

#include		"../inc/my.h"
#include		"get_next_line.h"

void			manage_speed(float *info, char *s)
{
  if (info[15] <= 1000)
    {
      my_putstr("CAR_FORWARD:0.3\n");
      s = get_next_line(0);
    }
  else if (info[15] <= 1500)
    {
      my_putstr("CAR_FORWARD:0.6\n");
      s = get_next_line(0);
    }
  else if (info[15] <= 2500)
    {
      my_putstr("CAR_FORWARD:0.8\n");
      s = get_next_line(0);
    }
  else if (info[15] > 2500)
    {
      my_putstr("CAR_FORWARD:1\n");
      s = get_next_line(0);
  }
}

void			power_left(float *info, char *s)
{
  /*if (info[31] > 400)
    {
      my_putstr("WHEELS_DIR:0\n");
      s = get_next_line(0);
      }*/
  if (info[31] <= 390)
    {
      my_putstr("WHEELS_DIR:0.3\n");
      s = get_next_line(0);
    }
  else if (info[30] <= 430)
    {
      my_putstr("WHEELS_DIR:0.2\n");
      s = get_next_line(0);
    }
}

void			power_right(float *info, char *s)
{
  /*if (info[0] > 400)
    {
      my_putstr("WHEELS_DIR:0\n");
      s = get_next_line(0);
      }*/
  if (info[0] <= 390)
    {
      my_putstr("WHEELS_DIR:-0.3\n");
      s = get_next_line(0);
    }
  else if (info[1] <= 430)
    {
      my_putstr("WHEELS_DIR:-0.2\n");
      s = get_next_line(0);
    }
}

void			my_best_driver(float *info, char *s)
{
  my_put_nbr(info[15]);
  if (/*info[0] > 400 && info[31] > 400*/ info[15] > 500)
    {
      my_putstr("WHEELS_DIR:0\n");
      s = get_next_line(0);
    }
  else
    {
      power_left(info, s);
      power_right(info, s);
    }
  manage_speed(info, s);
  /*my_putstr("CYCLYE_WAIT:1\n");
    s = get_next_line(0);*/
}
