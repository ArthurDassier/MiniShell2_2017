/*
** EPITECH PROJECT, 2017
** minishell1.h
** File description:
** blabla
*/

#ifndef MINI_SHELL_H
#define MINI_SHELL_H

typedef struct s_list_path list_path;

struct s_list_path
{
	char		*name;
	list_path	*next;
};

int shell(list_path *, char **);
list_path *init_cl(char **);
list_path *insert_end(list_path **, char *);
void del_elem_list(list_path **, char *);
char *find_path(list_path *);
int test_path(char **, char **, char **);
void print_list(list_path *);
void my_setenv(char **, list_path *);
void no_tab_setenv(char **, list_path *);
void the_cd(char *, list_path *);
void my_setpath(char *, char *, list_path *);

#endif
