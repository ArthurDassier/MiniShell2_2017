/*
** EPITECH PROJECT, 2017
** my_put_nbr_base_long.c
** File description:
** baselong
*/

#include <unistd.h>
#include "../../include/my.h"

long my_put_nbr_base_long(long long nb, char *base)
{
	long	res = nb / my_strlen(base);
	long	rest = nb % my_strlen(base);

	if (res > 0)
		my_put_nbr_base_long(res, base);
	my_putchar(base[rest]);
	return (0);
}
