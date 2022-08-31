# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpaulo-d <jpaulo-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 02:24:12 by jpaulo-d          #+#    #+#              #
#    Updated: 2022/08/30 20:32:20 by jpaulo-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_atoi.c \
			ft_calloc.c \
			ft_free_ptr.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_itoa.c \
			ft_itoa_u.c \
			ft_itoa_base.c \
			ft_itoa_ptr.c \
			ft_memcmp.c \
			ft_memmove.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_split.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcpy.c \
			ft_strmapi.c \
			ft_strnstr.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_putendl_fd.c \
			ft_putstr_fd.c \
			ft_strchr.c \
			ft_striteri.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strrchr.c \
			ft_substr.c \
			ft_toupper.c \
			ft_get_next_line.c

OBJS	=	${SRCS:.c=.o}
NAME	=	libft.a
C_LIB	=	ar rc
S_LIB	=	ranlib
CC		=	gcc
RM		=	rm -f
FLAGS	=	-Wall -Wextra -Werror

.c.o:		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${C_LIB} ${NAME} ${OBJS}
			${S_LIB} ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re 
