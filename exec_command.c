/*
** EPITECH PROJECT, 2018
** exec_command.c
** File description:
** execute command minishell
*/

#include "my.h"

void puts_env(char **envp)
{
	for (int j = 0; envp[j] != NULL; j++) {
		my_putstr(envp[j]);
		my_putstr("\n");
	}
}

int count_size_tab(char **tab)
{
	int j = 0;

	for(;tab[j] != NULL;j++);
	return (j);
}

int verif_command(char *command, char **envp, char *path)
{
	char **command_tab = my_str_to_wordtab(command);
	int pid = 0;

	if (my_strcmp(command_tab[0], "cd") == 0)
		my_cd(command_tab);
	else if (my_strcmp(command_tab[0], "env") == 0)
		puts_env(envp);
	else if (my_strcmp(command_tab[0], "setenv") == 0)
		puts_env(envp);
	else if ((pid = fork()) == -1)
		return (84);
	else
		exec_command(command, path, envp, pid);
	return (0);
}

char *my_cd(char **command_tab)
{
	if (chdir(command_tab[1]) == -1) {
		my_putstr(command_tab[1]);
		write(2, ": No such file or directory.\n", my_strlen(": No such file or directory.\n"));
		return ("echec");
	}
	my_putstr("\n");
	return ("succes");
}

char *exec_command(char *command, char *path, char **envp, int pid)
{
	char **new_path = my_str_to_wordtab(path);
	char **new_command = my_str_to_wordtab(command);
	int size = count_size_tab(new_command);
	int i = 0;
	int return_execve = 0;
	char *filename = my_str_concast(new_path[i], "/");

	new_command[size - 1] = NULL;
	if (my_strcmp(command, "exit") == 0)
		return (NULL);

	if (pid == 0) {
		while (new_path[i]) {
			filename = my_str_concast(new_path[i], "/");
			filename = my_str_concast(filename, new_command[0]);
			return_execve = execve(filename, new_command, envp);
			i++;
		}
		if (return_execve == -1) {
			write(2, command, my_strlen(command));
			write(2, ": Command not found.\n", my_strlen(": Command not found.\n"));
		}
		exit(0);
	}
	wait(0);
	return (NULL);
}
