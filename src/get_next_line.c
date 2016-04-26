/*
** get_next_line.c for getnext in /home/fossae_t/rendu/CPE_2015_Allum1
**
** Made by Fossaert Thomas
** Login   <fossae_t@epitech.net>
**
** Started on  Mon Feb  8 11:22:16 2016 Fossaert Thomas
** Last update Mon Feb  8 11:22:18 2016 Fossaert Thomas
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

char		*my_realloc(char *old, int size)
{
  int		i;
  char		*new;
  int		len;

  i = 0;
  len = 0;
  while (old[len] != '\0')
    len++;
  new = malloc(sizeof(char) * (len + size));
  if (new  == NULL)
    return (NULL);
  while (old[i])
    {
      new[i] = old[i];
      i++;
    }
  free(old);
  return (new);
}

char		return_char(const int fd)
{
  static char	buffer[READ_SIZE];
  static char	*sto_buff;
  static int	ret;
  char		c;

  if (ret == 0)
    {
      ret = read(fd, buffer, READ_SIZE);
      sto_buff = buffer;
      if (ret == 0)
	return ('\0');
    }
  c = *sto_buff;
  sto_buff++;
  ret = ret - 1;
  return (c);
}

char		*check_error(int fd)
{
  if (fd < 0)
    return (NULL);
  if (READ_SIZE <= 0)
    return (NULL);
}

char		*get_next_line(const int fd)
{
  char		c;
  char		*line;
  int		i;

  check_error(fd);
  i = 0;
  line = malloc(READ_SIZE + 1);
  if (line == NULL)
    return (NULL);
  c = return_char(fd);
  if (c == '\0')
    return (NULL);
  while (c != '\n' && c != '\0')
    {
      line[i] = c;
      c = return_char(fd);
      i++;
      if (i % (READ_SIZE + 1) == 0)
	line = my_realloc(line, i + READ_SIZE + 1);
    }
  line[i] = '\0';
  if (c == '\0' && line[0] == '\n')
    return (NULL);
  return (line);
}
