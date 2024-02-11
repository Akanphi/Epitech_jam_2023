/*
** EPITECH PROJECT, 2024
** getnbr
** File description:
** getnbr
*/

int my_getnbr(char *p)
{
    int i;
    int c = 0;

    for (i = 0; p[i] != '\0'; i++) {
        if (p[i] <= '9' && p[i] >= '0')
            c = c * 10 + (p[i] - 48);
    }
    return c;
}
