# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/01 15:39:03 by rgermain     #+#   ##    ##    #+#        #
#    Updated: 2018/11/26 18:52:14 by rgermain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #


NAME = libftprintf.a

//CFLAGS = -Wall -Werror -Wextra

INCLUDE = -Iincludes

CINC = includes/ft_printf.h libft/includes/libft.h

SRC = main.c ft_conv.c ft_option_lo.c ft_option_o.c ft_option_x.c utils.c \
	ft_option_c.c ft_option_lu.c ft_option_p.c ft_option_xmaj.c utils2.c \
	ft_option_d.c ft_option_lx.c ft_option_s.c ft_printf.c utils3.c \
	ft_option_ld.c ft_option_lxmaj.c ft_option_u.c ft_option_cmaj.c \
	ft_option_lld.c ft_option_llo.c ft_option_llx.c ft_option_llxmaj.c ft_option_llu.c \
	ft_printcolor.c ft_option_no.c

OBJ = $(SRC:.c=.o)

DSRC = src/
DOBJ = obj/

CSRC = $(addprefix $(DSRC),$(SRC))
COBJ = $(addprefix $(DOBJ),$(OBJ))

all: $(NAME)

$(NAME): $(COBJ)
	@echo "Compilation de l'executable" $(NAME)
	@ar ru $(NAME) $? libft/obj/*.o
	@ranlib $(NAME)

$(DOBJ)%.o : $(DSRC)%.c $(CINC)
	@make -C libft/ all
	@mkdir -p $(DOBJ)
	@gcc $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "Compilation de la fonction "$<

clean:
	@make -C libft/ clean
	@mkdir -p $(DOBJ)
	@rm -rf $(DOBJ)
	@echo "Suppresion des objects"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "Suppresion de la library "$(NAME)

re: fclean all

.PHONY: all clean fclean re
