/*
** EPITECH PROJECT, 2017
** convert.c
** File description:
** converteur
*/

int cti(char c)
{
	int	nb = c - 48;

	return (nb);
}

char itc(int nb)
{
	char	c = nb + 48;

	return (c);
}
