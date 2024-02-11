/*
** EPITECH PROJECT, 2024
** count char
** File description:
** count char
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

int my_count_char(char *buffer, char c)
{
    int i;
    int count_line = 0;

    for (i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == c) {
            count_line++;
        }
    }
    return count_line;
}
