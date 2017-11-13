/*
** ran.c for ran in /home/t3i/06nov/ngo_t
** 
** Made by NGO tri
** Login   <ngo_t@etna-alternance.net>
** 
** Started on  Tue Nov  7 14:08:01 2017 NGO tri
** Last update Thu Nov  9 22:27:06 2017 NGO tri
*/
#include <stdlib.h>
#include <time.h>

int ran(int max)
{
  int ran;
  
  //  srand (time (NULL));
  ran = (rand()% max) + 1;
  return (ran);
}
