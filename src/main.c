/*
** EPITECH PROJECT, 2024
** EPITECH PROJECT MY_RADAR
** File description:
** main function
*/

#include "../include/my.h"

int main(int ac, char **argv)
{
    entities_t *simulation = malloc(sizeof(entities_t));
    simulator_t *info = malloc(sizeof(simulator_t));

    if (ac != 2)
        return (84);
    if (ac == 2 && my_strcmp(argv[1], "-h") == 0) {
        print_usage();
        return (0);
    }
    if (check_file(argv[1]) == 0) {
        add_information_file(argv[1], simulation);
        add_sprite_info(simulation, info);
        my_screen(info);
        return (0);
    }
    return (84);
}
