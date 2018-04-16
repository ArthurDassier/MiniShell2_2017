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

char *clean_dot(char *str)
{
	char	*tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
	int	j = 0;
	int	space = 1;

	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] != ';') {
			tmp[j] = str[i];
			space = 0;
			++j;
		} else if ((str[i] == ';') && space == 0) {
			tmp[j] = str[i];
			++j;
			space = 1;
		}
	}
	tmp[j] = '\0';
	if (tmp[--j] && tmp[j] == ';')
		tmp[j] = '\0';
	return (tmp);
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

static int my_forking(char *str, char **com,
char **new_env, list_path *my_env)
{
	pid_t	child_pid;
	int	wstatus;
	int	ret = 0;
	int	nb_pipe = count_pipe(str);
	char	**tab = NULL;

	if (nb_pipe == 0)
		tab = my_str_to_wordtab(str);
	else {
		ret = my_piping(str, com, new_env, my_env);
		return (ret);
	}
	child_pid = fork();
	if (child_pid == 0)
		ret = test_path(tab, com, new_env, my_env);
	else
		if (wait(&wstatus) != -1)
			return (error_status(wstatus));
	return (wstatus);
}

static int command(list_path *my_env, char **com, char **new_env, char *str)
{
	char	**big_tab = my_path_to_wordtab(clean_dot(str), ';');
	char	**tab;
	int	ret = 0;
	int	i = 0;

	while (big_tab[i]) {
		tab = my_str_to_wordtab(big_tab[i]);
		ret = try_build(tab, my_env);
		if (ret == -1)
			ret = my_forking(big_tab[i], com, new_env, my_env);
		++i;
	}
	return (ret);
}

int shell(list_path *my_env, char **new_env)
{
	size_t	len = 0;
	char	*path;
	char	**com;
	char	*str = NULL;
	int	ret = 0;

	while (42) {
		str = NULL;
		new_env = reset_env(my_env, new_env);
		path = find_path(my_env);
		if (path != NULL)
			com = my_path_to_wordtab(path, ':');
		write(1, "$> ", 3);
		if (getline(&str, &len, stdin) == -1) {
			my_putstr("exit\n");
			return (ret);
		}
		str[my_strlen(str) - 1] = '\0';
		str = clean_str(str);
		if (str[0] != '\0')
			ret = command(my_env, com, new_env, str);
	}
	return (ret);
}
