/*
** EPITECH PROJECT, 2019
** PSU_my_exec_2019
** File description:
** array_handling.c
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

int check_str_empty(char *str)
{
    int i = 0;

    while (str && str[i]) {
        i++;
    }
    if (i == 0) {
        return (0);
    }
    return (1);
}

char *my_append_word(char *tmp, int *i, char *src)
{
    char *word = malloc(sizeof(char));
    char end = 0;

    word[0] = 0;
    if (src[*i] != '\"' && src[*i] != '\'')
        return (my_append_str(tmp, src[*i]));
    end = src[*i];
    *i += 1;
    for (; src[*i] != end; *i += 1)
        word = my_append_str(word, src[*i]);
    *i += 1;
    return (my_strcat(tmp, word));
}

char **my_append_array(char **array, char *str)
{
    size_t len = 0;
    char **tmp = NULL;

    if (!str || !str[0] || str[0] == '\n')
        return (array);
    for (; array[len]; len++);
    tmp = malloc(sizeof(char *) * (len + 2));
    for (int i = 0; array[i]; i++)
        tmp[i] = array[i];
    tmp[len] = str;
    tmp[len + 1] = NULL;
    return (tmp);
}

char **my_word_array(char *st)
{
    char *tmp = malloc(sizeof(char));
    char **array = malloc(sizeof(char *));

    tmp[0] = 0;
    array[0] = NULL;
    if (!st || st[0] == 0 || !(check_str_empty(st)))
        return (NULL);
    for (int i = 0; st[i]; i++) {
        for (; st[i] && st[i] != '\n' && st[i] != ' ' && st[i] != '\t'; i++)
            tmp = my_append_word(tmp, &i, st);
        if (i <= 0)
            continue;
        i--;
        if (st[i] && st[i] != 32 && st[i] != 9 && st[i] != 10) {
            array = my_append_array(array, tmp);
            tmp = malloc(sizeof(char));
            tmp[0] = 0;
        }
        i++;
    }
    return (array);
}