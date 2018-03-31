/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** putnbr
*/

#include <unistd.h>
#include "../../include/my.h"

int my_put_nbr(int nb)
{
	if (nb < 0) {
		nb = nb * (-1);
		my_putchar('-');
	}
	if (nb >= 10) {
		my_put_nbr(nb / 10);
		my_putchar(nb % 10 + '0');
	}
	if (nb < 10)
		my_putchar(nb % 10 + '0');
	return (0);
}
