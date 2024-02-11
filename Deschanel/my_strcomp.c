/*
** EPITECH PROJECT, 2024
** my strcomp
** File description:
** my strcomp
*/
#include "my.h"
int my_strcomp(char *str1, char *str2)
{
    int i;
    int a = my_strlen(str1);
    int b = my_strlen(str2);

    if (a != b)
        return 1;
    for (i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == str2[i])
            continue;
        else
            return 1;
    }
    return 0;
}
