/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-melissa.laget [WSL: Manjaro]
** File description:
** entities
*/

#include "my_sokoban.h"

entity_t *entitiesmap(char **map, int count)
{
    entity_t *entities = malloc(sizeof(entity_t));

    entities->x = count;
    return entities;
}

int count_entities_str(char **map, int i, int count)
{
    for (int j = 0; map[i][j] != '\0'; j++) {
        if (map[i][j] == 'P' || map[i][j] == 'X')
            count++;
    }
    return count;
}

int count_entities(char **map)
{
    int count = 0;

    for (int i = 0; map[i] != NULL; i++) {
        count = count_entities_str(map, i, count);
    }
    return count;
}
