/*
** EPITECH PROJECT, 2019
** bootstrap_world
** File description:
** my_graphic_func.h
*/

#ifndef MY_GRAPHIC_FUNC_H_
#define MY_GRAPHIC_FUNC_H_

    #include "basic.h"

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "framebuffer.h"
    #include "my.h"
    #include "destroy.h"

    void create_quad(world_t *world);

    int my_draw_line(framebuffer_t *fb, sfVector2i p_a, sfVector2i p_b, sfColor c);

    void my_draw_rect(framebuffer_t *fb, sfVector2i p, sfVector2i s, sfColor c);

    sfVideoMode set_videomode(int width, int height, int bpp);

    void create_line(sfVertexArray *vertex_array, sfVector2f point1, sfVector2f point2);

    int draw_2d_map(world_t *world);

    void assemble_lines(world_t *world);

    void reload_table(world_t *world);

    void flatten_table(world_t *world);

#endif /* MY_GRAPHIC_FUNC_H_ */
