/*
** EPITECH PROJECT, 2024
** EPITECH PROJECT MY_RADAR
** File description:
** check the information provide in the file
*/

#include "../include/my.h"

int check_information(char *buffer)
{
    for (int i = 0; buffer[i] != 0; i++) {
        if (buffer[i] == 'A' || buffer[i] == 'T'
        || buffer[i] == '\n' || buffer[i] == '\t' ||
        buffer[i] == ' ')
        continue;
        if (buffer[i] >= '0' && buffer[i] <= '9')
            continue;
        return (-1);
    }
    return (0);
}

int check_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer;
    struct stat info;

    if (fd == -1) {
        my_putstr("invalid or non-existing file\n");
        return (-1);
    }
    stat(filepath, &info);
    buffer = malloc(sizeof(char) * (info.st_size + 1));
    read(fd, buffer, info.st_size);
    if (check_information(buffer) != 0) {
        my_putstr("invalid information\n");
        return (-1);
    }
    free(buffer);
    close(fd);
    return (0);
}

char *filecont(char *filepath)
{
    struct stat file_size;
    int fd = open(filepath, O_RDONLY);
    char *buffer;

    stat(filepath, &file_size);
    buffer = malloc((file_size.st_size + 1) * sizeof(char));
    read(fd, buffer, file_size.st_size);
    my_putchar(buffer[file_size.st_size]);
    close(fd);
    return (buffer);
}
