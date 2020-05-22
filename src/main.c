/*
** EPITECH PROJECT, 2019
** bootstrap_world
** File description:
** main.c
*/

#include "main.h"

int print_help(void)
{
    my_printf("MY_WORLD\n");
    my_printf("Basic random terrain generation\n\nUSAGE:\n");
    my_printf("./my_world\n");
    my_printf("Creates a grid of 60*60 size for you to play with!\n");
    my_printf("\nKEYS:\n");
    my_printf("Z, S:\t\tzoom or dezoom\nI, J, K, L:\trotate the plan\n");
    my_printf("Arrows:\t\ttranslate the plan\n");
    my_printf("R:\t\treload the map\n\n");
    my_printf("BUTTONS:\neach button has a purpose: rotation, ");
    my_printf("flattening, grid mode or textured mode, reload\n");
    my_printf("Some of them are mapped on the keyboard, others not.\n\n");
    my_printf("MOUSE CONTROLS:\nBoth clicks find the nearest point and apply");
    my_printf(" a transformation on it: right makes it go down, left up\n");
    my_printf("\nThis project was made by Raphaël Risser and Alec Ferrari\n");
    return (0);
}

float **new_tab(int height, int width, world_t *world)
{
    float **tab = malloc(sizeof(float *) * height);

    for (int y = 0; y < height; y++) {
        tab[y] = malloc(sizeof(float) * width);
        for (int x = 0; x < width; x++) {
            tab[y][x] = (float)((rand() % 15) / world->zoom);
        }
    }
    return (tab);
}

world_t *new_world(void)
{
    sfVideoMode md = set_videomode(1080, 720, 32);
    world_t *world = malloc(sizeof(world_t));

    world->rotate = 0;
    world->width = 50;
    world->height = 50;
    world->zoom = 10.0f;
    world->tab = new_tab(world->height, world->width, world);
    world->sm_zoom = 0.01f;
    world->delta_x = 540;
    world->delta_y = 360 - (world->zoom * world->height / 2 * sqrt(2)) + 10;
    world->degrees = (sfVector2i) {35, 45};
    world->sm_delta_x = world->delta_x;
    world->sm_delta_y = world->delta_y;
    world->map = create_2d_map(world);
    world->win = sfRenderWindow_create(md, "World", sfClose, NULL);
    assemble_lines(world);
    world->buttons = create_button();
    world->last_mp = (sfVector2i){-1, -1};
    world->grid = 1;
    return (world);
}

void destroy_world(world_t *world)
{
    free_buttons(world);
    for (int i = 0; i < world->height; i++) {
        free(world->tab[i]);
        free(world->map[i]);
    }
    free(world->tab);
    free(world->map);
    sfVertexArray_destroy(world->lines);
    sfRenderWindow_destroy(world->win);
}

int main(int argc, char const *argv[])
{
    world_t *world = NULL;

    if (argc == 2 && !my_strcmp(argv[1], "-h"))
        return (print_help());
    if (argc != 1)
        return (84);
    world = new_world();
    world->state = 0;
    sfRenderWindow_setFramerateLimit(world->win, 60);
    while (sfRenderWindow_isOpen(world->win)) {
        handle_window(world);
        sfRenderWindow_clear(world->win, sfBlack);
        update(world);
        draw_button(world);
        SMOOTH(world->sm_delta_y, world->delta_y, 0.2f);
        SMOOTH(world->sm_delta_x, world->delta_x, 0.2f);
        SMOOTH(world->sm_zoom, world->zoom, 0.1f);
        sfRenderWindow_display(world->win);
    }
    destroy_world(world);
    return (0);
}