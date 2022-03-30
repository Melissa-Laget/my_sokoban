/*
** EPITECH PROJECT, 2022
** sokoban [WSL: Manjaro]
** File description:
** main
*/

#include "printf.h"
#include "my.h"
#include "my_sokoban.h"

int main(int argc, char **argv)
{
    int result = check_help(argc, argv);

    if (result == 1)
        return 0;
    if (argc != 2)
        return 84;
    return my_sokoban(argv[1]);
}
