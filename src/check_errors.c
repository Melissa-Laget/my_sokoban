/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-melissa.laget [WSL: Manjaro]
** File description:
** check_errors
*/

#include "my_sokoban.h"

int check_errors(sokoban_t *sokoban)
{
    if (sokoban->nb_holes > sokoban->nb_entities - 1)
        return 84;
    if (sokoban->entities[0]->symbol != 'P')
        return 84;
    for (int i = 0; sokoban->map[i] != NULL; i++) {
        if (str_with_str(sokoban->map[i], "POX #") == 1)
            return 84;
    }
    return 0;
}
