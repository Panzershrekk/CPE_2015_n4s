/*
** str_to_wordatab.c for str in /home/fossae_t/rendu/CPE_2015_n4s
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue Apr 26 15:50:15 2016 Thomas Fossaert
** Last update Tue Apr 26 16:30:06 2016 Thomas Fossaert
*/

#include	<stdlib.h>
#include	"../inc/my.h"

int		count_words(char *str)
{
  int		i;
  int		nb_words;

  nb_words = 1;
  i = 0;
  while (str[i] != '\0')
    {
      if (i == 0)
	{
	  while (str[i] == ':' || str[i] == '\0')
	    i++;
	}
      if (((str[i] == ':') || str[i] == '\0')
	  && (str[i + 1] != ':' && str[i + 1] != '\0'))
	nb_words++;
      if (str[i] != '\0')
	i = i + 1;
    }
  return (nb_words);
}

void		dup_n_car(char *new_str, char *str, int begin, int end)
{
  int		i;

  i = 0;
  while (begin <= end)
    {
      new_str[i] = str[begin];
      begin = begin + 1;
      i = i + 1;
    }
  new_str[i] = '\0';
}

void		recup_words(char **tab, char *str, int nb_words)
{
  int		i;
  int		begin;
  int		word_cur;

  word_cur = 0;
  i = 0;
  begin = 0;
  while (word_cur < nb_words)
    {
      while (str[i] && (str[i] == ':' || str[i] == '\0'))
	i++;
      begin = i;
      while (str[i] && (str[i] != ':' && str[i] != '\0'))
	i++;
      tab[word_cur] = malloc(sizeof(char *) * ((i - 1) - begin + 2));
      dup_n_car(tab[word_cur], str, begin, i - 1);
      i = i + 1;
      word_cur = word_cur + 1;
    }
}

char		**my_str_to_wordtab(char *str)
{
  int		nb_words;
  char		**tab;

  nb_words = count_words(str);
  tab = malloc(sizeof(char**) * (nb_words + 1));
  recup_words(tab, str, nb_words);
  tab[nb_words] = NULL;
  return (tab);
}
