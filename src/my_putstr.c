/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** my_putstr
*/

#include "my.h"

void my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}
