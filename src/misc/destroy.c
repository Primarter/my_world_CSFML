/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** destroy.c
*/

#include "basic.h"

void free_buttons(world_t *world)
{
    for (int i = 0; world->buttons[i]; i++) {
        sfSprite_destroy(world->buttons[i]->sprite[0]);
        sfSprite_destroy(world->buttons[i]->sprite[1]);
        sfTexture_destroy(world->buttons[i]->texture[0]);
        sfTexture_destroy(world->buttons[i]->texture[1]);
        free(world->buttons[i]);
    }
    free(world->buttons);
}