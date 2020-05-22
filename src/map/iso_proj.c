/*
** EPITECH PROJECT, 2019
** bootstrap_world
** File description:
** iso_proj.c
*/

#include "iso_proj.h"

sfVector2f iso_proj(float x, float y, float z, world_t *world)
{
    sfVector2f fb_point = {0, 0};
    sfVector2f angle = {to_radians(world->degrees.x), to_radians(world->degrees.y)};

    fb_point.x = cosf(angle.x) * x - cosf(angle.x) * y + world->sm_delta_x;
    fb_point.y = sinf(angle.y) * y + sinf(angle.y) * x - z + world->sm_delta_y;
    return (fb_point);
}

int check_mouse_in_grid(sfVector2i mouse, world_t *world)
{
    float tmp = FLT_MAX;
    sfVector2i closest = (sfVector2i){0, 0};
    float mx = (float)mouse.x;
    float my = (float)mouse.y;
    float new_d = 0;

    for (int y = 0; y < world->height; y++) {
        for (int x = 0; x <= world->width; x++) {
            new_d = D(mx, my, world->map[y][x].x, world->map[y][x].y);
            if (new_d < tmp) {
                closest = (sfVector2i){x, y};
                tmp = new_d;
            }
        }
    }
    world->last_mp = closest;
    if (tmp > (world->sm_zoom * 3.0) * (world->sm_zoom * 3.0))
        return (0);
    return (1);
}

sfVector2f **create_2d_map(world_t *world)
{
    sfVector2f **new_map = malloc(sizeof(sfVector2f *) * (world->height + 1));
    int w = world->width;
    int h = world->height;
    float rx = 0.0;
    float ry = 0.0;
    float rz = 0.0;

    new_map[h] = NULL;
    for (int y = 0; y < h; y++) {
        new_map[y] = malloc(sizeof(sfVector2f) * (w));
        for (int x = 0; x < w; x++) {
            rx = RX(x, y, RAD(world->rotate), w / 2, h / 2) * world->zoom;
            ry = RY(x, y, RAD(world->rotate), w / 2, h / 2) * world->zoom;
            rz = world->tab[y][x] * world->zoom;
            new_map[y][x] = iso_proj(rx, ry, rz, world);
        }
    }
    return (new_map);
}