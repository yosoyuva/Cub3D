# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 13:00:55 by ymehdi            #+#    #+#              #
#    Updated: 2020/06/10 22:03:41 by ymehdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SOURCES = ft_strjoin.c\
		  ft_split.c\
		  ft_putstr_fd.c\
		  ft_strlcat.c\
		  ft_atoi.c\
		  ft_memcpy.c\
		  ft_strlen.c\
		  ft_bzero.c\
		  ft_strchr.c\
		  ft_strtrim.c\
		  ft_isalnum.c\
		  ft_memmove.c\
		  ft_strmapi.c\
		  ft_tolower.c\
		  ft_isalpha.c\
		  ft_memset.c\
		  ft_toupper.c\
		  ft_isascii.c\
		  ft_strncmp.c\
		  ft_isdigit.c\
		  ft_putchar_fd.c\
		  ft_isprint.c\
		  ft_strdup.c\
		  ft_itoa.c\
		  ft_putendl_fd.c\
		  ft_strnstr.c\
		  ft_memccpy.c\
		  ft_putnbr_fd.c\
		  ft_strrchr.c\
		  ft_calloc.c\
		  ft_memchr.c\
		  ft_memcmp.c\
		  ft_strlcpy.c\
		  ft_substr.c\
			ft_strcpy.c\
			ft_strcat.c\
			ft_strncpy.c\
			ft_strnew.c\
			ft_putchar.c\
			ft_strnstr.c\
			ft_strtrim.c\
			ft_itoa_hex.c\
			ft_itoa_hex_m.c\
			ft_itoa_hex_long.c\
			ft_strnew_zero.c\
			ft_strnew_space.c\
			ft_putstr.c\
			ft_strcmp.c\



HEADERS = libft.h

OBJECT = $(SOURCES:.c=.o)

SOURCES_BONUS =	ft_lstadd_front.c\
				ft_lstnew.c\
				ft_lstadd_back.c\
				ft_lstlast.c\
				ft_lstsize.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c\

OBJECT_BONUS = $(SOURCES_BONUS:.c=.o)

$(NAME):
	$(CC) $(FLAGS) -c $(SOURCES)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)

all: $(NAME)

bonus:
	$(CC) $(FLAGS) -c $(SOURCES) $(SOURCES_BONUS)
	ar rc $(NAME) $(OBJECT) $(OBJECT_BONUS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJECT) $(OBJECT_BONUS)

fclean: clean
	rm -fr $(NAME)

re: fclean all
