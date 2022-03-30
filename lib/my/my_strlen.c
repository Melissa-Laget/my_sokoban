/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** my_strlen
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int count = 0;

    if (str == NULL)
        return (-1);
    while (str[count] != '\0') {
        count = count + 1;
    }
    return (count);
}
