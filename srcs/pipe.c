/*
** EPITECH PROJECT, 2018
** pipe.c
** File description:
** Arthur
*/

#include "minishell1.h"
#include "printf.h"
#include <sys/wait.h>

int count_pipe(char *str)
{
	int	i = 0;
	int	j = 0;

	while (str[i] != '\0') {
		if (str[i] == '|')
			++j;
		++i;
	}
	return (j);
}

int my_piping(char *str, char **com, char **new_env, list_path *my_env)
{
	int	fd[2];
	int	save = 1;
	int	wstatus;
	pid_t	child_pid;
	int	nb_pipe = count_pipe(str);
	char	**tab_pipe = my_path_to_wordtab(str, '|');

	for (int i = 0; i != nb_pipe + 1; ++i) {
		pipe(fd);
		child_pid = fork();
		if (child_pid == 0) {
			dup2(save, 0);
			if (i < nb_pipe)
				dup2(fd[1], 1);
			test_path(my_str_to_wordtab(tab_pipe[i]), com,
			new_env, my_env);
		} else
			if (wait(&wstatus) != -1)
				return (error_status(wstatus));
		close(fd[1]);
		save = fd[0];
	}
	return (wstatus);
}
