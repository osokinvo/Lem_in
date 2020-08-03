# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: val <val@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 16:04:00 by ghusk             #+#    #+#              #
#    Updated: 2020/07/30 08:39:06 by val              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
SRC := src/
SRCO := srco/
INC := includes/
include lib_connections
PFO := $(addprefix $(SRCO), $(addsuffix .o, $(PF)))


all:		$(SRCO) $(NAME)

$(NAME):	$(PFO)
	@ar rc $(NAME) $?
	@ranlib $(NAME)
	@echo "$(NAME) completed"
	

$(SRCO)%.o:	$(SRC)%.c
	@gcc -Wall -Wextra -Werror -MD -c -I$(INC) $< -o $@

$(SRCO):
	@mkdir $@

clean:
	@rm -rf $(PFO) $(addprefix $(SRCO),$(addsuffix .d, $(PF)))\
		$(addprefix $(SRCO).,$(addsuffix .d, $(PF))) $(SRCO)
	@echo "libft_2 cleaning completed"

fclean:		clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re:			fclean all

include $(wildcard $(SRCO)*.d)

.PHONY:		all clean fclean re
