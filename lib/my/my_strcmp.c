/*
** EPITECH PROJECT, 2021
** my strcmp
** File description:
** reproduce the behavior of the strcmp function
*/

#include <stddef.h>

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int str1 = my_strlen(s1);
    int str2 = my_strlen(s2);

    if (s1 == NULL || s2 == NULL)
        return 84;
    if (str1 == 0 || str2 == 0)
        return 0;
    if (str1 != str2)
        return 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}
