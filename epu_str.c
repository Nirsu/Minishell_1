/*
** EPITECH PROJECT, 2018
** epu_str.c
** File description:
** the epu_str !
*/

#include "my.h"

char *epu_str(char *str)
{
	int i = 0;
	int j = 0;
	char *str_2 = malloc(sizeof(char) * my_strlen(str) + 1);

	while (verif_array(str[i]) != 0)
		i++;
	while (str[i] != '\0') {
		while ((str[i] == ' ') && (str[i + 1] == ' ' || (str[i + 1] == '\t')
			|| (str[i] == '\t'))) {
			i++;
		}
		str_2[j++] = str[i++];
	}
	str_2[j] = '\0';
	return(str_2);
}
