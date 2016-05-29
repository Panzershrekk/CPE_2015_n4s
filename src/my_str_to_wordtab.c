/*
** my_str_to_wordtab.c for minishell2 in /home/thomas/PSU_2015_minishell2/src
**
** Made by Thomas HUGUET
** Login   <thomas@epitech.net>
**
** Started on  Thu Apr 21 10:03:09 2016 Thomas HUGUET
** Last update Sun May 29 22:40:39 2016 Thomas Fossaert
*/

#include	<stdlib.h>
#include	<stdio.h>

int		is_separator(char c, char *separator)
{
  int		i;

  i = 0;
  while (separator[i] && separator[i] != c)
    i++;
  if (separator[i] == c)
    return (1);
  return (0);
}

int		count_words(char *str, char *separator)
{
  int		i;
  int		nb_words;
  int		word;

  word = 0;
  nb_words = 0;
  i = 0;
  while (str[i])
    {
      if (word == 0 && is_separator(str[i], separator) == 0)
	{
	  nb_words++;
	  word = 1;
	}
      if (word == 1 && is_separator(str[i], separator) == 1)
	word = 0;
      i++;
    }
  return (nb_words);
}

char		*fill_tab_line(char *tab, char *str, int tmp, char *separator)
{
  int		i;

  i = 0;
  while (str[tmp] && is_separator(str[tmp], separator) == 0)
    {
      tab[i] = str[tmp];
      tmp++;
      i++;
    }
  tab[i] = '\0';
  return (tab);
}

char		**recup_words(char **tab, char *str, char *separator)
{
  int		i;
  int		tmp;
  int		word;
  int		j;

  word = 0;
  i = 0;
  while (str[i])
    {
      while (str[i] && is_separator(str[i], separator) == 1)
	i++;
      j = 0;
      tmp = i;
      while (str[i] && is_separator(str[i], separator) == 0)
	{
	  i++;
	  j++;
	}
      tab[word] = malloc(sizeof(char *) * (j + 1));
      tab[word] = fill_tab_line(tab[word], str, tmp, separator);
      word++;
    }
  return (tab);
}

char		**my_str_to_wordtab(char *str, char *separator)
{
  int		nb_words;
  char		**tab;

  nb_words = count_words(str, separator);
  if (nb_words == 0)
    return (NULL);
  tab = malloc(sizeof(char **) * (nb_words + 1));
  tab = recup_words(tab, str, separator);
  tab[nb_words] = NULL;
  return (tab);
}
