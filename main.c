/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main minishell_1
*/

#include "my.h"

void catch_seg(char *command, int pid)
{
	int status = 0;
	char **new_command = my_str_to_wordtab(command);

	if (pid == 0) {
		execve(new_command[0], new_command, NULL);
		wait(0);
	}
	if (waitpid(pid, &status, WCONTINUED | WUNTRACED) == -1)
		exit(84);
	if (WIFSIGNALED(status)) {
		if (WCOREDUMP(status)) {
			my_putstr("Segmentation fault (core dumped)\n");
		}
		else {
			my_putstr("Segmentation fault\n");
		}
	}
}

int minishell(char **envp)
{
	char *command = "\0";
	char *path = recup_env(envp, "PATH=");
	int pid = 0;

	while (my_strcmp(command, "exit") != 0) {
		my_putstr("Meru $> ");
		command = my_get_next_line(0);
		if (command == NULL)
			return (84);
		command = epu_str(command);
		if (command[0] == '.') {
			if ((pid = fork()) == -1)
				return (84);
			else
				catch_seg(command, pid);
		}
		else
			if (verif_command(command, envp, path) == 84)
				return (84);
	}
	return (0);
}

int main(int ac, char **av, char **envp)
{
	(void) ac;
	(void) av;
	if (envp[0] == NULL) {
		write(2, "No 'env'", 9);
		return (84);
	}
	else
		minishell(envp);
	return (0);
}
