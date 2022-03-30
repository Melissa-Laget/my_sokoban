/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-melissa.laget [WSL: Manjaro]
** File description:
** my_sokoban
*/

#include "printf.h"
#include "my.h"
#include "my_sokoban.h"

sokoban_t *init_sokoban(char *filepath)
{
    sokoban_t *sokoban = malloc(sizeof(sokoban_t));

    sokoban->map = get_map(filepath);
    if (sokoban->map == NULL)
        return NULL;
    sokoban->nb_entities = count_entities(sokoban->map);
    sokoban->nb_holes = count_holes(sokoban->map);
    sokoban->entities = malloc(sizeof(entity_t*) * (sokoban->nb_entities + 1));
    sokoban->entities[sokoban->nb_entities] = NULL;
    sokoban->entities[0] = get_entities(sokoban, sokoban->entities[0], 'P');
    for (int i = 1; i < sokoban->nb_entities; i++)
        sokoban->entities[i] = get_entities(sokoban, sokoban->entities[i],
        'X');
    if (check_errors(sokoban) != 0)
        return NULL;
    sokoban = get_map_info(sokoban);
    return sokoban;
}

entity_t *get_entities_position_x(char **map, int i, entity_t *ent, char sym)
{
    for (int j = 0; map[i][j] != '\0'; j++) {
        if (map[i][j] == sym) {
            ent->x = j;
            ent->y = i;
            ent->status = 0;
            ent->symbol = sym;
            map[i][j] = ' ';
            return ent;
        }
    }
    return ent;
}

entity_t *get_entities(sokoban_t *sokoban, entity_t *entity, char symbol)
{
    int count = 0;

    entity = malloc(sizeof(entity_t));
    entity->status = 1;
    for (int i = 0; sokoban->map[i] != NULL && entity->status != 0; i++) {
        entity = get_entities_position_x(sokoban->map, i, entity, symbol);
    }
    return entity;
}

sokoban_t *free_sokoban(sokoban_t *sokoban)
{
    for (int i = 0; sokoban->map[i] != NULL; i++)
        free(sokoban->map[i]);
    free(sokoban->map);
    for (int i = 0; sokoban->entities[i] != NULL; i++)
        free(sokoban->entities[i]);
    free(sokoban->entities);
    free(sokoban);
    return NULL;
}

int my_sokoban(char *filepath)
{
    sokoban_t *sokoban = NULL;
    int key_touched = 0;
    int status = -1;

    initscr();
    curs_set(0);
    key_touched = my_sokoban2(filepath, key_touched, sokoban, &status);
    usleep(2);
    endwin();
    if (key_touched == 112)
        return 1;
    if (key_touched == 84)
        return 84;
    return status;
}
