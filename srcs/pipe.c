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

void change_pipe(int in, int out)
{
	if (in != 0) {
		dup2(in, 0);
		close(in);
	}
	if (out != 1) {
		dup2(out, 1);
		close(out);
	}
}

char **my_piping(char *str, char **com, char **new_env, list_path *my_env)
{
	int	fd[2];
	int	save = 0;
	int	i = 0;
	pid_t	child_pid;
	int	nb_pipe = count_pipe(str);
	char	**tab_pipe = my_path_to_wordtab(str, '|');

	while (i != nb_pipe) {
		pipe(fd);
		child_pid = fork();
		if (child_pid == 0) {
			change_pipe(save, fd[1]);
			test_path(my_str_to_wordtab(tab_pipe[i]), com,
			new_env, my_env);
		}
		close(fd[1]);
		save = fd[0];
		++i;
	}
	dup2(save, 0);
	return (my_str_to_wordtab(tab_pipe[i]));
}
