/*
** EPITECH PROJECT, 2017
** get_next_line.c
** File description:
** blabla
*/

#include "../include/get_next_line.h"

char *get_next_line(int fd)
{
	int	check = 1;
	char	*str = malloc(sizeof(char) * 1024);
	char	buffer[READ_SIZE];
	int	i = 0;

	while ((check = read(fd, buffer, READ_SIZE)) > 0) {
		if (buffer[0] == '\n')
			break;
		str[i] = buffer[0];
		str[i + 1] = '\0';
		my_realloc(str);
		++i;
	}
	if (check == 0 && i == 0)
		return (NULL);
	str[i] = '\0';
	return (str);
}
