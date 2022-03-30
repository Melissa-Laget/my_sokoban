/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-melissa.laget [WSL: Manjaro]
** File description:
** check_help
*/

#include "my_sokoban.h"

int check_help(int argc, char **argv)
{
    struct stat st;
    int i = 1;
    char *filepath = "ressources/rules.txt";
    int fd = 0;
    char *buffer = NULL;

    while (i < argc) {
        if (argv[i][0] == '-' && argv[i][1] == 'h') {
            fd = open(filepath, O_RDONLY);
            fstat(fd, &st);
            buffer = malloc(sizeof(char) * (st.st_size + 1));
            read(fd, buffer, st.st_size);
            write(1, buffer, st.st_size);
            close(fd);
            free(buffer);
            return 1;
        }
        i += 1;
    }
    return 0;
}
