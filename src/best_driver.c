/*
** best_driver.c for  in /home/fossae_t/rendu/CPE_2015_n4s
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Wed Apr 27 15:18:36 2016 Thomas Fossaert
** Last update Wed May 11 17:07:23 2016 Thomas Fossaert
*/

#include		"../inc/my.h"
#include		"get_next_line.h"

void			check_back(float *info, char *s)
{
  if (info[15] <= 150 && info[31] > info[0])
    {
      my_putstr("CAR_BACKWARDS:1\n");
      s = get_next_line(0);
      my_putstr("WHEELS_DIR:0.3\n");
      s = get_next_line(0);
    }
  else if (info[15] <= 150 && info[0] > info[31])
    {
      my_putstr("CAR_BACKWARDS:1\n");
      s = get_next_line(0);
      my_putstr("WHEELS_DIR:-0.3\n");
      s = get_next_line(0);
    }
}

void			manage_speed(float *info, char *s)
{
  if (info[15] <= /*1000*/800)
    {
      my_putstr("CAR_FORWARD:0.3\n");
      s = get_next_line(0);
    }
  else if (info[15] <= /*1500*/1000)
    {
      my_putstr("CAR_FORWARD:0.6\n");
      s = get_next_line(0);
    }
  else if (info[15] <= /*2500*/1500)
    {
      my_putstr("CAR_FORWARD:0.8\n");
      s = get_next_line(0);
    }
  else if (info[15] > /*2500*/1500)
  {
    my_putstr("CAR_FORWARD:1\n");
    s = get_next_line(0);
  }
}

void			power_left(float *info, char *s)
{
  if (info[31] <= 280)
    {
      my_putstr("WHEELS_DIR:0.35\n");
      s = get_next_line(0);
    }
  else if (info[31] <= 390)
    {
      my_putstr("WHEELS_DIR:0.3\n");
      s = get_next_line(0);
    }
  else if (info[30] <= 430)
    {
      my_putstr("WHEELS_DIR:0.25\n");
      s = get_next_line(0);
    }
}

void			power_right(float *info, char *s)
{
  if (info[0] <= 280)
    {
      my_putstr("WHEELS_DIR:-0.35\n");
      s = get_next_line(0);
    }
  else if (info[0] <= 390)
    {
      my_putstr("WHEELS_DIR:-0.3\n");
      s = get_next_line(0);
    }
  else if (info[1] <= 430)
    {
      my_putstr("WHEELS_DIR:-0.25\n");
      s = get_next_line(0);
    }
}

void			my_best_driver(float *info, char *s)
{
  check_back(info, s);
  if (info[15] > 800)
    {
      my_putstr("WHEELS_DIR:0\n");
      s = get_next_line(0);
    }
  if (info[15] < 800 || (info[0] < 130 || info[31] < 130))
    {
      power_left(info, s);
      power_right(info, s);
      /*check_back(info, s);*/
      /*manage_speed(info, s);*/
    }
  manage_speed(info, s);

}
