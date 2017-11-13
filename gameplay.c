/*
** gameplay.c for gameplay in /home/t3i/06nov/ngo_t
** 
** Made by NGO tri
** Login   <ngo_t@etna-alternance.net>
** 
** Started on  Tue Nov  7 08:14:09 2017 NGO tri
** Last update Fri Nov 10 18:32:46 2017 NGO tri
*/

#include "ftl.h"

void command()
{ 
  my_putstr("[a]");
  my_putstr_color("red","attack");
  my_putstr(" :         si un ennemi est présent dans la zone, des dommages lui sont infligés.\n[d]");
  my_putstr_color("blue","detect");
  my_putstr(":          permet d'utiliser les outils de navigations pour détecter des conteneurs spatiaux.\n[j]");
  my_putstr_color("blue","jump");
  my_putstr(" :           permet de sauter au secteur stéllaire suivant et diminue l'énergie de 1.\n[g]");
  my_putstr_color("yellow","getbonus");
  my_putstr(" :       permet de vider la liste du container et de récupérer tous les bonus qui s'y trouvent.\n[r]");
  my_putstr_color("blue","repair_system");
  my_putstr(" :  permet d'accéder aux fonctions permettant de réparer les divers parties de votre vaisseau.\n[c]");
  my_putstr_color("blue","control_system");
  my_putstr(" : permet de voir l'état des différentes parties du vaisseau.\n[s]");
  my_putstr_color("green","stat");
  my_putstr(" :           permet de voir les caractéristiques du vaisseau.\n");
} 

char lec()
{
  char *c;
  
  c = my_strdup(readline());
  if (my_strcmp(c, "q") == 0 || my_strcmp(c, "quit") == 0)
    return('q');
  if (my_strcmp(c, "h") == 0 || my_strcmp(c, "help") == 0)
    return('h');
  if (my_strcmp(c, "d") == 0 || my_strcmp(c, "detec") == 0)
    return('d');
  if (my_strcmp(c, "a") == 0 || my_strcmp(c, "attack") == 0)
    return('a');
  if (my_strcmp(c, "j") == 0 || my_strcmp(c, "jump") == 0)
    return('j');
  if (my_strcmp(c, "r") == 0 || my_strcmp(c, "repair_system") == 0)
    return('r');
  if (my_strcmp(c, "c") == 0 || my_strcmp(c, "control_system") == 0)
    return('c');
  if (my_strcmp(c, "s") == 0 || my_strcmp(c, "stat") == 0)
    return('s');
  if (my_strcmp(c, "g") == 0 || my_strcmp(c, "getbonus") == 0)
    return('g');
  else
    return('e');
}

void aff(t_ship *ship)
{
  aff_stat(ship);
  if (0 < ship->ennemy->hp)
    {
      my_putstr_color("red","ennemi : 1            points de vie ennemi : ");
      my_put_nbr(ship->ennemy->hp);
      my_putstr_color("red","      armes ennemi : ");
      my_put_nbr(ship->ennemy->dmg);
      my_putchar('\n');
    }
  else
    my_putstr_color("blue", "pas d'ennemi dans le secteur\n");
  my_putchar('\n');
}

void jum(t_ship *ship)
{
  ship->ftl_drive->energy--;
  aff(ship);  
  if (ship->ennemy->hp <= 0)
    {
      ship->navigation_tools->sector++;
      aff(ship);
      if (ran(10) <= 3)
	{
	  ship->ennemy->hp = ship->ennemy->inihp;
	  ship->ennemy->dmg = ship->ennemy->hp / 2;
	  ship->ennemy->inihp = ship->ennemy->inihp * 1.5;
	  aff(ship);
	}
      ship->cont = 'b';
    }
  else if (ship->ennemy->hp != ship->ennemy->inihp)
      put_dmg(ship);
  else
    my_putstr_color("red", "ennemi détecté dans le secteur\n");
}

void jump(t_ship *ship)
{
  if (my_strcmp(ship->ftl_drive->system_state, "online") == 0)  
    jum(ship);
  else
    my_putstr_color("red", "système de navigation hors service\n");
}
