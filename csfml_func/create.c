/*
** EPITECH PROJECT, 2024
** create
** File description:
** create
*/

#include "../include/include.h"

sfRenderWindow *window_create(int width, int height, int bPP, int framerate)
{
    sfRenderWindow *w;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = bPP;
    w = sfRenderWindow_create(video_mode, "My RPG", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(w, framerate);
    sfRenderWindow_setVerticalSyncEnabled(w, sfTrue);
    return w;
}

sfRenderWindow *window_create_fullscreen(int width, int height,
    int bPP, int framerate)
{
    sfRenderWindow *w;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = bPP;
    w = sfRenderWindow_create(video_mode, "My RPG", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(w, framerate);
    sfRenderWindow_setVerticalSyncEnabled(w, sfTrue);
    return w;
}

sfText *create_text(char const *name, char *filepath
    , sfVector2f pos, sfColor color)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(filepath);

    sfText_setString(text, name);
    sfText_setScale(text, (sfVector2f){1.0, 1.0});
    sfText_setFont(text, font);
    sfText_setColor(text, color);
    sfText_setPosition(text, pos);
    return text;
}

sfIntRect create_rect(int left, int top, int w, int h)
{
    sfIntRect rect;

    rect.top = top;
    rect.width = w;
    rect.left = left;
    rect.height = h;
    return rect;
}

sfRectangleShape *create_rectangle(sfVector2f pos,
    sfVector2f size, sfColor color)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setOutlineThickness(rectangle, 1.0);
    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setFillColor(rectangle, color);
    sfRectangleShape_setOutlineColor(rectangle, sfBlack);
    sfRectangleShape_setPosition(rectangle, pos);
    return rectangle;
}
