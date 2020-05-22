/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** table_gestion.c
*/

#include "my_graphic_func.h"

void reload_table(world_t *world)
{
    for (int y = 0; y < world->height; y++)
        for (int x = 0; x < world->width; x++)
            world->tab[y][x] = (float)((rand() % 15) / world->zoom);
    world->state = 0;
}

void flatten_table(world_t *world)
{
    for (int y = 0; y < world->height; y++)
        for (int x = 0; x < world->width; x++)
            world->tab[y][x] = 0;
}