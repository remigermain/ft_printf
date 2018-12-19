# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/01 15:39:03 by rgermain     #+#   ##    ##    #+#        #
#    Updated: 2018/12/19 18:47:43 by rgermain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #


NAME = ./a.out

//CFLAGS = -Wall -Werror -Wextra

INCLUDE = -Iincludes

CINC = includes/ft_printf.h libft/includes/libft.h

SRC = main.c ft_printf.c ft_conv.c utils.c utils2.c utils3.c utils_print.c\
	  ft_params_nb.c ft_params_char.c ft_params_string.c \
	  ft_params_f.c ft_params_k.c ft_params_ti.c ft_params_ts.c \
	  ft_params_a.c ft_params_lstring.c \
	  lst_init.c lst_init2.c lst_initnb.c \
	  debug.c \
	  ft_atoi2.c

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
	@echo "Suppresion des objects"

fclean: clean
	@rm -f $(NAME)
	@echo "Suppresion de la library "$(NAME)

.PHONY: all clean fclean
