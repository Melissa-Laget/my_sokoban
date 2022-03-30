/*
** EPITECH PROJECT, 2022
** sokoban [WSL: Manjaro]
** File description:
** my
*/

#ifndef MY_H
    #define MY_H

int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_put_nbr(int nb);
int my_strcmp(char const *s1, char const *s2);
void my_putstr(char const *str);
void my_putchar(char c);
char *my_strdup(char const *src);
void free_char_arr(char **arr);
void char_arr_len(char **arr);
void concat_str(char *str);
void add_to_char_arr(char **arr);
void my_nbrlen(int nb);
void my_str_to_word_array(const char *str);

#endif
