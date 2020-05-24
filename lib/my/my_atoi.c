/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** Leo Fabre
*/
#include "my.h"

int my_atoi(char const *str)
{
    int nbr = 0;
    int count = 0;

    while (str[count] == ' ' && str[count] != '\0') {
        count++;
    }
    while (my_isnum(str[count]) == 0 && str[count] != '\0') {
        nbr = (nbr * 10) + (str[count] - '0');
        count++;
    }
    return (nbr);
}
