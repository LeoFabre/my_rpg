/*
** EPITECH PROJECT, 2024
** CPool_Day08_2019
** File description:
** Created by Leo Fabre
*/
#include "my.h"
#include "malloc.h"

int my_char_isalpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
        (c >= 0 && c <= 9)) {
        return 1;
    } else {
        return 0;
    }
}

int get_nb_words(char const *str)
{
    int word_count = 0;
    int char_back = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_isalpha(str[i]) == 0 && char_back == 1) {
            char_back = 0;
            word_count++;
        }
        if (my_char_isalpha(str[i]) == 1)
            char_back = 1;
    }
    return word_count;
}

char **my_str_to_word_array(char const *str)
{
    int temp_ws = 0;
    int nb_words = get_nb_words(str);
    char **arr = malloc(sizeof(char *) * (nb_words + 1));
    int wordcount = 0;

    for (int i = 0; str[i] != '\0';) {
        for (; my_char_isalpha(str[i + temp_ws]) &&
            str[i + temp_ws] != '\0'; temp_ws++);
        if (temp_ws > 0) {
            arr[wordcount] = malloc(sizeof(char) * (temp_ws + 1));
            for (int temp = 0; temp < temp_ws; temp++)
                arr[wordcount][temp] = str[i + temp];
            arr[wordcount][temp_ws] = '\0';
            wordcount++;
            i += temp_ws;
        } else
            i++;
    }
    arr[nb_words + 1] = NULL;
    return arr;
}