/*
** EPITECH PROJECT, 2019
** bootstrap_world
** File description:
** events.h
*/

#ifndef EVENTS_H_
#define EVENTS_H_

    #include "basic.h"
    #include "destroy.h"

    int handle_window(world_t *world);

    int manage_mouse_click(sfEvent event, sfRenderWindow *window);

    void treat_rotation(world_t *world);

    void treat_zoom(world_t *world);

    void treat_translation(world_t *world);

#endif