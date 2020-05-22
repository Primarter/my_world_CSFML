/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copy n characters from a string to another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int c = 0;

    for (; src[c] && c < n; c++)
        dest[c] = src[c];
    dest[c] = 0;
    return (dest);
}
