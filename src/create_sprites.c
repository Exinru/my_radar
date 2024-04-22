/*
** EPITECH PROJECT, 2024
** EPITECH PROJECT MY_RADAR
** File description:
** create sprites
*/

#include "../include/my.h"

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, sfBlack);
    sfCircleShape_setOutlineThickness(circle, 1.00);
    sfCircleShape_setRadius(circle, radius);
    position.x = position.x - radius + 12;
    position.y = position.y - radius + 12;
    sfCircleShape_setPosition(circle, position);
    return (circle);
}

sfSprite *create_sprite(char *filepath)
{
    sfTexture *texture =
        sfTexture_createFromFile(filepath, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, true);
    return (sprite);
}
