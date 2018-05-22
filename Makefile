# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/09 19:34:27 by anestor           #+#    #+#              #
#    Updated: 2018/05/22 19:32:39 by anestor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= anestor.filler
FLAGS				= -Wall -Wextra -Werror
OBJ_DIR				= obj/
BONUS_DIR			= bonus/
EXT					= filler.h

SRC					=
SRC					+= main.c
SRC					+= read.c
SRC					+= check.c
SRC					+= make_result.c

OBJ					= $(patsubst %.c,$(OBJ_DIR)%.o,$(SRC))
.SILENT:

LIBFT_DIR			= libft/
LIBFT_FLAGS			= -L$(LIBFT_DIR) -lft
LIBFT_INC			= -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ) $(EXT)
	@make -C $(LIBFT_DIR) -j4
	@gcc $(FLAGS) $(LIBFT_FLAGS) $(OBJ) -o $(NAME)
	@make -C $(BONUS_DIR)

obj/%.o: %.c $(EXT)
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS)  -c $< -o $@ $(LIBFT_INC)
	@echo "... compiling $< ..."

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(BONUS_DIR) clean
	@echo "... cleaning fdf obj ..."

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(BONUS_DIR) fclean
	@echo "... cleaning $(NAME) ..."

norm:
	norminette *.c
	norminette *.h
	norminette $(BONUS_DIR)*.c
	norminette $(BONUS_DIR)*.h
	norminette $(LIBFT_DIR)*.c
	norminette $(LIBFT_DIR)*.h

re: fclean all

.PHONY: clean fclean re all test
