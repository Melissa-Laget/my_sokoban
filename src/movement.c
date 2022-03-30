/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-melissa.laget [WSL: Manjaro]
** File description:
** movement
*/

#include "my_sokoban.h"

void key_movement(sokoban_t *sokoban, int key_touched)
{
    int pos_x = 0;
    int pos_y = 0;

    if (key_touched == RIGHT)
        pos_x++;
    if (key_touched == LEFT)
        pos_x--;
    if (key_touched == DOWN)
        pos_y++;
    if (key_touched == UP)
        pos_y--;
    collision_walls(sokoban, 0, pos_x, pos_y);

    return;
}

int collision_walls(sokoban_t *sokoban, int entity_index, int pos_x, int pos_y)
{
    if (sokoban->map[sokoban->entities[entity_index]->y + pos_y]
        [sokoban->entities[entity_index]->x + pos_x] == '#') {
        return 0;
    }
    if (collision_boxes(sokoban, entity_index, pos_x, pos_y) == 1) {
        sokoban->entities[entity_index]->x += pos_x;
        sokoban->entities[entity_index]->y += pos_y;
        return 1;
    }
    return 0;
}

int collision_boxes(sokoban_t *sokoban, int entity_index, int pos_x, int pos_y)
{
    for (int i = 0; i < sokoban->nb_entities; i++) {
        if (i == entity_index)
            continue;
        if (sokoban->entities[entity_index]->x + pos_x !=
            sokoban->entities[i]->x || sokoban->entities[entity_index]->y +
            pos_y != sokoban->entities[i]->y)
            continue;
        if (entity_index != 0)
            return 0;
        return collision_walls(sokoban, i, pos_x, pos_y);
    }
    return 1;
}
