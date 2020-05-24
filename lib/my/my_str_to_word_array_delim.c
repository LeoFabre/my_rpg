/*
** EPITECH PROJECT, 2024
** CPool_Day08_2019
** File description:
** Created by Leo Fabre
*/
#include "my.h"
#include "malloc.h"

int my_char_isdelim(char c, char const *delims)
{
    for (int i = 0; delims[i]; ++i) {
        if (c == delims[i]) {
            return 1;
        }
    }
    return 0;
}

int get_nb_words_delims(char const *str, char const *delims)
{
    int word_count = 0;
    int char_back = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_isdelim(str[i], delims) == 0 && char_back == 1) {
            char_back = 0;
            word_count++;
        }
        if (my_char_isdelim(str[i], delims) == 1)
            char_back = 1;
    }

    return word_count;
}

char **my_str_to_word_array_delims(char const *str, char const *delims)
{
    int temp_wrd_len = 0;
    int nb_words = get_nb_words_delims(str, delims);
    char **arr = malloc(sizeof(char *) * (nb_words + 2));
    int wordcount = 0;

    for (int i = 0; str[i] != '\0';) {
        for (temp_wrd_len = 0;
            !my_char_isdelim(str[i + temp_wrd_len], delims) &&
                str[i + temp_wrd_len] != '\0'; temp_wrd_len++);
        if (temp_wrd_len > 0) {
            arr[wordcount] = malloc(sizeof(char) * (temp_wrd_len + 1));
            for (int temp = 0; temp < temp_wrd_len; temp++)
                arr[wordcount][temp] = str[i + temp];
            arr[wordcount][temp_wrd_len] = '\0';
            wordcount++;
            i += temp_wrd_len;
        } else
            i++;
    }
    arr[nb_words] = NULL;
    return arr;
}

void free_array(char **array)
{
    for (int i = 0; array[i]; ++i)
        free(array[i]);
}
