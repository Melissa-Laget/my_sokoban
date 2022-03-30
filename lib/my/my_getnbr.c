/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** my_getnbr
*/

int my_strlen(char const *str);

int my_getnbr(char const *str)
{
    int index = 0;
    long nb = 0;
    int neg = 1;

    for (; str[index] == '-' || str[index] == '+'; index = index + 1) {
        if (str[index] != '+')
            neg = neg * (-1);
    }
    if (my_strlen(str) - index > 10)
        return (0);
    while (str[index] != '\0' && str[index] >= 48 && str[index] <= 57) {
        nb = nb + str[index] - 48;
        nb = nb * 10;
        index = index + 1;
    }
    nb = nb / 10;
    if (nb > 2147483647)
        return (0);
    return (nb * neg);
}
