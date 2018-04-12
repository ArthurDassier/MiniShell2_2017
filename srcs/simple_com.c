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
	if (WIFSIGNALED(wstatus)) {
		if (WTERMSIG(wstatus))
			my_puterror("Segmentation fault\n");
		return (139);
	}
	return (0);
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
		my_printf("%s: Permission denied.\n", order);
		exit(0);
	} else
		execve(order, tab, new_env);
	return (0);
}

int test_path(char **tab, char **com, char **new_env, list_path *my_env)
{
	int	i = 0;
	int	j = -1;

	if (my_strcmp(tab[0], "env") == 0 ||
	(my_strcmp(tab[0], "setenv") == 0 && !tab[1]))
		exit(try_env_simple(my_env));
	tab[0] = my_strcat("/", tab[0]);
	while (com[i] != NULL) {
		if (i == 0 && com[5])
			com[i] += 5;
		j = access(my_strcat(com[i], tab[0]), F_OK || X_OK);
		if (j == 0)
			return (exec(my_strcat(com[i], tab[0]), tab, new_env));
		++i;
	}
	if (access(++tab[0], F_OK || X_OK) == 0)
		return (exec(tab[0], tab, new_env));
	my_printf("%s: Command not found.\n", tab[0]);
	exit(1);
}
