/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2019
** File description:
** my_graphic_func.c
*/

#include "my_graphic_func.h"

void create_quad(world_t *world)
{
    sfColor sforange = {255, 150, 25, 255};
    sfVertexArray *va = sfVertexArray_create();

    sfVertexArray_setPrimitiveType(va, sfQuads);
    for (int y = 0; y < world->height - 1; y++) {
        for (int x = 0; x < world->width - 1; x++) {
            sfVertex vertex1 = {.position = world->map[y][x], .color = sforange};
            sfVertex vertex2 = {.position = world->map[y][x + 1], .color = sforange};
            sfVertex vertex3 = {.position = world->map[y + 1][x + 1], .color = sforange};
            sfVertex vertex4 = {.position = world->map[y + 1][x], .color = sforange};
            sfVertexArray_append(va, vertex1);
            sfVertexArray_append(va, vertex2);
            sfVertexArray_append(va, vertex3);
            sfVertexArray_append(va, vertex4);
        }
    }
    sfRenderWindow_drawVertexArray(world->win, va, NULL);
}

sfVideoMode set_videomode(int width, int height, int bpp)
{
    return ((sfVideoMode){width, height, bpp});
}

void create_line(sfVertexArray *va, sfVector2f p1, sfVector2f p2)
{
    sfVertex vertex1 = {.position = p1, .color = sfBlue};
    sfVertex vertex2 = {.position = p2, .color = sfBlue};

    sfVertexArray_append(va, vertex1);
    sfVertexArray_append(va, vertex2);
}

void assemble_lines(world_t *world)
{
    sfVertexArray *lines = sfVertexArray_create();

    sfVertexArray_setPrimitiveType(lines, sfLines);
    for (int y = 0; y < world->height; y++) {
        for (int x = 0; x < world->width - 1; x++) {
            create_line(lines, world->map[y][x], world->map[y][x + 1]);
        }
    }
    for (int x = 0; x < world->width; x++) {
        for (int y = 0; y < world->height - 1; y++) {
            create_line(lines, world->map[y][x], world->map[y + 1][x]);
        }
    }
    //sfVertexArray_destroy(world->lines);
    world->lines = lines;
    sfRenderWindow_drawVertexArray(world->win, world->lines, NULL);
}

int draw_2d_map(world_t *world)
{
    sfVertexArray *line = sfVertexArray_create();

    for (int y = 0; y < world->height; y++) {
        for (int x = 0; x < world->width - 1; x++) {
            create_line(line, world->map[y][x], world->map[y][x + 1]);
            sfRenderWindow_drawVertexArray(world->win, line, NULL);
        }
    }
    for (int x = 0; x < world->width; x++) {
        for (int y = 0; y < world->height - 1; y++) {
            create_line(line, world->map[y][x], world->map[y + 1][x]);
            sfRenderWindow_drawVertexArray(world->win, line, NULL);
        }
    }
    sfVertexArray_destroy(line);
    return (0);
}