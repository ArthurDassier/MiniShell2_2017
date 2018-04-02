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

int error_status(int wstatus)
{
	if (WIFSIGNALED(wstatus)) {
		if (WTERMSIG(wstatus))
			my_puterror("Segmentation fault\n");
		return (1);
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
	pid_t	child_pid;
	int	wstatus;

	if (tab != NULL)
		++tab[0];
	child_pid = fork();
	if (child_pid == 0) {
		execve(order, tab, new_env);
	} else
		if (wait(&wstatus) != -1)
			return (error_status(wstatus));
	return (0);
}

int test_path(char **tab, char **com, char **new_env)
{
	int	i = 0;
	int	j = -1;

	tab[0] = my_strcat("/", tab[0]);
	while (com[i] != NULL) {
		j = access(my_strcat(com[i], tab[0]), F_OK || X_OK);
		if (j == 0)
			return (exec(my_strcat(com[i], tab[0]), tab, new_env));
		++i;
	}
	if (access(++tab[0], F_OK || X_OK) == 0)
		return (exec(tab[0], tab, new_env));
	my_printf_err("%e: Command not found.\n", tab[0]);
	return (1);
}
