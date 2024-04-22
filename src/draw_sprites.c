/*
** EPITECH PROJECT, 2024
** EPITECH PROJECT MY_RADAR
** File description:
** draw sprites
*/

#include "../include/my.h"

void draw_sprites_pl(sfRenderWindow *window, simulator_t *info, sfClock *clock)
{
    int seconds = sfTime_asSeconds(sfClock_getElapsedTime(clock));

    for (sp_plane_t *pl = info->plane; pl != NULL; pl = pl->prev) {
        if (seconds >= pl->delay && seconds < (pl->delay + pl->time)
        && pl->bool_aircraft == 1) {
            sfSprite_setPosition(pl->aircraft, pl->initial_position);
            sfRenderWindow_drawSprite(window, pl->aircraft, NULL);
        }
        if (seconds > (pl->delay + pl->time))
            delete_information(info, pl->id);
    }
    for (sp_plane_t *pl = info->plane; pl != NULL; pl = pl->prev) {
        if (seconds >= pl->delay && seconds < (pl->delay + pl->time)
        && pl->bool_rect == 1) {
            sfRectangleShape_setPosition(pl->rectangule, pl->initial_position);
            sfRenderWindow_drawRectangleShape(window, pl->rectangule, NULL);
        }
    }
}

void draw_sprites(sfRenderWindow *window, simulator_t *info, sfClock *clock)
{
    for (sp_tower_t *tw = info->tower; tw != NULL
    && tw->bool_circle == 1; tw = tw->prev)
        sfRenderWindow_drawCircleShape(window, tw->circle, NULL);
    for (sp_tower_t *tw = info->tower; tw != NULL
    && tw->bool_tower == 1; tw = tw->prev) {
        sfSprite_setPosition(tw->tower, tw->position);
        sfRenderWindow_drawSprite(window, tw->tower, NULL);
    }
    draw_sprites_pl(window, info, clock);
}
