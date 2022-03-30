/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-melissa.laget [WSL: Manjaro]
** File description:
** display
*/

#include "my_sokoban.h"
#include "my.h"

void draw_map(sokoban_t *sokoban, int row, int col)
{
    for (int i = 0; sokoban->map[i] != NULL; i++) {
        mvprintw(((row / 2) - (sokoban->map_height / 2)) + i,
        (col / 2) - (sokoban->map_width / 2), sokoban->map[i]);
    }
    return;
}

void draw_entities(sokoban_t *sokoban, int row, int col)
{
    for (int i = 0; i < sokoban->nb_entities; i++) {
        mvprintw(((row / 2) - (sokoban->map_height / 2) +
        sokoban->entities[i]->y), ((col / 2) - (sokoban->map_width / 2)) +
        sokoban->entities[i]->x, "%c", sokoban->entities[i]->symbol);
        refresh();
    }
    return;
}

void draw_too_small(int row, int col)
{
    char text[] = "Invalid Size";

    clear();
    mvprintw((row / 2), ((col / 2) - (my_strlen(text) / 2)), text);
    refresh();
}

void draw_game(sokoban_t *sokoban)
{
    int row = 0;
    int col = 0;

    getmaxyx(stdscr, row, col);
    if (row < sokoban->map_height || col < sokoban->map_width) {
        draw_too_small(row, col);
        return;
    }
    clear();
    draw_map(sokoban, row, col);
    draw_entities(sokoban, row, col);
    refresh();
    return;
}
