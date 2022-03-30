/*
** EPITECH PROJECT, 2022
** lib [WSL: Manjaro]
** File description:
** free_char_arr
*/

#include <unistd.h>
#include <stdlib.h>

void free_char_arr(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
    return;
}
