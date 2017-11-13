/*
** system_control.c for system_control.c in /home/t3i/06nov/ngo_t
** 
** Made by NGO tri
** Login   <ngo_t@etna-alternance.net>
** 
** Started on  Mon Nov  6 20:11:39 2017 NGO tri
** Last update Fri Nov 10 11:09:29 2017 NGO tri
*/

#include "ftl.h"

void ftl_drive_system_check(t_ship *ship)
{
  my_putstr_color("blue", "vérification du réacteur en cours...\n");
  if (ship->ftl_drive == NULL)
    my_putstr_color("red", "réacteur introuvable\n");
  else if (my_strcmp(ship->ftl_drive->system_state, "online") == 0)
    my_putstr_color("green", "réacteur OK!\n");
  else
    my_putstr_color("red", "réacteur hors service\n");
}

void navigation_tools_system_check(t_ship *ship)
{
  my_putstr_color("blue", "vérification du système de navigation en cours...\n");
  if (ship->navigation_tools == NULL)
    my_putstr_color("red", "système de navigation introuvable\n");
  else if (my_strcmp(ship->navigation_tools->system_state, "online") == 0)
    my_putstr_color("green", "système de navigation OK!\n");
  else
    my_putstr_color("red", "système de navigation hors service\n");
}

void weapon_system_check(t_ship *ship)
{
  my_putstr_color("blue", "vérification du système d'armenent en cours...\n");
  if (ship->weapon == NULL)
    my_putstr_color("red", "système d'armement introuvable\n");
  else if (my_strcmp(ship->weapon->system_state, "online") == 0)
    my_putstr_color("green", "système d'armement OK!\n");
  else
    my_putstr_color("red", "système d'armement hors service\n");
}

void system_control(t_ship *ship)
{
  if (ship == NULL)
    my_putstr_color("red", "mais ou est le vaisseau ?\n");
  else
    {
      ftl_drive_system_check(ship);
      navigation_tools_system_check(ship);
      weapon_system_check(ship);
    }
  put_dmg(ship);
}
