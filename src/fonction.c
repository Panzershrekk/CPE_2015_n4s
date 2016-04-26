/*
** fonction.c for  in /home/fossae_t/rendu/CPE_2015_n4s/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue Apr 26 10:43:00 2016 Thomas Fossaert
** Last update Tue Apr 26 17:07:38 2016 Thomas Fossaert
*/

#include		<unistd.h>

void			my_putchar(char c)
{
  write(2, &c, 1);
}

int			my_strlen(char *str)
{
  int			i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void			my_putstr(char *str)
{
  write(1, str, my_strlen(str));
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

int			my_getnbr(char *str)
{
  int			var;
  int			inv;
  int			i;

  inv = 1;
  var = 0;
  i = 0;
  if (str == NULL)
    return (0);
  while ((*str < 47 || *str > 58) && *str != 0)
    {
      str = str + 1;
      i = i + 1;
    }
  if (i > 0 && *(str - 1) == 45)
    inv = -1;
  while (*str != 0 && *str >= '0' && *str <= '9')
    {
      var = var * 10;
      var = var + *str - 48;
      str = str + 1;
    }
  var = var * inv;
  return (var);
}
