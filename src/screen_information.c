/*
** EPITECH PROJECT, 2024
** EPITECH PROJECT MY_RADAR
** File description:
** add information about the differents elements
*/

#include "../include/my.h"
sfRectangleShape *rectangule_create(sfVector2f position)
{
    sfVector2f size = {20, 20};
    sfRectangleShape *rectangule = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rectangule, sfTransparent);
    sfRectangleShape_setOutlineColor(rectangule, sfRed);
    sfRectangleShape_setOutlineThickness(rectangule, 1.00);
    sfRectangleShape_setSize(rectangule, size);
    sfRectangleShape_setPosition(rectangule, position);
    return (rectangule);
}

int calculate_distance(sp_plane_t *pl)
{
    int distance = sqrt((pow((pl->final_dest.x - pl->initial_position.x), 2) +
    (pow((pl->final_dest.y - pl->initial_position.y), 2))));

    return (distance);
}

sp_plane_t *add_sp_aircraft(aircrafts_t *aircraft, int id)
{
    sp_plane_t *sp_aircraft = malloc(sizeof(sp_plane_t));

    sp_aircraft->id = id;
    sp_aircraft->aircraft = create_sprite("images/plane.png");
    sp_aircraft->bool_aircraft = 1;
    sp_aircraft->bool_rect = 1;
    sp_aircraft->initial_position.x = aircraft->departure_x - 10;
    sp_aircraft->initial_position.y = aircraft->departure_y - 10;
    sp_aircraft->final_dest.x = aircraft->arrival_x;
    sp_aircraft->final_dest.y = aircraft->arrival_y;
    sp_aircraft->rectangule = rectangule_create(sp_aircraft->initial_position);
    sp_aircraft->time = calculate_distance(sp_aircraft) / aircraft->speed;
    sp_aircraft->speed.x = (sp_aircraft->final_dest.x - \
    sp_aircraft->initial_position.x)
    / sp_aircraft->time;
    sp_aircraft->speed.y = (sp_aircraft->final_dest.y - \
    sp_aircraft->initial_position.y) / sp_aircraft->time;
    sp_aircraft->delay = aircraft->delay;
    sp_aircraft->prev = NULL;
    return (sp_aircraft);
}

sp_tower_t *add_sp_tower(tower_t *tower)
{
    sp_tower_t *sp_tower = malloc(sizeof(sp_tower_t));

    sp_tower->tower = create_sprite("images/tower.png");
    sp_tower->bool_circle = 1;
    sp_tower->bool_tower = 1;
    sp_tower->position.x = tower->x - 12;
    sp_tower->position.y = tower->y - 12;
    sp_tower->circle = create_circle(sp_tower->position, tower->radius);
    sp_tower->prev = NULL;
    return (sp_tower);
}

void add_sprite_info(entities_t *simulation, simulator_t *info)
{
    sfVideoMode video = {1920, 1080, 32};
    sp_plane_t *sp_aircraft;
    sp_tower_t *sp_tower;
    int id = 0;

    info->background = create_sprite("images/map.jpg");
    info->window =
    sfRenderWindow_create(video, "my_radar", sfDefaultStyle, NULL);
    for (tower_t *tw = simulation->tower; tw != NULL; tw = tw->prev) {
        sp_tower = info->tower;
        info->tower = add_sp_tower(tw);
        info->tower->prev = sp_tower;
    }
    for (aircrafts_t *pl = simulation->aircrafts; pl != NULL; pl = pl->prev) {
        sp_aircraft = info->plane;
        info->plane = add_sp_aircraft(pl, id);
        info->plane->prev = sp_aircraft;
        id++;
    }
}
