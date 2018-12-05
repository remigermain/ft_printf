# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/01 15:39:03 by rgermain     #+#   ##    ##    #+#        #
#    Updated: 2018/12/05 16:23:21 by rgermain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #


NAME = ./a.out

//CFLAGS = -Wall -Werror -Wextra

INCLUDE = -Iincludes

CINC = includes/ft_printf.h libft/includes/libft.h

SRC = main.c ft_printf.c ft_conv.c utils.c utils2.c utils_print.c\
	  ft_option_d.c ft_option_c.c ft_option_s.c\
	  ft_option_ts.c ft_option_ti.c ft_option_k.c \
	  ft_option_f.c ft_option_fe.c \
	  lst_init.c lst_init2.c lst_initnb.c

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
