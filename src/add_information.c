/*
** EPITECH PROJECT, 2024
** EPITECH PROJECT MY_RADAR
** File description:
** get the information of the file
*/

#include "../include/my.h"

int getnbr(char *str)
{
    int num = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            num = (num * 10) + (str[i] - 48);
        if (str[i] == ' ' || str[i] == '\t')
            break;
    }
    return (num);
}

aircrafts_t *add_aircraft(char *str)
{
    aircrafts_t *aircraft = malloc(sizeof(aircrafts_t));
    int i = 2;

    aircraft->departure_x = getnbr(str + i);
    i = i + my_nlen(aircraft->departure_x) + 1;
    aircraft->departure_y = getnbr(str + i);
    i = i + my_nlen(aircraft->departure_y) + 1;
    aircraft->arrival_x = getnbr(str + i);
    i = i + my_nlen(aircraft->arrival_x) + 1;
    aircraft->arrival_y = getnbr(str + i);
    i = i + my_nlen(aircraft->arrival_y) + 1;
    aircraft->speed = getnbr(str + i);
    i = i + my_nlen(aircraft->speed) + 1;
    aircraft->delay = getnbr(str + i);
    aircraft->prev = NULL;
    return (aircraft);
}

tower_t *add_tower(char *str)
{
    tower_t *tower = malloc(sizeof(tower_t));
    int i = 2;

    tower->x = getnbr(str + i);
    i = i + my_nlen(tower->x) + 1;
    tower->y = getnbr(str + i);
    i = i + my_nlen(tower->y) + 1;
    tower->radius = getnbr(str + i);
    tower->prev = NULL;
    return (tower);
}

void add_information_file(char *filepath, entities_t *simulation)
{
    char **map = get_array(filepath);
    aircrafts_t *aircrafts;
    tower_t *towers;

    for (int x = 0; x < get_file_height(filepath) + 1; x++) {
        if (map[x][0] == 'A') {
            aircrafts = simulation->aircrafts;
            simulation->aircrafts = add_aircraft(map[x]);
            simulation->aircrafts->prev = aircrafts;
        }
        if (map[x][0] == 'T') {
            towers = simulation->tower;
            simulation->tower = add_tower(map[x]);
            simulation->tower->prev = towers;
        }
    }
}
