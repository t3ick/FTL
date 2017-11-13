/*
** readline.c for readline in /home/t3i/06nov/ngo_t
** 
** Made by NGO tri
** Login   <ngo_t@etna-alternance.net>
** 
** Started on  Tue Nov  7 07:09:36 2017 NGO tri
** Last update Wed Nov  8 15:11:36 2017 NGO tri
*/

#include<stdlib.h>
#include<unistd.h>

char	*readline(void)
{
  ssize_t	ret;
  char		*buff;

  if ((buff = malloc((50 + 1) * sizeof(char))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  free(buff);
  return (NULL);
}
