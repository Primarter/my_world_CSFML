/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** update.c
*/

#include "update.h"
#include "my_graphic_func.h"

void update_2d_map(world_t *world)
{
    int w = world->width;
    int h = world->height;
    float rx = 0.0;
    float ry = 0.0;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            rx = RX(x, y, RAD(world->rotate), w / 2, h / 2) * world->sm_zoom;
            ry = RY(x, y, RAD(world->rotate), w / 2, h / 2) * world->sm_zoom;
            world->map[y][x] = iso_proj(rx, ry, world->tab[y][x] * world->sm_zoom, world);
        }
    }
}

void map_reload(world_t *world)
{
    switch (world->state) {
        case 'r':
            return (reload_table(world));
        case 'f':
            return (flatten_table(world));
        case 'g':
            world->grid = world->grid == 1 ? 0 : 1;
            return;
        case 's':
            return;
        default:
            return;
    }
}

int move_with_buttons(world_t *world)
{
    switch (world->state) {
        case 'e':
            world->rotate += 2;
            return (1);
        case 'w':
            world->rotate -= 2;
            return (1);
        case 'u':
            world->degrees.y -= 1;
            world->delta_y += 5;
            return (1);
        case 'd':
            world->degrees.y += 1;
            world->delta_y -= 5;
            return (1);
        default:
            return (0);
    }
}

void update(world_t *world)
{
    if (world->state != 0) {
        if (move_with_buttons(world))
            world->state = 0;
    }
    update_2d_map(world);
    if (world->grid == 1)
        create_quad(world);
    assemble_lines(world);
}
