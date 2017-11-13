/*
** container.c for container in /home/t3i/06nov/ngo_t
** 
** Made by NGO tri
** Login   <ngo_t@etna-alternance.net>
** 
** Started on  Mon Nov  6 13:55:37 2017 NGO tri
** Last update Fri Nov 10 18:36:38 2017 NGO tri
*/

#include "ftl.h"

int add_container(t_ship *ship)
{
  t_container *container;

  my_putstr_color("blue", "ajout du container en cours...\n");
  container = malloc (sizeof(t_container));
  if (container == NULL)
    {
      my_putstr_color("red", "votre vaisseau à explosé lorsque vous avez posé le container\n");
      return(0);
    }
  container->first = NULL;
  container->last = NULL;
  container->nb_elem = 0;
  ship->container = container;
  my_putstr_color("green", "le container à été ajouté avec succes!\n");
  return (1);
}

void add_freight_to_container(t_ship *ship, t_freight *freight)
{
  if (ship->container->first == NULL)
    {
      freight->next = NULL;
      freight->prev = NULL;
      ship->container->first = freight;
      ship->container->last = freight;
    }
  else
    {
      freight->next = NULL;
      freight->prev = ship->container->last;
      ship->container->last->next = freight;
      ship->container->last = freight;
    }
  ship->container->nb_elem++;
}

void del_fright_from_container(t_ship *ship, t_freight *freight)
{
  if (freight->next == NULL && freight->prev == NULL)
    {
      ship->container->first = NULL;
      ship->container->last = NULL;
    }
  else if (freight->next == NULL)
    {
      ship->container->last = freight->prev;
      ship->container->last->next = NULL;
    }
  else if (freight->prev == NULL)
    {
      ship->container->first = freight->next;
      ship->container->first->prev = NULL;
    }
  else
    {
      freight->prev->next = freight->next;
      freight->next->prev = freight->prev;
    }
  free(freight->item);
  free(freight);
  ship->container->nb_elem--;
}

void get_bonus(t_ship *ship)
{
  t_freight *nav;
  
  nav = ship->container->first;
  while (nav != NULL)
    {
      if (my_strcmp(nav->item, "attackbonus") == 0)
	ship->weapon->damage += 5;
      else if (my_strcmp(nav->item, "evadebonus") == 0)
	ship->navigation_tools->evade += 3;
      else if (my_strcmp(nav->item, "energy") == 0)
	ship->ftl_drive->energy += 1;
      nav = nav->next;
    }
  nav = ship->container->first;
  while (ship->container->nb_elem != 0)
      del_fright_from_container(ship, ship->container->first);
  aff(ship);
}

void aff_bonus(t_ship *ship)
{
  int a;
  int ev;
  int en;

  a = ship->weapon->damage;
  ev = ship->navigation_tools->evade;
  en = ship->ftl_drive->energy;
  get_bonus(ship);
  put_dmg(ship);
  if (a != ship->weapon->damage || ev != ship->navigation_tools->evade || en != ship->ftl_drive->energy)
    {
      my_putstr("vous avez gagné ");
      my_put_nbr(ship->weapon->damage - a);
      my_putstr(" attaque\n");
      my_putstr("vous avez gagné ");
      my_put_nbr(ship->navigation_tools->evade - ev);
      my_putstr(" % d'ésquive\n");
      my_putstr("vous avez gagné ");
      my_put_nbr(ship->ftl_drive->energy - en);
      my_putstr(" energie\n");
    }
}
