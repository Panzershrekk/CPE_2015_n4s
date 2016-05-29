/*
** best_driver.c for  in /home/fossae_t/rendu/CPE_2015_n4s
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Wed Apr 27 15:18:36 2016 Thomas Fossaert
** Last update Sun May 29 22:18:55 2016 Thomas Fossaert
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		"../inc/my.h"
#include		"get_next_line.h"

void			check_back(int *info, char *s)
{
  if (info[15] <= 150 && info[31] > info[0])
    {
      my_putstr("CAR_BACKWARDS:1\n");
      s = get_next_line(0);
      my_putstr("WHEELS_DIR:0.5\n");
      s = get_next_line(0);
    }
  else if (info[15] <= 150 && info[0] > info[31])
    {
      my_putstr("CAR_BACKWARDS:1\n");
      s = get_next_line(0);
      my_putstr("WHEELS_DIR:-0.5\n");
      s = get_next_line(0);
    }
  else if (info[15] <= 150 || info[16] <= 150
	   || info[17] <= 150 || info[14] <= 150)
    {
      my_putstr("CAR_BACKWARDS:1\n");
      s = get_next_line(0);
    }
}

void			manage_speed(int *info, char *s)
{
  if (info[15] <= 400)
    {
      my_putstr("CAR_FORWARD:0.15\n");
      s = get_next_line(0);
    }
  else if (info[15] <= 800)
    {
      my_putstr("CAR_FORWARD:0.30\n");
      s = get_next_line(0);
    }
  else if (info[15] <= 1000)
    {
      my_putstr("CAR_FORWARD:0.45\n");
      s = get_next_line(0);
    }
  else if (info[15] <= 1500)
    {
      my_putstr("CAR_FORWARD:0.65\n");
      s = get_next_line(0);
    }
  else if (info[15] > 1500)
    {
      my_putstr("CAR_FORWARD:0.9\n");
      s = get_next_line(0);
    }
}

void			power_left(int *info, char *s)
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
  else if (info[31] <= 430)
    {
      my_putstr("WHEELS_DIR:0.25\n");
      s = get_next_line(0);
    }
}

void			power_right(int *info, char *s)
{
  if (info[0] <= 280)
    {
      my_putstr("WHEELS_DIR:-0.35\n");
      s = get_next_line(0);
    }
  else if (info[1] <= 390)
    {
      my_putstr("WHEELS_DIR:-0.3\n");
      s = get_next_line(0);
    }
  else if (info[0] <= 430)
    {
      my_putstr("WHEELS_DIR:-0.25\n");
      s = get_next_line(0);
    }
}

void			my_best_driver(int *info, char *s)
{
  check_back(info, s);
  my_puterror(s);
  if (info[15] > 800)
    {
      my_putstr("WHEELS_DIR:0\n");
      s = get_next_line(0);
      my_puterror(s);
    }
  if (info[15] < 800 || (info[0] < 170 || info[31] < 170))
    {
      power_left(info, s);
      my_puterror(s);
      power_right(info, s);
      my_puterror(s);
    }
  check_extreme(info, s);
  my_puterror(s);
  manage_speed(info, s);
  my_puterror(s);
}
