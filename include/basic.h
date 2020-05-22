/*
** EPITECH PROJECT, 2019
** bootstrap_world
** File description:
** base_inc.h
*/

#ifndef BASE_INC_H_
    #define BASE_INC_H_

    #define KEY_PRESSED(sfKey) (world->event.type == sfEvtKeyPressed && world->event.key.code == sfKey)

    #include "my.h"
    #include <stdlib.h>
    #include <unistd.h>
    #include <math.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/System/Vector3.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Window/Keyboard.h>
    #include <SFML/Window/Export.h>

    typedef struct square_s {
        sfVector2f a;
        sfVector2f b;
        sfVector2f c;
        sfVector2f d;
    } square_t;
    typedef struct button_s {
        sfSprite *sprite[2];
        sfTexture *texture[2];
        sfVector2f position;
        sfVector2f scale;
        sfIntRect rect;
        sfFloatRect bound;
        char id;
    } button_t;

    typedef struct world_s {
        float **tab;
        sfVector2f **map;
        sfVertexArray *lines;
        sfRenderWindow *win;
        sfEvent event;
        sfVector2i degrees;
        sfVector2i last_mp;
        int height;
        int width;
        float zoom;
        int delta_x;
        int delta_y;
        float rotate;
        float sm_zoom;
        float sm_delta_x;
        float sm_delta_y;
        float sm_rotate;
        int state;
        int grid;
        button_t **buttons;
    } world_t;

    button_t *init_b(char *act, char *inact, sfVector2f position, char id);

    int use_button(world_t *world, button_t **butt);

    button_t **create_button(void);

    void draw_button(world_t *world);

    void free_buttons(world_t *world);

    #define SMOOTH(sx, x, speed) (sx = sx + (x - sx) * speed)

#endif