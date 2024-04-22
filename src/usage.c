/*
** EPITECH PROJECT, 2024
** EPITECH PROJECT MY_RADAR
** File description:
** prints the usage of the program
*/

#include "../include/my.h"

void print_usage(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr("  ./my_radar [OPTIONS] path_to_script\n");
    my_putstr("    path_to_script    The path to the script file.\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("  -h\t\tprint the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("  'L' key\tenable/disable hitboxes and areas.\n");
    my_putstr("  'S' key\tenable/disable sprites.\n");
}
