/*
** EPITECH PROJECT, 2022
** condition
** File description:
** win and loose condition
*/

#include "my_sokoban.h"

int count_holes_str(char **map, int i, int count)
{
    for (int j = 0; map[i][j] != '\0'; j++) {
        if (map[i][j] == 'O')
            count++;
    }
    return count;
}

int count_holes(char **map)
{
    int count = 0;

    for (int i = 0; map[i] != NULL; i++) {
        count = count_holes_str(map, i, count);
    }
    return count;
}

int win_condition(sokoban_t *sokoban)
{
    int count = 0;
    for (int i = 1; i < sokoban->nb_entities; i++) {
        if (sokoban->map[sokoban->entities[i]->y][sokoban->entities[i]->x] ==
            'O')
            count++;
    }
    if (count >= sokoban->nb_holes)
        return 0;
    return -1;
}

int lose_condition(sokoban_t *sokoban)
{
    int nb_collision = 0;

    for (int i = 1; i < sokoban->nb_entities; i++)
        nb_collision = lose_collision(sokoban, nb_collision, i);
    if (nb_collision == sokoban->nb_entities - 1)
        return 1;
    return -1;
}

int end_condition(sokoban_t *sokoban)
{
    if (win_condition(sokoban) != -1)
        return 0;
    if (lose_condition(sokoban) != -1)
        return 1;
    return -1;
}
