/*
** EPITECH PROJECT, 2024
** show
** File description:
** show
*/

#include "../include/include.h"

void show_sprite(sfRenderWindow *window, char *path,
    sfVector2f pos, sfVector2f scale)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void show_text(sfRenderWindow *window, char *str,
    sfVector3f dimensions, char *font_name)
{
    sfFont *font = sfFont_createFromFile(font_name);
    sfText *text = sfText_create();
    sfVector2f pos = {dimensions.x, dimensions.y};

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, dimensions.z);
    sfText_setPosition(text, pos);
    sfText_setColor(text, sfBlack);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void show_rect(sfRenderWindow *window, sfVector2f pos, sfColor color[2],
    sfVector3f dimensions)
{
    sfRectangleShape *rectangle;
    sfVector2f size = {dimensions.x, dimensions.y};

    rectangle = create_rectangle((sfVector2f){pos.x, pos.y}, size, color[0]);
    sfRectangleShape_setOutlineColor(rectangle, color[1]);
    sfRectangleShape_setOutlineThickness(rectangle, dimensions.z);
    sfRectangleShape_setFillColor(rectangle, color[0]);
    sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
    sfRectangleShape_destroy(rectangle);
}

void show_circle(sfRenderWindow *w, sfVector2f pos, float rad, sfColor color)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setFillColor(circle, color);
    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setRadius(circle, rad);
    sfCircleShape_setOutlineColor(circle, color);
    sfRenderWindow_drawCircleShape(w, circle, NULL);
    sfCircleShape_destroy(circle);
}
