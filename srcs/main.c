/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Arthur
*/

#include <stdlib.h>
#include "minishell1.h"

int main(int ac, char *av[], char **env)
{
	list_path	*my_env = init_cl(env);
	char		**new_env = NULL;
	int		i = 1;

	(void) ac;
	(void) av;
	if (my_env == NULL)
		return (84);
	while (env[i]) {
		insert_end(&my_env, env[i]);
		++i;
	}
	return (shell(my_env, new_env));
}
