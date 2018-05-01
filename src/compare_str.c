/*
** EPITECH PROJECT, 2018
** compare_str
** File description:
** un compare str
*/

#include "my.h"

int my_strcmp(char *str, char *verif)
{
	int i = 0;

	if (my_strlen(str) != my_strlen(verif))
		return (2);
	while (str[i] != '\0') {
		if (str[i] != verif[i])
			return (2);
		i++;
	}
	return (0);
}
