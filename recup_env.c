/*
** EPITECH PROJECT, 2018
** recup env
** File description:
** recup env minishell
*/

#include "my.h"

char *copy_env(char **envp, int index)
{
	int i = 0;
	int j = 0;
	char *my_env = malloc(sizeof(char *) * my_strlen(envp[index]));

	while (envp[index][i] != '=')
		i++;
	i++;
	while (envp[index][i] != '\0') {
		my_env[j] = envp[index][i];
		j++;
		i++;
	}
	my_env[j] = '\0';
	return (my_env);
}

char *recup_env(char **envp, char *to_find)
{
	int i = 0;
	int index = 0;
	char *compare = malloc(sizeof(char *) * my_strlen(envp[index]));
	char *my_env = NULL;

	compare[0] = '\0';
	while (my_strcmp(compare, to_find) != 0) {
		free(compare);
		compare = malloc(sizeof(char *) * my_strlen(envp[index]));
		for (;envp[index][i] != '='; i++)
			compare[i] = envp[index][i];
		compare[i] = '=';
		compare[i + 1] = '\0';
		index += 1;
		i = 0;
	}
	index = index - 1;
	my_env = malloc(sizeof(char *) * my_strlen(envp[index]));
	my_env = copy_env(envp, index);
	free(compare);
	return (my_env);
}
