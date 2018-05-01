/*
** EPITECH PROJECT, 2018
** str_to_wordtab
** File description:
** mon str_to_wordtab
*/

#include "my.h"

int count_word(char *str)
{
	int i = 0;
	int j = 0;

	while (str[i] != '\0' && str[i] != '\n') {
		if (str[i] == ' ' || str[i + 1] == '\0' || str[i] == ',' || str[i] == ':')
			j++;
		i++;
	}
	return (j);
}

int verif_array(char const str)
{
	if ((str >= 'A' && str <= 'Z') || (str >= 'a' && str <= 'z') || str == '/' || str == '.' || str == '-')
		return (0);
	if (str == ' ' || str == '\t' || str == ',' || str == '\n' || str == '\0')
		return (1);
	return (1);
}

char *my_put_word_into_array(char *tab, int *j, char const *str)
{
	int tmp = 0;
	int a = 0;
	int word = 0;

	for (; verif_array(str[*j]) == 1 && str[*j] != '\0'; (*j)++);
	for (; verif_array(str[*j]) == 0 && str[*j] != '\0'; tmp++, (*j)++);
	tab = malloc(sizeof(char) * tmp + 1);
	if (tab == NULL)
		return (0);
	a = *j - tmp;
	while (a < *j) {
		tab[word] = str[a];
		a++;
		word++;
	}
	tab[word] = '\0';
	return (tab);
}

char **my_str_to_wordtab(char *str)
{
	int i = 0;
	int j = 0;
	char **tab;
	int nbr = count_word(str);

	tab = malloc(sizeof(char*) * (nbr + 1) * 2);

	while (i <= nbr) {
		tab[i] = my_put_word_into_array(tab[i], &j, str);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
