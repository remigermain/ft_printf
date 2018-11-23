# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/01 15:39:03 by rgermain     #+#   ##    ##    #+#        #
#    Updated: 2018/11/16 09:15:29 by rgermain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #


NAME = ./a.out

//CFLAGS = -Wall -Werror -Wextra

INCLUDE = -Iincludes

CINC = includes/ft_printf.h libft/includes/libft.h

SRC = ft_option_d.c ft_printf.c ft_strjoin.c main.c utils.c ft_params.c ft_option_o.c ft_option_c.c ft_option_s.c ft_option_p.c ft_option_x.c ft_option_u.c ft_option_u2.c ft_option_d2.c ft_option_o2.c ft_option_x2.c

OBJ = $(SRC:.c=.o)

DSRC = src/
DOBJ = obj/

CSRC = $(addprefix $(DSRC),$(SRC))
COBJ = $(addprefix $(DOBJ),$(OBJ))

all: $(NAME)

$(NAME): $(COBJ)
	@echo "Compilation de l'executable" $(NAME)
	@gcc $? libft/libft.a -o $(NAME)

$(DOBJ)%.o : $(DSRC)%.c $(CINC)
	@make -C libft/ all
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
