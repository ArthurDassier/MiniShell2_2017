/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** mes_prototypes
*/

#ifndef MYLIB_H_
#define MYLIB_H_
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char *dest, char *src);
int my_put_nbr_base(int nb, char *base);
long my_put_nbr_base_long(long long nb, char *base);
char **my_path_to_wordtab(char *str);
char **my_str_to_wordtab(char *str);
char *my_realloc(char *str);
void my_puterror(char *str);
int cti(char c);
char itc(int nb);

#endif
