/*
** EPITECH PROJECT, 2018
** simple_com.c
** File description:
** Arthur
*/

#include "my.h"
#include "get_next_line.h"
#include "minishell1.h"
#include "printf.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

int error_status(int wstatus)
{
	int	ret = wstatus / 256;

	if (WIFSIGNALED(wstatus)) {
		if (WTERMSIG(wstatus) == 11) {
			my_puterror("Segmentation fault\n");
			return (139);
		} else if (WTERMSIG(wstatus) == 8) {
			my_puterror("Floating exception\n");
			return (136);
		}
	}
	return (ret);
}

char *find_path(list_path *my_env)
{
	list_path	*tmp = my_env;

	while (tmp != NULL && my_strncmp(tmp->name, "PATH=", 4) != 0)
		tmp = tmp->next;
	if (tmp == NULL)
		return ("\0");
	return (tmp->name);
}

static int exec(char *order, char **tab, char **new_env)
{
	struct stat	sb;

	if (tab != NULL)
		++tab[0];
	if (stat(order, &sb) == 0 && S_ISDIR(sb.st_mode)) {
		my_putstr(order);
		my_putstr(": Permission denied.\n");
		exit(1);
	} else
		execve(order, tab, new_env);
	return (0);
}

int test_path(char **tab, char **com, char **new_env, list_path *my_env)
{
	int	i = 0;
	int	j = -1;

	if (my_strcmp(tab[0], "env") == 0 ||
	(my_strcmp(tab[0], "setenv") == 0 && count_line(tab) == 1))
		exit(try_env_simple(my_env));
	tab[0] = my_strcat("/", tab[0]);
	while (com[i] != NULL && com[i][0] != '\0') {
		if (i == 0 && com[5])
			com[i] += 5;
		j = access(my_strcat(com[i], tab[0]), F_OK || X_OK);
		if (j == 0)
			return (exec(my_strcat(com[i], tab[0]), tab, new_env));
		++i;
	}
	if (access(++tab[0], F_OK || X_OK) == 0)
		return (exec(tab[0], tab, new_env));
	my_putstr(tab[0]);
	my_putstr(": Command not found.\n");
	exit(1);
}
