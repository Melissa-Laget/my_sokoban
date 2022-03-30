/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-melissa.laget [WSL: Manjaro]
** File description:
** map_info
*/

#include "printf.h"
#include "my.h"
#include "my_sokoban.h"

sokoban_t *get_map_info(sokoban_t *sokoban)
{
    int i = 0;

    sokoban->map_width = 0;
    for (; sokoban->map[i] != NULL; i++) {
        if (my_strlen(sokoban->map[i]) > sokoban->map_width)
            sokoban->map_width = my_strlen(sokoban->map[i]);
    }
    sokoban->map_height = i;
    return sokoban;
}

int lose_collision(sokoban_t *sokoban, int nb_collision, int i)
{
    if ((sokoban->map[sokoban->entities[i]->y + 1][sokoban->entities[i]->x
        + 0] == '#') && (sokoban->map[sokoban->entities[i]->y + 0]
        [sokoban->entities[i]->x + 1] == '#'))
        nb_collision++;
    if ((sokoban->map[sokoban->entities[i]->y + 0][sokoban->entities[i]->x
        + 1] == '#') && (sokoban->map[sokoban->entities[i]->y - 1]
        [sokoban->entities[i]->x + 0] == '#'))
        nb_collision++;
    if ((sokoban->map[sokoban->entities[i]->y - 1][sokoban->entities[i]->x
        + 0] == '#') && (sokoban->map[sokoban->entities[i]->y + 0]
        [sokoban->entities[i]->x - 1] == '#'))
        nb_collision++;
    if ((sokoban->map[sokoban->entities[i]->y + 0][sokoban->entities[i]->x
        - 1] == '#') && (sokoban->map[sokoban->entities[i]->y + 1]
        [sokoban->entities[i]->x + 0] == '#'))
        nb_collision++;
    return nb_collision;
}

int my_sokoban2(char *filepath, int key_touched, sokoban_t *sokoban, int *stat)
{
    while (key_touched != 112 && *stat == -1) {
        sokoban = init_sokoban(filepath);
        if (sokoban == NULL)
            return 84;
        draw_game(sokoban);
        while (*stat == -1 && (((key_touched = getch()) != SPACE) &&
            (key_touched != KEY_P))) {
            key_movement(sokoban, key_touched);
            draw_game(sokoban);
            *stat = end_condition(sokoban);
        }
        sokoban = free_sokoban(sokoban);
    }
    return key_touched;
}
