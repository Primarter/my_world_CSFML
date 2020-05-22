/*
** EPITECH PROJECT, 2019
** bootstrap_world
** File description:
** array_len.c
*/

#include <stdlib.h>

size_t array_len(char **array)
{
    size_t len = 0;

    while (array[len])
        len++;
    return (len);
}