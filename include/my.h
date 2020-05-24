/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by Leo Fabre
*/
#ifndef MY_H
#define MY_H

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_itoa(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str , char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum (char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr (char const *str);
int my_showmem (char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char const *str);
void my_show_word_array(char **tab);
char *remove_chars_in_str(char *rm, char *str);
char *remove_c_in_str(char *str, char c);
int my_count_char_in_str(char c, char *str);
int my_char_isdelim(char c, char const *delims);
char **my_str_to_word_array_delims(char const *str, char const *delims);
void my_printf(char *, ...);
char *my_strdup(char *str);
int check_flags(char);
void init_fptr(void (**)());
void my_put_unsigned_nbr(unsigned int);
void my_hexa(int);
void my_capitalize_hexa(int);
void my_octal(int);
void my_binary(int);
int my_get_binary(int);
void my_put_pointer_address(unsigned int);
void my_put_octal(char *);
void my_get_octal(int);
void free_array(char **array);

#endif
