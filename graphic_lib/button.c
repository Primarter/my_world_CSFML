/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** buttons.c
*/

#include "basic.h"

button_t *init_b(char *act, char *inact, sfVector2f position, char id)
{
    button_t *button = malloc(sizeof(button_t));

    button->position = position;
    button->texture[0] = sfTexture_createFromFile(inact, NULL);
    button->sprite[0] = sfSprite_create();
    button->texture[1] = sfTexture_createFromFile(act, NULL);
    button->sprite[1] = sfSprite_create();
    for (int i = 0; i <= 1; i++) {
        sfSprite_setPosition(button->sprite[i], button->position);
        sfSprite_setTexture(button->sprite[i], button->texture[i], sfTrue);
        button->bound = sfSprite_getGlobalBounds(button->sprite[i]);
    }
    button->id = id;
    return (button);
}

int use_button(world_t *world, button_t **butt)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(world->win);

    for (int i = 0; butt[i]; i++)
        if (sfFloatRect_contains(&butt[i]->bound, mpos.x, mpos.y) == sfTrue) {
            world->state = butt[i]->id;
            return (1);
        }
    return (0);
}


button_t **create_button(void)
{
    button_t **butt = malloc(sizeof(button_t *) * 8);
    sfVector2f pos = {8, 8};

    butt[7] = NULL;
    butt[0] = init_b("assets/up_act.png", "assets/up_inact.png", pos, 'u');
    pos.y += 92;
    butt[1] = init_b("assets/down_act.png", "assets/down_inact.png", pos, 'd');
    pos.y += 92;
    butt[2] = init_b("assets/rotr_act.png", "assets/rotr_inact.png", pos, 'e');
    pos.y += 92;
    butt[3] = init_b("assets/rotl_act.png", "assets/rotl_inact.png", pos, 'w');
    pos.y += 92;
    butt[4] = init_b("assets/flat_act.png", "assets/flat_inact.png", pos, 'f');
    pos.y += 92;
    butt[5] = init_b("assets/grid_act.png", "assets/grid_inact.png", pos, 'g');
    pos.y += 92;
    butt[6] = init_b("assets/gen_act.png", "assets/gen_inact.png", pos, 'r');
    return (butt);
}

void draw_button(world_t *world)
{
    for (int i = 0; world->buttons[i]; i++) {
        if (world->state == world->buttons[i]->id)
            sfRenderWindow_drawSprite(world->win, world->buttons[i]->sprite[0], NULL);
        else
            sfRenderWindow_drawSprite(world->win, world->buttons[i]->sprite[1], NULL);
    }
}