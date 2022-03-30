/*
** EPITECH PROJECT, 2022
** printf [WSL: Manjaro]
** File description:
** type
*/

#include "printf.h"

void print_str(va_list va)
{
    my_putstr(va_arg(va, char *));
    return;
}

void print_char(va_list va)
{
    my_putchar(va_arg(va, int));
    return;
}

void print_nb(va_list va)
{
    my_put_nbr(va_arg(va, int));
    return;
}

void print_percents(va_list va)
{
    my_putchar('%');
    return;
}
