/*
** cbt.c for cbt in /home/t3i/06nov/ngo_t
** 
** Made by NGO tri
** Login   <ngo_t@etna-alternance.net>
** 
** Started on  Thu Nov  9 09:16:07 2017 NGO tri
** Last update Fri Nov 10 18:55:02 2017 NGO tri
*/

#include "ftl.h"

void down(t_ship *ship)
{
  int r;

  if (ran(5) == 1)
    {
      r = ran(3);
      if (r == 1)
	ship->ftl_drive->system_state = my_strdup("offline");
      if (r == 2)
	ship->navigation_tools->system_state = my_strdup("offline");
      if (r == 3)
	ship->weapon->system_state = my_strdup("offline");
      my_putstr_color("red", "système endommagé");
    }
}

void att(t_ship *ship)
{
  aff(ship);
  if (ship->ennemy->hp <= 0)
    if (ran(2) == 1)
      {
	ship->ftl_drive->energy--;
	aff(ship);
	my_putstr_color("red", "vous perdez 1 point d'energie suite au combat\n");
      }
  if (ship->ennemy->hp <= 0)
    my_putstr_color("green", "ennemi détruit\n");
  aff_dmg(ship);
  my_putstr_color("red", "ennemi touché\n");
  my_putstr("votre ennemi perd ");
  my_put_nbr(ship->weapon->damage);
  my_putstr(" points de vie\n");
}

void attack(t_ship *ship)
{
  if (0 < ship->ennemy->hp)
    {
      dmg(ship);
      if (my_strcmp(ship->weapon->system_state, "online") == 0)
	{
	  ship->ennemy->hp -= ship->weapon->damage;
	  att(ship);
	  down(ship);
	}
      else
	my_putstr("système d'armement endommagé.");
    }
  else
    {
      my_putstr_color("blue", "pas d'ennemi dans le secteur\n");
    }
}


void dmg(t_ship *ship)
{
  if (ship->navigation_tools->evade <= ran(100))
    {
      ship->eva = 't';
      ship->hull -= ship->ennemy->dmg;
    }
  else
    ship->eva ='e';
}

void aff_dmg(t_ship *ship)
{
  if (ship->eva == 't')
    {
      my_putstr_color("red", "vous êtes touché\n");
      my_putstr("vous perdez ");
      my_put_nbr(ship->ennemy->dmg);
      my_putstr(" points de vie\n");
    }
  else
    my_putstr_color("green", "vous avez évité l'attaque ennemi\n");
}

void put_dmg(t_ship *ship)
{
  if (0 < ship->ennemy->hp)
    {
  dmg(ship);
  aff(ship);
  aff_dmg(ship);
    }
}
