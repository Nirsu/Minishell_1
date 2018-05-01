/*
** EPITECH PROJECT, 2018
** my_str_concast.c
** File description:
** un str concast
*/

#include "my.h"

char *my_str_concast(char *str1, char *str2)
{
	char *str3 = malloc(sizeof(char *) * my_strlen(str1) + my_strlen(str2));
	int i = 0;
	int j = 0;

	while (str1[i] != '\0') {
		str3[j] = str1[i];
		j++;
		i++;
	}
	i = 0;
	while (str2[i] != '\0') {
		str3[j] = str2[i];
		i++;
		j++;
	}
	str3[j] = '\0';
	return (str3);
}
