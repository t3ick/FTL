/*
** system_repair.c for system_repair in /home/t3i/06nov/ngo_t
** 
** Made by NGO tri
** Login   <ngo_t@etna-alternance.net>
** 
** Started on  Tue Nov  7 01:26:50 2017 NGO tri
** Last update Fri Nov 10 16:42:06 2017 NGO tri
*/

#include "ftl.h"

void ftl_drive_system_repair(t_ship *ship)
{
  my_putstr_color("blue", "réparation du réacteur en cours...\n");
  free(ship->ftl_drive->system_state);
  ship->ftl_drive->system_state = malloc (6 * sizeof(char));
  ship->ftl_drive->system_state = my_strdup("online");
  if (my_strcmp(ship->ftl_drive->system_state, "online") == 0)
    my_putstr_color("green", "réparation terminé, système réacteur OK!\n");
  else
    my_putstr_color("red", "les réparation du réacteur ont échoué\n");
}

void navigation_tools_system_repair(t_ship *ship)
{
  my_putstr_color("blue", "réparation du systèmede navigation en cours...\n");
  free(ship->navigation_tools->system_state);
  ship->navigation_tools->system_state = malloc (6 * sizeof(char));
  ship->navigation_tools->system_state = my_strdup("online");
  if (my_strcmp(ship->navigation_tools->system_state, "online") == 0)
    my_putstr_color("green", "réparation terminé,système de navigation OK!\n");
  else
    my_putstr_color("red", "les réparation des outils de navigation ont échoué\n");
}

void weapon_system_repair(t_ship *ship)
{
  my_putstr_color("blue", "réparation du système d'armement en cours...\n");
  free(ship->weapon->system_state);
  ship->weapon->system_state = malloc (6 * sizeof(char));
  ship->weapon->system_state = my_strdup("online");
  if (my_strcmp(ship->weapon->system_state, "online") == 0)
    my_putstr_color("green", "réparation terminé, système d'armement OK!\n")\
      ;
  else
    my_putstr_color("red", "les réparation du système d'armement ont échoué\\
n");
}

static const t_repair_command tab[] =
  {
    {"ftl_drive", ftl_drive_system_repair},
    {"navigation_tools", navigation_tools_system_repair},
    {"weapon", weapon_system_repair},
    { NULL, NULL }
  };

void  system_repair(t_ship *ship)
{
  char *read;
  int i;
  int j;
  
  i = 0;
  j = 0;
  my_putstr("repaire_systeme~>\n\n");
  my_putstr("ftl_drive\n");
  my_putstr("navigation_tools\n");
  my_putstr("weapon\n");
  read = readline();
  while (tab[i].str != NULL)
    {
      if (my_strcmp(tab[i].str, read) == 0)
	{
	  tab[i].function(ship);
	  j++;
	}
      i++;
    }
  if (j == 0)
    my_putstr_color("red", "[SYSTEME FAILURE] : commande inconnue\n");
  put_dmg(ship);
}
