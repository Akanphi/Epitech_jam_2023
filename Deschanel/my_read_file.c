/*
** EPITECH PROJECT, 2024
** read file
** File description:
** read file
*/
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

char *my_read_file(char *filepath)
{
    int s;
    int r;
    int fd;
    char *buffer;

    fd = open(filepath, O_RDONLY);
    buffer = malloc(500 * sizeof(char));
    r = read(fd, buffer, 500 * sizeof(char));
    close(fd);
    return buffer;
}
