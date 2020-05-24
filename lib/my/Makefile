##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	my_getnbr.c \
		my_isneg.c \
		my_revstr.c \
		my_putchar.c \
		my_putstr.c \
		my_put_nbr.c \
		my_sort_int_array.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
		my_strcapitalize.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strlowcase.c \
		my_strncmp.c \
		my_itoa.c		\
		my_strncpy.c \
		my_strlen.c \
		my_strupcase.c \
		my_swap.c \
		my_strcat.c \
		my_strncat.c \
		check_flags.c \
		init_fptr.c \
		my_binary.c \
		my_capitalize_hexa.c \
		my_hexa.c \
		my_octal.c \
		my_printf.c \
		my_put_octal.c \
		my_put_pointer_address.c \
		my_put_unsigned_nbr.c \
		my_remove_char_in_str.c \
		my_str_to_word_array.c \
		my_str_to_word_array_delim.c \
		my_strdup.c					\
		my_show_word_array.c \

NAME	=	libmy.a

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I ../../include/

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
	rm 	-f 	$(NAME)

re:	fclean	all
