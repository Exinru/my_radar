/*
** EPITECH PROJECT, 2023
** EPITECH PROJECT SETTING UP
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <stdbool.h>
    #include <string.h>
    #include <math.h>

typedef struct aircrafts {
    int departure_x;
    int departure_y;
    int arrival_x;
    int arrival_y;
    int speed;
    int delay;
    struct aircrafts *prev;
} aircrafts_t;

typedef struct tower {
    int x;
    int y;
    int radius;
    struct tower *prev;
} tower_t;

typedef struct entities {
    tower_t *tower;
    aircrafts_t *aircrafts;
} entities_t;

typedef struct sp_tower {
    sfSprite *tower;
    sfCircleShape *circle;
    sfVector2f position;
    struct sp_tower *prev;
    int bool_tower;
    int bool_circle;
}sp_tower_t;

typedef struct sp_aircrafts {
    int id;
    sfSprite *aircraft;
    sfVector2f initial_position;
    sfVector2f final_dest;
    sfVector2f rect_pos;
    sfRectangleShape *rectangule;
    int bool_aircraft;
    int bool_rect;
    sfVector2f speed;
    int time;
    int delay;
    struct sp_aircrafts *prev;
} sp_plane_t;

typedef struct screen_simulation {
    sfRenderWindow *window;
    sfSprite *background;
    sp_plane_t *plane;
    sp_tower_t *tower;
} simulator_t;

void my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_nlen(int x);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int get_file_height(char *filepath);
void print_usage(void);
void add_information_file(char *filepath, entities_t *simulation);
int check_file(char *filepath);
char **get_array(char *filepath);
char *filecont(char *filepath);
sfCircleShape *create_circle(sfVector2f position, float radius);
sfSprite *create_sprite(char *filepath);
int delete_information(simulator_t *info, int id);
void add_sprite_info(entities_t *simulation, simulator_t *info);
void change_visibility_sprites(simulator_t *info, sfEvent event);
void change_visibility_hitbox(simulator_t *info, sfEvent event);
int my_screen(simulator_t *info);
void draw_sprites(sfRenderWindow *window, simulator_t *info, sfClock *clock);
#endif
