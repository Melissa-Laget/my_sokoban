/*
** EPITECH PROJECT, 2022
** lib [WSL: Manjaro]
** File description:
** my_strdup
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *dest = malloc(sizeof(char) * len + 1);
    int j = 0;

    if (src == NULL)
        return NULL;
    while (len < j) {
        dest[j] = src[j];
        j = j + 1;
    }
    dest[len] = '\0';
    return dest;
}
