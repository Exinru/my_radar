/*
** EPITECH PROJECT, 2024
** EPITECH PROJECT MY_RADAR
** File description:
** create an array of the file
*/

#include "../include/my.h"

int get_file_height(char *filepath)
{
    int height = 0;
    char *buffer = filecont(filepath);

    for (int cont = 0; buffer[cont] != '\0'; cont++)
        if (buffer[cont] == '\n')
            height++;
    free(buffer);
    return (height);
}

char **get_array(char *filepath)
{
    int x = get_file_height(filepath) + 1;
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char **map;
    int cont = 0;

    stream = fopen(filepath, "r");
    map = malloc(x * sizeof(char *));
    nread = getline(&line, &len, stream);
    while (nread != -1) {
        map[cont] = malloc((my_strlen(line) + 1) * sizeof(char));
        my_strcpy(map[cont], line);
        cont++;
        nread = getline(&line, &len, stream);
    }
    fclose(stream);
    return (map);
}
