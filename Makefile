# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avogt <avogt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/19 18:09:35 by avogt             #+#    #+#              #
#    Updated: 2021/03/19 18:09:36 by avogt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_strlen.s \
ft_strdup.s \
ft_strcmp.s \
ft_strcpy.s \
ft_write.s \
ft_read.s \

OBJS = $(SRCS:.s=.o)
NAME = libasm.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.s
	nasm -f elf64 $<

clean : 
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
