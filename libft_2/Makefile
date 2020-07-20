# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: val <val@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 16:04:00 by ghusk             #+#    #+#              #
#    Updated: 2020/07/08 14:55:05 by val              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
PF := ft_abs\
	  ft_atoi\
	  ft_atoi1\
	  ft_bzero\
	  ft_dellist\
	  ft_is_char\
	  ft_isalnum\
	  ft_isalpha\
	  ft_isalphalowcase\
	  ft_isalphaupercase\
	  ft_isnonprint\
	  ft_isascii\
	  ft_isdigit\
	  ft_isprint\
	  ft_isspace\
	  ft_itoa\
	  ft_free_replace\
	  ft_lstadd\
	  ft_lstdel\
	  ft_lstdelone\
	  ft_lstiter\
	  ft_lstlen\
	  ft_lstmap\
	  ft_lstnew\
	  ft_memalloc\
	  ft_memccpy\
	  ft_memchr\
	  ft_memcmp\
	  ft_memcpy\
	  ft_memdel\
	  ft_memmove\
	  ft_memset\
	  ft_putchar\
	  ft_putchar_fd\
	  ft_putendl\
	  ft_putendl_fd\
	  ft_putnbr\
	  ft_putnbr_fd\
	  ft_putstr\
	  ft_putstr_fd\
	  ft_strcat\
	  ft_strchr\
	  ft_strclr\
	  ft_strcmp\
	  ft_strcpy\
	  ft_strdel\
	  ft_strdup\
	  ft_strequ\
	  ft_striter\
	  ft_striteri\
	  ft_strjoin\
	  ft_strlcat\
	  ft_strlen\
	  ft_strmap\
	  ft_strmapi\
	  ft_strncat\
	  ft_strncmp\
	  ft_strncpy\
	  ft_strnequ\
	  ft_strnew\
	  ft_strnstr\
	  ft_strrchr\
	  ft_strsplit\
	  ft_strstr\
	  ft_strsub\
	  ft_strtol\
	  ft_strtoll\
	  ft_strtoul\
	  ft_strtoull\
	  ft_strtrim\
	  ft_tolower\
	  ft_toupper\
	  get_next_line1\
	  get_next_line\
	  ft_create_list_str_nbr
SRC := src/
SRCO := srco/
INC := includes/
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
