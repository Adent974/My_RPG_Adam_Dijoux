/*
** EPITECH PROJECT, 2024
** dialogue
** File description:
** dialogue
*/

#include "include/include.h"

void wait_select(global_t *global)
{
    sfEvent event;

    while (1) {
        sfRenderWindow_waitEvent(global->window, &event);
        if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(global->settings->move_keys[4]))
            break;
    }
}

static void next_page(global_t *global, dialogue_t *dialogue)
{
    wait_select(global);
    dialogue->page++;
    dialogue->current_letter = 0;
    free(dialogue->tmp_speech);
    dialogue->tmp_speech = strdup("");
}

static void finish_dialogue(global_t *global, dialogue_t *dialogue)
{
    dialogue->page = 0;
    dialogue->nb_talks++;
    global->dialogue_active = 0;
}

static void next_letter(dialogue_t *dialogue)
{
    char text[2] = "";
    int i = dialogue->nb_talks;

    sfClock_restart(dialogue->clock);
    text[0] = dialogue->tab[i][dialogue->page][dialogue->current_letter];
    text[1] = '\0';
    dialogue->tmp_speech = my_strcat(dialogue->tmp_speech, text, "");
    dialogue->current_letter++;
}

void dialogue(global_t *global, dialogue_t *dialogue)
{
    sfTime time = sfClock_getElapsedTime(dialogue->clock);

    if (!dialogue->tab[dialogue->nb_talks][dialogue->page]) {
        finish_dialogue(global, dialogue);
        return;
    }
    if (strcmp(dialogue->tmp_speech,
    dialogue->tab[dialogue->nb_talks][dialogue->page]) == 0) {
        next_page(global, dialogue);
        return;
    }
    if (sfKeyboard_isKeyPressed(global->settings->move_keys[6])) {
        free(dialogue->tmp_speech);
        dialogue->tmp_speech =
        strdup(dialogue->tab[dialogue->nb_talks][dialogue->page]);
        return;
    }
    if (time.microseconds > 20000)
        next_letter(dialogue);
}

void display_dialogue(global_t *global)
{
    sfVector2f win_pos = sfView_getCenter(global->view);

    show_rect(global->window, (sfVector2f){win_pos.x - 900, win_pos.y + 200},
    (sfColor[2]){sfWhite, sfBlack}, (sfVector3f){1800, 150, 2});
    show_text(global->window, global->dialogue->tmp_speech,
    (sfVector3f){win_pos.x - 880, win_pos.y + 230, 35}, "rs/KarmaFuture.ttf");
}

void init_dialogue(dialogue_t *dialogue, char *path)
{
    char *str = fileread(path);
    char **tab = my_str_to_array(str, "!");
    char *str2 = NULL;
    int i = 0;

    dialogue->clock = sfClock_create();
    dialogue->current_letter = 0;
    dialogue->page = 0;
    dialogue->nb_talks = 0;
    dialogue->tmp_speech = strdup("");
    dialogue->speech = tab;
    dialogue->tab = my_malloc(sizeof(char **) * (my_tablen(dialogue->speech)));
    for (i = 0; dialogue->speech[i]; i++) {
        str2 = strdup(dialogue->speech[i]);
        dialogue->tab[i] = my_str_to_array(str2, "\n");
        free(str2);
    }
    dialogue->tab[i] = NULL;
    free(str);
    dialogue->nb_talks_max = (my_tablen(tab) - 1);
}
