/*
** EPITECH PROJECT, 2022
** printf [WSL: Manjaro]
** File description:
** my_printf
*/

#include "printf.h"

static const void (*print_func[])(va_list va) = {
    &print_percents,
    &print_str,
    &print_char,
    &print_nb
};

static const char *formatter = "%scd";
static const int nb_formatter = 4;

void which_formatter(char *format, va_list va)
{
    if (format == NULL)
        return;
    for (int i = 0; i < nb_formatter; i++) {
        if (format[1] == formatter[i]) {
            print_func[i](va);
            return;
        }
    }
    write(1, &format[0], 2);
}

int my_printf(const char *format, ...)
{
    va_list va;
    va_start(va, format);

    if (format == NULL)
        return 0;
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            which_formatter((char *)&format[i], va);
            i += 1;
        } else
            write(1, &format[i], 1);
    }
}
