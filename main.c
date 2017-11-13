/*
** main.c for main in /home/t3i/06nov/ngo_t
** 
** Made by NGO tri
** Login   <ngo_t@etna-alternance.net>
** 
** Started on  Mon Nov  6 10:57:39 2017 NGO tri
** Last update Fri Nov 10 16:19:58 2017 NGO tri
*/
#include "ftl.h"
#include <stdio.h>

void stat(t_ship *ship)
{
  t_freight *nav;

  my_putstr("vous avez récupéré ");
  my_put_nbr(ship->container->nb_elem);
  my_putstr(" conteneur(s).\n\n");
  nav = ship->container->first;
  while (nav != 0)
    {
  my_putstr(nav->item);
  my_putchar('\n');
  nav = nav->next;
    }
}

void aff_stat(t_ship *ship)
{
  my_putstr_color("clear","");
  my_putstr("votre position : ");
  my_put_nbr(ship->navigation_tools->sector);
  my_putstr("    vos points de vie : ");
  my_put_nbr(ship->hull);
  my_putstr("         vos armes : ");
  my_put_nbr(ship->weapon->damage);
  my_putstr("       votre energie : ");
  my_put_nbr(ship->ftl_drive->energy);
  my_putstr("       votre esquive : ");
  my_put_nbr(ship->navigation_tools->evade);
  my_putstr("%         [h]help   [q]quit\n");
}

void init(t_ship *ship)
{
  my_putstr_color("red", "protocol d'URGENCE\ninitialisation IA : Nebuchadnezzar\npassage en mode polite automatique.\n");
  my_putstr_color("blue", "destination : secteur 10\n");
  my_putstr("signe de vie à bord : 1\n");
  my_putstr("identification : capitaine\n");
  my_putstr("etat : inconscient\n");
  readline();
  create_ship();
  add_weapon_to_ship(ship);
  add_ftl_drive_to_ship(ship);
  add_navigation_tools_to_ship(ship);
  add_container(ship);
  add_ennemy(ship);  
}

char play(t_ship *ship)
{
  char l;
  
  l = lec();
  aff(ship);
  if (l == 'j')
    jump(ship);
  if (l == 'h')
    command();
  if (l == 'a')
    attack(ship);
  if (l == 'd')
    detect(ship);
  if (l == 'g')
    aff_bonus(ship);
  if (l == 's')
    stat(ship);
  if (l == 'c')
    system_control(ship);
  if (l == 'r')
    system_repair(ship);
  return (l);
}

int main()
{
  t_ship *ship;
  char l;

  srand (time (NULL));
  ship = create_ship();
  my_putstr_color("clear","");
  init(ship);
  while (l != 'q' && ship->navigation_tools->sector < 11 && 0 < ship->hull)
    l = play(ship);
  ship->ennemy->hp = 0;
  my_putstr_color("clear","");
  aff_stat(ship);
  if (ship->navigation_tools->sector == 11)
    my_putstr_color("green","\nsigne de vie à bord : 1\nidentification : capitaine\netat : operationnel\npassage en mode manuel");
  else
    {
      my_putstr_color("red","\nFIN de le simulation\nreprogrammation de l'IA\ndelete : Nebuchadnezzar");
      my_putstr_color("red", "\n\nprotocol d'URGENCE\ninitialisation IA : Nebuchadnezzas\n");
    }
  my_putchar('\n');
  lec();
  my_putstr_color("clear","");
  return (0);
}
