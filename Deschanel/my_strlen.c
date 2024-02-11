/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** my_strlen
*/
int my_strlen(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return i;
}
