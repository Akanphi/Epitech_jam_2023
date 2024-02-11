/*
** EPITECH PROJECT, 2024
** B-CPE-110-COT-1-1-secured-jean-baptiste.viossi
** File description:
** my_strdup
*/
#include "my.h"
char *my_strdup(char *src)
{
    int len = my_strlen(src) + 1;
    char *dest = malloc(len);

    if (src == NULL) {
        return NULL;
    }
    if (dest != NULL) {
        my_strcpy(dest, src);
    }
    return dest;
}
