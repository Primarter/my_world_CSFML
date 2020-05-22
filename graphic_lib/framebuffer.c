/*
** EPITECH PROJECT, 2019
** bootstrap_graphic
** File description:
** framebuffer.h
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "framebuffer.h"

void clear_fb(framebuffer_t *fb, int width, int height)
{
    int size = width * height * 4;

    for (int i = 0; i < size; i += 4) {
        fb->pixels[i] = 0;
        fb->pixels[i + 1] = 0;
        fb->pixels[i + 2] = 0;
        fb->pixels[i + 3] = 255;
    }
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer;

    framebuffer = malloc(sizeof(framebuffer_t));
    framebuffer->pixels = malloc(sizeof(sfUint8) * width * height * 4);
    framebuffer->height = height;
    framebuffer->width = width;
    clear_fb(framebuffer, width, height);
    return (framebuffer);
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
}

void my_put_pixel(framebuffer_t *fb, unsigned int x, unsigned int y, sfColor c)
{
    size_t pixel_location = (x + y * fb->width) * 4;

    fb->pixels[pixel_location] = c.r;
    fb->pixels[pixel_location + 1] = c.g;
    fb->pixels[pixel_location + 2] = c.b;
    fb->pixels[pixel_location + 3] = c.a;
}

void fade_fb(framebuffer_t *fb, int width, int height, unsigned int fade)
{
    int size = width * height * 4;

    for (int i = 0; i < size; i += 4) {
        fb->pixels[i] = 0;
        fb->pixels[i + 1] = 0;
        fb->pixels[i + 2] = 0;
        fb->pixels[i + 3] = fade;
    }
}