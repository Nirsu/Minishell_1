/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** lib_header
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>

int my_strlen(char const *);
int my_getnbr(char const *str);
int my_strcmp(char *str, char *verif);
int verif_command(char *command, char **envp, char *path);

void my_putstr(char *str);
void my_putchar(char c);
void puts_env(char **envp);
void catch_seg(char *command, int pid);

char *my_get_next_line(int fd);
char *recup_env(char **envp, char *to_find);
char *exec_command(char *command, char *path, char **envp, int pid);
char *my_str_concast(char *str1, char *str2);
char *my_cd(char **command_tab);
char *epu_str(char *str);
int verif_array(char const str);

char **my_str_to_wordtab(char *str);

#endif /* !MY_H_ */
