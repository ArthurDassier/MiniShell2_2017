/*
** EPITECH PROJECT, 2017
** get_next_line.h
** File description:
** definer
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef READ_SIZE
#	define READ_SIZE (1)
#endif

char *get_next_line(int fd);
char *my_realloc(char *str);
int my_len(char const *str);

#endif
