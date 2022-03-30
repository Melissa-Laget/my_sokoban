/*
** EPITECH PROJECT, 2022
** printf [WSL: Manjaro]
** File description:
** printf
*/

#ifndef PRINTF_H
    #define PRINTF_H

    #include <stdarg.h>
    #include <unistd.h>

int my_printf(const char *format, ...);
void which_formatter(char *format, va_list va);
void my_putchar(char c);
int my_put_nbr(int nb);
void my_putstr(char const *str);
void print_str(va_list va);
void print_char(va_list va);
void print_nb(va_list va);
void print_percents(va_list va);

#endif
