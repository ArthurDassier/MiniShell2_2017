/*
** EPITECH PROJECT, 2018
** builds.c
** File description:
** Arthur
*/

#include "minishell1.h"
#include "printf.h"

int count_line(char **tab)
{
	int i = 0;

	while (tab[i])
		++i;
	return (i);
}

int try_build(char **tab, list_path *my_env)
{
	int	ret = 0;

	if (tab == NULL)
		return (0);
	if (my_env == NULL) {
		my_printf_err("%e: Command not found.\n", tab[0]);
		return (1);
	}
	ret = try_env(tab, my_env);
	if (ret != -1)
		return (ret);
	if (my_strcmp(tab[0], "exit") == 0)
		exit(my_getnbr(tab[1]));
	if (my_strcmp(tab[0], "cd") == 0) {
		the_cd(tab[1], my_env);
		return (0);
	}
	return (-1);
}

int try_env(char **tab, list_path *my_env)
{
	int	i = count_line(tab);

	if (tab == NULL || my_env == NULL)
		return (0);
	if (i > 1 && my_strcmp(tab[0], "setenv") == 0)
		return (try_setenv(tab, my_env));
	if (my_strcmp(tab[0], "unsetenv") == 0)
		return (try_unsetenv(tab, my_env));
	return (-1);
}
