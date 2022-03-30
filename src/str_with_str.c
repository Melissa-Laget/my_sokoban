/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-melissa.laget [WSL: Manjaro]
** File description:
** str_with_str
*/

#include <stddef.h>
#include <stdio.h>

#include "my.h"

static int in_str(char c, char const *str)
{
    if (str == NULL)
        return 84;
    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == c)
            return 0;
    }
    return 1;
}

int str_with_str(char const *str, char const *str2)
{
    int count = 0;

    if (str == NULL || str2 == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; i++) {
        if (in_str(str[i], str2) == 0)
            count += 1;
    }
    if (count == my_strlen(str))
        return 0;
    return 1;
}
