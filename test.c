/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** test.c
*/

#include <stdio.h>
#include "include/my.h"
#include "include/basic.h"

void make_squares(sfVector2f **vec)
{
    for (int i = 0; i < 10 - 1; i += 1) {
        for (int y = 0; y < 10 - 1; y += 1) {
            printf("(%.2f, %.2f) - (%.2f, %.2f)\n(%.2f, %.2f) - (%.2f, %.2f)\n\n", vec[i][y].x, vec[i][y].y, vec[i][y + 1].x, vec[i][y + 1].y, vec[i + 1][y].x, vec[i + 1][y].y, vec[i + 1][y + 1].x, vec[i + 1][y + 1].y);
        }
    }
}

sfVector2f **make_map(int height, int width)
{
    sfVector2f **vec = malloc(sizeof(sfVector2f*) * height);
    for (int i = 0; i < height; i += 1) {
        vec[i] = malloc(sizeof(sfVector2f) * width);
        for (int y = 0; y < width; y += 1) {
            vec[i][y].x = ((float)(rand() % 350)) / 10;
            vec[i][y].y = ((float)(rand() % 350)) / 10;
        }
    }
    return (vec);
}

void print_map(sfVector2f **map)
{
    for (int i = 0; i < 10; i += 1) {
        for (int y = 0; y < 10; y += 1) {
            printf("%.2f-%.2f   ", map[i][y].x, map[i][y].y);
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    int height = 10;
    int width = 10;

    sfVector2f **vec = make_map(height, width);
    print_map(vec);
    make_squares(vec);
}