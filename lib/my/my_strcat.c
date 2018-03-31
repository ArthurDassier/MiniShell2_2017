/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** strcat
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strcat(char *dest, char *src)
{
	char	*tmp = malloc(sizeof(char) * (my_strlen(dest) +
	my_strlen(src) + 1));
	int	i = 0;
	int	j = 0;
	int	count = 0;

	while (dest[i] != '\0') {
		tmp[count] = dest[i];
		++count;
		++i;
	}
	while (src[j] != '\0') {
		tmp[count] = src[j];
		++count;
		++j;
	}
	tmp[count] = '\0';
	return (tmp);
}
