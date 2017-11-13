/*                                                                       
** ftl.h for ftl in /home/t3i/06nov/ngo_t                                
**                                                                       
** Made by NGO tri                                                       
** Login   <ngo_t@etna-alternance.net>                                   
**                                                                       
** Started on  Mon Nov  6 09:21:19 2017 NGO tri                          
** Last update Fri Nov 10 16:17:09 2017 NGO tri                          
*/

#ifndef     _FTL_H_
# define    _FTL_H_

#include <stdlib.h>
#include <time.h>

typedef struct  s_ship
{
  int                           hull;
  struct s_weapon               *weapon;
  struct s_ftl_drive            *ftl_drive;
  struct s_navigation_tools     *navigation_tools;
  struct s_container            *container;
  struct s_ennemy               *ennemy;
  char                          eva;
  char                          cont;
}       t_ship;

typedef struct  s_weapon
{
  char  *system_state;
  int   damage;
}       t_weapon;

typedef struct  s_ftl_drive
{
  char  *system_state;
  int   energy;
}       t_ftl_drive;

typedef struct  s_navigation_tools
{
  char  *system_state;
  int   sector;
  int   evade;
}       t_navigation_tools;

typedef struct  s_freight
{
  char                  *item;
  struct  s_freight     *next;
  struct  s_freight     *prev;
}       t_freight;

typedef struct  s_container
{
  int                   nb_elem;
  struct s_freight      *first;
  struct s_freight      *last;
}       t_container;

typedef struct s_repair_command
{
  char  *str;
  void  (*function)(t_ship *ship);
}       t_repair_command;

typedef struct s_ennemy
{
  int  hp;
  int  inihp;
  int  dmg;
}       t_ennemy;

int     my_strlen(char *str);
char    *my_strdup(char *str);
void    my_putstr_color(const char *color, const char *str);
void    my_putchar(char c);
int     my_strcmp(const char *s1, const char *s2);
char    *readline(void);
void    my_putstr(const char *str);
void    my_put_nbr(int n);
void    ftl_drive_system_repair(t_ship *ship);
void    navigation_tools_system_repair(t_ship *ship);
void    weapon_system_repair(t_ship *ship);
void    attack(t_ship *ship);
t_ship  *create_ship();
int     add_weapon_to_ship(t_ship *ship);
int     add_ftl_drive_to_ship(t_ship *ship);
int     add_navigation_tools_to_ship(t_ship *ship);
int     add_container(t_ship *ship);
void    system_control(t_ship *ship);
void    command();
char    lec();
void    aff(t_ship *ship);
int     add_ennemy(t_ship *ship);
int     ran(int max);
void    jump(t_ship *ship);
void    dmg(t_ship *ship);
void    aff_dmg(t_ship *ship);
void    add_freight_to_container(t_ship *ship, t_freight *freight);
void    aff_bonus(t_ship *ship);
void    detect(t_ship *ship);
void    system_repair(t_ship *ship);
void    put_dmg(t_ship *ship);
void    aff_stat(t_ship *ship);

#endif      /* !_FTL_H_ */
