/*
** fonction.c for  in /home/fossae_t/rendu/CPE_2015_n4s/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue Apr 26 10:43:00 2016 Thomas Fossaert
** Last update Tue Apr 26 11:54:02 2016 Thomas Fossaert
*/

#include		<unistd.h>

void			my_putchar(char c)
{
  write(1, &c, 1);
}

void			my_putstr(char *str)
{
  int			i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

void			my_put_nbr(int nb)
{
  int			mod;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  mod = (nb % 10);
	  nb = (nb - mod) / 10;
	  my_put_nbr(nb);
	  my_putchar(48 + mod);
	}
      else
	my_putchar(48 + nb % 10);
    }
}
