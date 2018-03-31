/*
** EPITECH PROJECT, 2017
** my_puterror.c
** File description:
** blabla
*/

#include <unistd.h>
#include "../../include/my.h"

void my_puterror(char *str)
{
	write(2, str, my_strlen(str));
}
