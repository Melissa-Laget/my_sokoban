/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-bsmysokoban-melissa.laget [WSL: Manjaro]
** File description:
** my_sokoban
*/

#ifndef MY_SOKOBAN_H
    #define MY_SOKOBAN_H

    #include <curses.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>

    #define SPACE 32
    #define KEY_P 112
    #define UP 65
    #define DOWN 66
    #define RIGHT 67
    #define LEFT 68

typedef struct entity_s {
    int x;
    int y;
    int status;
    char symbol;
} entity_t;

typedef struct sokoban_s {
    entity_t **entities;
    int nb_entities;
    int nb_holes;
    char **map;
    int map_height;
    int map_width;
} sokoban_t;

int check_help(int argc, char **argv);
int count_line(char *map);
int count_cols(char *map);
int count_entities(char **map);
int my_sokoban(char *filepath);
int collision_walls(sokoban_t *sokoban, int entity_index, int pos_x,
int pos_y);
int collision_boxes(sokoban_t *sokoban, int entity_index, int pos_x,
int pos_y);
int count_holes(char **map);
int count_holes_str(char **map, int i, int count);
int win_condition(sokoban_t *sokoban);
int end_condition(sokoban_t *sokoban);
int lose_collision(sokoban_t *sokoban, int nb_collision, int i);
int check_errors(sokoban_t *sokoban);
int my_sokoban2(char *filepath, int key_touched, sokoban_t *sokoban,
int *stat);
int str_with_str(char const *str, char const *str2);
char *file_to_str(char *filepath);
char **get_map(char *filepath);
void draw_game(sokoban_t *sokoban);
void draw_map(sokoban_t *sokoban, int row, int col);
void key_movement(sokoban_t *sokoban, int key_touched);
sokoban_t *get_map_info(sokoban_t *sokoban);
entity_t *get_entities_position_x(char **map, int i, entity_t *ent, char sym);
entity_t *get_entities(sokoban_t *sokoban, entity_t *entity, char symbol);
sokoban_t *init_sokoban(char *filepath);
sokoban_t *free_sokoban(sokoban_t *sokoban);

#endif
