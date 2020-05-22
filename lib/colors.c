/*
** EPITECH PROJECT, 2019
** bonus
** File description:
** colors.c
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "include/framebuffer.h"
#include "include/my_graphic_funct.h"
#include "include/structures.h"

saver_t int_to_colors(saver_t sv)
{
    sv.c.r = ((sv.n / 65536) % 256);
    sv.c.g = ((sv.n / 256) % 256);
    sv.c.b = sv.n % 256;
    sv.c.a = 255;
    return (sv);
}

// r = (n / 65536) % 256;
// g = (n / 256) % 256;
// b = n % 256;

// n = r * 65536 + g * 256 + b
// n(max) = 16 777 215