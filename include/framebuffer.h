/*
** EPITECH PROJECT, 2019
** bootstrap_graphic
** File description:
** framebuffer.h
*/

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_
#include <SFML/Graphics.h>
#include <stdlib.h>

typedef struct framebuffer_s {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);

void framebuffer_destroy(framebuffer_t *framebuffer);

void my_put_pixel(framebuffer_t *fb, unsigned int x, unsigned int y, sfColor c);

void fade_fb(framebuffer_t *fb, int width, int height, unsigned int fade);

void clear_fb(framebuffer_t *fb, int width, int height);

#endif