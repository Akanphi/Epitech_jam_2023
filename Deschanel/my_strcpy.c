/*
** EPITECH PROJECT, 2023
** MY_STRCPY
** File description:
** Strcpy String
*/
#include "my.h"
char *my_strcpy(char *dest, char *src)
{
    int size = my_strlen(src);

    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
    dest[size] = '\0';
    return dest;
}
