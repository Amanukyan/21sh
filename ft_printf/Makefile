# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amanukya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/21 15:25:02 by amanukya          #+#    #+#              #
#    Updated: 2016/04/21 15:25:13 by amanukya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

FILES	= ft_printf.c \
		  parse_tag.c \
		  get_converter.c \
		  converters/convert_int.c \
		  converters/convert_unsigned_int.c \
		  converters/convert_octal.c \
		  converters/convert_hexa.c \
		  converters/convert_char.c \
		  converters/convert_string.c \
		  converters/convert_address.c \
		  converters/convert_escape.c \
		  converters/convert_long.c \
		  converters/convert_wchar.c \
		  converters/convert_wstring.c \
		  converters/convert_binary.c \
		  color.c \
		  utils/print_width_pad.c \
		  utils/nbr_strlen.c \
		  utils/print_forceprefix.c \
		  utils/convert_length.c \
		  utils/print_forceprefix_max.c \
		  utils/print_uint.c

SRC		= $(addprefix srcs/, $(FILES))
OBJ		= $(SRC:.c=.o)

INC     = ./includes
LIBFT	= ./libft/
LIBFTA   = ./libft/libft.a

CC		= gcc

ifdef FLAGS
    ifeq ($(FLAGS), no)
        CFLAGS	= 
    endif
    ifeq ($(FLAGS), debug)
        CFLAGS	= -Wall -Wextra -Werror -g
    endif
else
    CFLAGS      = -Wall -Wextra -Werror
endif

AR      = ar
ARFLAGS = rcs

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp $(LIBFTA) $(NAME)
	@$(AR) r $(NAME) $(OBJ)

%.o: %.c
	@$(CC) -o $@ $(CFLAGS) -I $(INC) -c $<
	@echo "Building: \033[34m$@\033[0m"

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIBFT) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean


re: fclean all
