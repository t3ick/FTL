/*
** bonus.c for bonus in /home/t3i/06nov/ngo_t
** 
** Made by NGO tri
** Login   <ngo_t@etna-alternance.net>
** 
** Started on  Thu Nov  9 15:37:47 2017 NGO tri
** Last update Fri Nov 10 19:02:17 2017 NGO tri
*/
#include "ftl.h"

void put_bonus(t_ship *ship)
{
  int i;
  int r;
  t_freight *freight;
  
  i = 0;
    while (i < 10)
      {
	freight = malloc(sizeof(t_freight));
	r = ran(10);
	if (r == 1)
	  freight->item = my_strdup("attackbonus");
	else if (r == 2)
	  freight->item = my_strdup("evadebonus");
	else if (r == 3)
	  freight->item = my_strdup("energy");
	else
	  freight->item = my_strdup("scrap");
	my_putstr(freight->item);
	my_putchar('\n');
	add_freight_to_container(ship, freight);
	ship->cont = 'n';
	i++;
      }
}

void detect(t_ship *ship)
{
  if (ship->cont == 'n')
      my_putstr_color("blue", "plus de conteneur dans le secteur.\n");
  else if (my_strcmp(ship->navigation_tools->system_state, "online") != 0)
      my_putstr_color("red", "systeme de navigation endommagé.\n");
  else
    put_bonus(ship);
  put_dmg(ship);
}
