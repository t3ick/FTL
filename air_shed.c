/*                                                                       
** air_shed.c for air_shed in /home/t3i/06nov/ngo_t                      
**                                                                       
** Made y NGO tri                                                        
** Loginu   <ngo_t@etna-alternance.net>                                  
**                                                                       
** Started on  Mon Nov  6 09:28:18 2017 NGO tri                          
** Last update Fri Nov 10 10:42:47 2017 NGO tri                          
*/

#include "ftl.h"

t_ship *create_ship()
{
  t_ship *ship;

  my_putstr_color("blue", "construction du vaisseau en cours...\n");
  ship = malloc (sizeof(t_ship));
  ship->weapon = NULL;
  ship->ftl_drive = NULL;
  ship->navigation_tools = NULL;
  ship->container = NULL;
  ship->eva = 'e';
  ship->cont = 'b';
  if (ship == NULL)
      {
        my_putstr_color("red", "le vaisseau n'a pas pu être construit par manque de matériaux\n");
      return (0);
      }
    ship->hull = 50;
    my_putstr_color("green", "amélioration du vaisseau terminé!\n");
    return (ship);
}

int add_ftl_drive_to_ship(t_ship *ship)
{
  t_ftl_drive *ftl_drive;

  my_putstr_color("blue", "ajout du réacteur en cours...\n");
  ftl_drive = malloc (sizeof(t_ftl_drive));
  if (ftl_drive == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explosé quand vous avez posé le réacteur\n");
      return (0);
    }
  ftl_drive->energy = 10;
  ftl_drive->system_state = my_strdup("online");
  ship->ftl_drive = ftl_drive;
  my_putstr_color("green", "le réacteur a été ajouté avec succes!\n");
  return (1);
}

int add_navigation_tools_to_ship(t_ship *ship)
{
  t_navigation_tools *navigation_tools;

  my_putstr_color("blue", "ajout des outils de navigation en cours...\n"\
);
  navigation_tools = malloc (sizeof(t_navigation_tools));
  if (navigation_tools == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explosé quand vous avez posé les outils de navigations\n");
      return (0);
    }
  navigation_tools->sector = 0;
  navigation_tools->evade = 25;
  navigation_tools->system_state = my_strdup("online");
  ship->navigation_tools = navigation_tools;
  my_putstr_color("green", "les outils de navigations ont été ajouté avec succes!\n");
  return (1);
}

int add_ennemy(t_ship *ship)
{
  t_ennemy *ennemy;

  ennemy = malloc (sizeof(t_ennemy));
  if (ennemy == NULL)
      return (0);
  ennemy->dmg = 10;
  ennemy->inihp = 20;
  ennemy->hp = 0;
  ship->ennemy = ennemy;
  return (1);
}
