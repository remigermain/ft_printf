# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/01 15:39:03 by rgermain     #+#   ##    ##    #+#        #
#    Updated: 2018/12/19 23:02:17 by rgermain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = ./a.out

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -Iincludes

CINC = includes/ft_printf.h libft/includes/libft.h includes/color.h

SRC = main.c ft_printf.c find_conv.c \
		conv_int.c conv_char.c conv_double.c conv_string.c \
		conv_tabstring.c conv_other.c \
		lst_init.c lst_putint.c lst_putdouble.c lst_putoption.c \
		utils.c malloc_string.c put_color.c \
		debug.c

OBJ = $(SRC:.c=.o)

DSRC = src/
DOBJ = obj/

CSRC = $(addprefix $(DSRC),$(SRC))
COBJ = $(addprefix $(DOBJ),$(OBJ))

all: $(NAME)

$(NAME): $(COBJ)
	@make -C libft/ all
	@echo "Compilation de l'executable" $(NAME)
	@gcc $? libft/libft.a -o $(NAME)

$(DOBJ)%.o : $(DSRC)%.c $(CINC)
	@mkdir -p $(DOBJ)
	@gcc $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "Compilation de la fonction "$<

clean:
	@mkdir -p $(DOBJ)
	@rm -rf $(DOBJ)
	@make -C libft clean
	@echo "Suppresion des objects"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@echo "Suppresion de la library "$(NAME)

re: fclean all

.PHONY: all clean fclean
