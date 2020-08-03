# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: val <val@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 20:05:42 by ghusk             #+#    #+#              #
#    Updated: 2020/08/02 18:57:27 by val              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := lem_in
CC := gcc -Wall -Wextra -O2 -g
LIBD := libft_2/
LIB := $(LIBD)libft.a
FP :=	file\
		ft_del_crossing\
		ft_error\
		ft_find_path\
		ft_list_hesh\
		ft_path\
		ft_print_paths\
		ft_storage\
		lem_in2\
		lem_in 

SRC := src/

SRCO := srco/

INC :=	-I $(LIBD)includes/\
		-I includes/

FPO := $(addprefix $(SRCO), $(addsuffix .o, $(FP)))

all:	$(SRCO) $(NAME)

$(NAME):	$(FPO) $(LIB)
	@$(CC) $^ $(INC) -o $(NAME)
	@echo $(NAME) "completed"


$(SRCO)%.o:	$(SRC)%.c
	@$(CC) -MD -c $< $(INC) -o $@

$(SRCO):
	@mkdir $@

$(LIB):	$(LIBD)\
		$(addprefix $(LIBD)$(SRC), $(addsuffix .c, $(PF)))\
		$(addprefix $(LIBD)$(SRCO), $(addsuffix .o, $(PF)))
	@$(MAKE) -sC $(LIBD)

clean:
	@$(MAKE) -sC $(LIBD) clean
	@rm -rf $(SRCO)
	@echo "push_swap directory cleaning completed"

fclean:		clean
	@$(MAKE) -sC $(LIBD) fclean
	@rm -f $(NAME)
	@echo $(NAME)" deleted"

re:			fclean all

include $(wildcard $(SRCO)*.d)\
		$(LIBD)lib_connections\
		$(wildcard $(LIBD)$(SRCO)*.d)

.PHONY:		all clean fclean re
