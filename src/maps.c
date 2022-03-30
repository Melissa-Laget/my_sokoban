/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-bsmysokoban-melissa.laget [WSL: Manjaro]
** File description:
** maps
*/

#include "my_sokoban.h"
#include "my.h"

char *file_to_str(char *filepath)
{
    struct stat st;
    char *buff = NULL;
    int filedesc = open(filepath, O_RDONLY);

    if (filedesc < 0)
        return NULL;
    if (fstat(filedesc, &st) < 0)
        return NULL;
    buff = malloc(sizeof(char) * st.st_size + 1);
    if (read(filedesc, buff, st.st_size) < 1)
        return NULL;
    buff[st.st_size] = '\0';
    return buff;
}

char *my_strndup(char const *src, int nb)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * (nb + 1));

    if (src == NULL || dest == NULL)
        return NULL;
    dest[nb] = '\0';
    if (nb > my_strlen(src)) {
        return NULL;
    }
    while (i < nb) {
        dest[i] = src[i];
        i++;
    }
    return dest;
}

char **get_map(char *filepath)
{
    char *mapstr = file_to_str(filepath);
    char *bak = mapstr;
    char **map = NULL;
    int tmp = 0;
    int col = 0;

    if (mapstr == NULL)
        return NULL;
    tmp = count_line(mapstr);
    map = malloc(sizeof(char *) * (tmp + 1));
    map[tmp] = NULL;
    for (int i = 0; i < tmp; i++) {
        col = count_cols(mapstr);
        map[i] = my_strndup(mapstr, col);
        mapstr = &mapstr[col];
        (mapstr[0] != '\0') ? (mapstr = &mapstr[1]) : (mapstr = mapstr);
    }
    free(bak);
    return map;
}

int count_cols(char *map)
{
    int col = 0;

    for (; map[col] != '\n'; col++) {
        if (map[col] == '\0')
            return col;
    }
    return col;
}

int count_line(char *map)
{
    int line = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n')
            line++;
    }
    return line;
}
