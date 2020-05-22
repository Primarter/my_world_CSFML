/*
** EPITECH PROJECT, 2019
** bootstrap_world
** File description:
** iso_proj.h
*/

#ifndef ISO_PROJ_H_
    #define ISO_PROJ_H
    #define PI 3.14159265f
    #define RAD(d) (d*(PI/180))
    #define RX(x, y, t, a, b) (a + cosf(t) * (x - a) - sinf(t) * (y - b))
    #define RY(x, y, t, a, b) (b + sinf(t) * (x - a) + cosf(t) * (y - b))
    #define D(xa, ya, xb, yb) ((xa*xa + xb*xb - 2*xa*xb) + (ya*ya + yb*yb - 2*ya*yb))

    #include <float.h>
    #include <stdio.h>
    #include "basic.h"
    #include "angle_handling.h"

    sfVector2f iso_proj(float x, float y, float z, world_t *world);

    sfVector2f **create_2d_map(world_t *world);

    int check_mouse_in_grid(sfVector2i mouse, world_t *world);

    int check_line(sfVector2f mouse, world_t *world, int y);

    int contains(sfVector2f mouse, world_t *world, int x, int y);

#endif