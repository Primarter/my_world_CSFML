/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** manage_keyboard.c
*/

#include "basic.h"
#include "update.h"

void treat_rotation(world_t *world)
{
    switch (world->event.key.code) {
        case sfKeyK:
            world->degrees.y += 1;
            world->delta_y -= 5;
            break;
        case sfKeyI:
            world->degrees.y += -0.01;
            world->delta_y += 5;
            break;
        case sfKeyL:
            world->rotate += 5;
            break;
        case sfKeyJ:
            world->rotate += -5;
            break;
        case sfKeyR:
            reload_table(world);
            break;
        default:
            break;
    }
}

void treat_zoom(world_t *world)
{
    switch (world->event.key.code) {
        case sfKeyZ:
            world->zoom += 0.5;
            break;
        case sfKeyS:
            world->zoom += world->zoom > 1 ? -0.5 : 0;
            break;
        default:
            break;
    }
}

void treat_translation(world_t *world)
{
    switch (world->event.key.code) {
        case sfKeyDown:
            world->delta_y += 15;
            break;
        case sfKeyUp:
            world->delta_y += -15;
            break;
        case sfKeyRight:
            world->delta_x += 15;
            break;
        case sfKeyLeft:
            world->delta_x += -15;
            break;
        default:
            break;
    }
}