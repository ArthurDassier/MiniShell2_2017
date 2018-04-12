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
int test_path(char **, char **, char **, list_path *);
void print_list(list_path *);
int my_setenv(char **, list_path *);
void my_setpath(char *, char *, list_path *);
int error_status(int);

int try_env(char **, list_path *);
int no_tab_setenv(char **, list_path *);
void the_cd(char *, list_path *);
int try_build(char **, list_path *);
int try_setenv(char **, list_path *);
int try_unsetenv(char **, list_path *);
int try_env_simple(list_path *);

int count_pipe(char *);
void my_piping(char *, char **, char **, list_path *);

#endif
