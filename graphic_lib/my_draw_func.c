/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2019
** File description:
** my_draw_func.c
*/

#define H 720
#define W 1280
#define rad 30
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "framebuffer.h"

int my_draw_line(framebuffer_t *fb, sfVector2i p_a, sfVector2i p_b, sfColor c)
{
    if (p_a.x == p_b.x) {
        for (unsigned int i = 0; i < fb->height; i += 1) {
            my_put_pixel(fb, p_b.x, i, c);
        }
        return 0;
    }
    unsigned int a = (p_a.y - p_b.y) / (p_a.x - p_b.x);
    unsigned int b = p_a.y - a * p_a.x;

    for (unsigned int i = 0; i < fb->width; i += 1) {
        if (a * i + b < fb->height)
            my_put_pixel(fb, i, a * i + b, c);
    }
    return 0;
}

int my_draw_circle(framebuffer_t *fb, sfVector2i c, int radius, sfColor col)
{
    for (int i = 0; i < radius * 2; i += 1) {
        for (int j = 0; j < radius * 2; j += 1)
            if (pow((j - radius), 2) + pow(i - radius, 2) + 0.5f <= pow(radius, 2))
                my_put_pixel(fb, (c.x - radius) + j, (c.y - radius) + i, col);
    }
    return 0;
}

void my_draw_square(framebuffer_t *fb, sfVector2i p, unsigned int s, sfColor c)
{
    for (unsigned int i = 0; i < s; i += 1) {
        for (unsigned int j = 0; j < s; j += 1)
            my_put_pixel(fb, p.x + j, p.y + i, c);
    }
}

void my_draw_rect(framebuffer_t *fb, sfVector2i p, sfVector2i s, sfColor c)
{
    for (int i = 0; i < s.y; i += 1) {
        for (int j = 0; j < s.x; j += 1)
            my_put_pixel(fb, p.x + j, p.y + i, c);
    }
}