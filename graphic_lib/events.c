/*
** EPITECH PROJECT, 2019
** bootstrap_world
** File description:
** events.c
*/

#include "basic.h"
#include "update.h"
#include "iso_proj.h"

void update_z(world_t *world)
{
    int x = world->last_mp.x;
    int y = world->last_mp.y;

    if (world->event.mouseButton.button == sfMouseLeft) {
        world->tab[y][x] += 5.0 / world->sm_zoom;
    } else if (world->event.mouseButton.button == sfMouseRight) {
        world->tab[y][x] -= 5.0 / world->sm_zoom;
    }
}

void check_mouse_pos(world_t *world)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(world->win);

    if (use_button(world, world->buttons) == 0) {
        if (check_mouse_in_grid(mpos, world) == 1) {
            update_z(world);
        }
    }
}

int handle_window(world_t *world)
{
    static int pressed = 0;

    while (sfRenderWindow_pollEvent(world->win, &world->event)) {
        if (world->event.type == sfEvtMouseButtonReleased) {
            map_reload(world);
            world->state = 0;
            pressed = 0;
        }
        if (world->event.type == sfEvtClosed || KEY_PRESSED(sfKeyEscape))
            sfRenderWindow_close(world->win);
        if (world->event.type == sfEvtKeyPressed) {
            treat_zoom(world);
            treat_translation(world);
            treat_rotation(world);
        }
        if (world->event.type == sfEvtMouseButtonPressed)
            pressed = 1;
    }
    if (pressed)
            check_mouse_pos(world);
    return (0);
}