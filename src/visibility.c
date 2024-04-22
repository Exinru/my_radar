/*
** EPITECH PROJECT, 2024
** EPITECH PROJECT MY_RADAR
** File description:
** change visibility
*/

#include "../include/my.h"

void change_visibility_sprites(simulator_t *info, sfEvent event)
{
    for (sp_plane_t *pl = info->plane; pl != NULL; pl = pl->prev) {
        if (pl->bool_aircraft == 2) {
            pl->bool_aircraft = 1;
            continue;
        }
        if (pl->bool_aircraft == 1) {
            pl->bool_aircraft = 2;
        }
    }
    for (sp_tower_t *tw = info->tower; tw != NULL; tw = tw->prev) {
        if (tw->bool_tower == 2) {
            tw->bool_tower = 1;
            continue;
        }
        if (tw->bool_tower == 1)
            tw->bool_tower = 2;
    }
}

void change_visibility_hitbox(simulator_t *info, sfEvent event)
{
    for (sp_plane_t *pl = info->plane; pl != NULL; pl = pl->prev) {
        if (pl->bool_rect == 2) {
            pl->bool_rect = 1;
            continue;
        }
        if (pl->bool_rect == 1) {
            pl->bool_rect = 2;
        }
    }
    for (sp_tower_t *tower = info->tower; tower != NULL; tower = tower->prev) {
        if (tower->bool_circle == 2) {
            tower->bool_circle = 1;
            continue;
        }
        if (tower->bool_circle == 1)
            tower->bool_circle = 2;
    }
}
