/*
** EPITECH PROJECT, 2023
** EPITECH PROJECT MY_RADAR
** File description:
** simulation of planes
*/

#include "../include/my.h"
static void cross_map(simulator_t *info)
{
    for (sp_plane_t *pl = info->plane; pl != NULL; pl = pl->prev) {
        if ((pl->initial_position.x - 20) >= 1920) {
            pl->initial_position.x = 0;
            pl->final_dest.x = pl->final_dest.x - 1920;
            //sfRectangleShape_setOutlineColor(pl->rectangule, sfGreen);
        }
        if ((pl->initial_position.y - 20) >= 1080) {
            pl->initial_position.y = 0;
            pl->final_dest.y = pl->final_dest.y - 1080;
            //sfRectangleShape_setOutlineColor(pl->rectangule, sfGreen);
        }
    }
}

int check_intersect(sp_plane_t *plane, sp_plane_t *pl, simulator_t *info)
{
    sfIntRect rect1 = {plane->initial_position.x, plane->initial_position.y,
    21, 21};
    sfIntRect quere = {pl->initial_position.x, pl->initial_position.y, 20, 20};

    if (sfIntRect_intersects(&rect1, &quere, NULL) == sfTrue) {
        delete_information(info, plane->id);
        delete_information(info, pl->id);
        return (1);
    }
    return (0);
}

static void intersecting_plane(simulator_t *info)
{
    sp_plane_t *plane;

    for (sp_plane_t *pl = info->plane; pl != NULL; pl = pl->prev) {
        plane = pl->prev;
        while (plane != NULL && check_intersect(plane, pl, info) != 1)
            plane = plane->prev;
    }
}

int delete_information(simulator_t *info, int id)
{
    sp_plane_t *prev = NULL;
    sp_plane_t *plane = info->plane;

    while (plane != NULL && plane->id != id) {
        prev = plane;
        plane = plane->prev;
    }
    if (plane == NULL)
        return (1);
    if (prev == NULL)
        info->plane = plane->prev;
    else
        prev->prev = plane->prev;
    free(plane);
    return (0);
}

static void aircraft_movement(simulator_t *info, float dt, sfClock *mainclock)
{
    cross_map(info);
    for (sp_plane_t *pl = info->plane; pl != NULL; pl = pl->prev) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(mainclock)) < pl->delay)
            continue;
        pl->initial_position.x = pl->initial_position.x + (dt * pl->speed.x);
        pl->initial_position.y = pl->initial_position.y + (dt * pl->speed.y);
    }
}

static void destroy_information(simulator_t *info)
{
    sfSprite_destroy(info->tower->tower);
    sfRenderWindow_destroy(info->window);
}

void events(sfRenderWindow *window, simulator_t *info)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtTextEntered && (int)event.text.unicode == 83)
            change_visibility_sprites(info, event);
        if (event.type == sfEvtTextEntered && (int)event.text.unicode == 76)
            change_visibility_hitbox(info, event);
    }
}

int my_screen(simulator_t *info)
{
    float deltatime = 0.0;
    sfClock *clock = sfClock_create();
    sfClock *main_clock = sfClock_create();

    sfRenderWindow_setFramerateLimit(info->window, 30);
    while (sfRenderWindow_isOpen(info->window)) {
        sfRenderWindow_clear(info->window, sfBlack);
        deltatime = sfTime_asSeconds(sfClock_getElapsedTime(clock));
        sfClock_restart(clock);
        aircraft_movement(info, deltatime, main_clock);
        events(info->window, info);
        sfRenderWindow_drawSprite(info->window, info->background, NULL);
        if (info->plane == NULL)
            sfRenderWindow_close(info->window);
        intersecting_plane(info);
        draw_sprites(info->window, info, main_clock);
        sfRenderWindow_display(info->window);
    }
    destroy_information(info);
    return (0);
}
