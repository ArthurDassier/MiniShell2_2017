/*
** EPITECH PROJECT, 2018
** cd_build.c
** File description:
** Arthur
*/

#include "my.h"
#include "minishell1.h"
#include "printf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static char *go_home(list_path *my_env)
{
	list_path	*tmp = my_env;
	char		*str = malloc(sizeof(char) * 1024);
	int		i = 5;
	int		j = 0;

	while (tmp != NULL && my_strncmp(tmp->name, "HOME=", 4) != 0)
		tmp = tmp->next;
	while (tmp->name[i] != '\0') {
		str[j] = tmp->name[i];
		++i;
		++j;
		str[j] = '\0';
		str = my_realloc(str);
	}
	str[j] = '\0';
	return (str);
}

static char *go_old(list_path *my_env)
{
	list_path	*tmp = my_env;
	char		*str = malloc(sizeof(char) * 1024);
	int		i = 7;
	int		j = 0;

	while (tmp != NULL && my_strncmp(tmp->name, "OLDPWD=", 6) != 0)
		tmp = tmp->next;
	while (tmp->name[i] != '\0') {
		str[j] = tmp->name[i];
		++i;
		++j;
		str[j] = '\0';
		str = my_realloc(str);
	}
	str[j] = '\0';
	return (str);
}

void the_cd(char *tab, list_path *my_env)
{
	char	*path = tab;
	char	*old_pwd = NULL;

	old_pwd = getcwd(old_pwd, 0);
	if (tab == NULL || tab[0] == '~') {
		path = go_home(my_env);
		chdir(path);
	}
	else if (chdir(path) == -1 && tab[0] != '-') {
		if (open(path,  O_RDONLY) < 0) {
			my_putstr(tab);
			my_putstr(": No such file or directory.\n");
		} else {
			my_putstr(tab);
			my_putstr("Not a directory.\n");
		}
		return;
	}
	else if (tab[0] == '-')
		chdir(go_old(my_env));
	path = NULL;
	my_setpath("OLDPWD", old_pwd, my_env);
	my_setpath("PWD", getcwd(path, 0), my_env);
}
