/*
** EPITECH PROJECT, 2017
** shell.c
** File description:
** blabla
*/

#include "my.h"
#include "get_next_line.h"
#include "minishell1.h"
#include "printf.h"
#include <sys/types.h>
#include <sys/wait.h>

static int try_build(char **tab, list_path *my_env)
{
	int	ret = 0;

	if (tab == NULL)
		return (0);
	if (my_env == NULL) {
		my_printf_err("%e: Command not found.\n", tab[0]);
		return (0);
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

static char **reset_env(list_path *my_env, char **new_env)
{
	list_path	*temp = my_env;
	int		i = 0;

	while (temp != NULL) {
		temp = temp->next;
		++i;
	}
	new_env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	temp = my_env;
	while (temp != NULL) {
		new_env[i] = temp->name;
		temp = temp->next;
		++i;
	}
	new_env[i] = NULL;
	return (new_env);
}

static int command(list_path *my_env, char **com, char **new_env, char *str)
{
	char	**big_tab = my_path_to_wordtab(str, ';');
	char	**tab;
	int	ret = 0;
	int	i = 0;

	while (big_tab[i]) {
		tab = my_str_to_wordtab(big_tab[i]);
		ret = try_build(tab, my_env);
		if (ret == -1)
			ret = test_path(tab, com, new_env);
		++i;
	}
	return (ret);
}

int shell(list_path *my_env, char **new_env)
{
	char	*path;
	char	**com;
	char	*str;

	while (42) {
		new_env = reset_env(my_env, new_env);
		path = find_path(my_env);
		if (path != NULL)
			com = my_path_to_wordtab(path, ':');
		write(1, "$> ", 3);
		str = get_next_line(0);
		if (str == NULL) {
			my_putstr("exit\n");
			return (0);
		}
		if (str[0] != '\0')
			command(my_env, com, new_env, str);
	}
	return (0);
}
