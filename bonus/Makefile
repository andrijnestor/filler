# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/09 19:34:27 by anestor           #+#    #+#              #
#    Updated: 2018/05/22 18:51:35 by anestor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= bonus
FLAGS				= -Wall -Wextra -Werror
FWORKS				= $(FWORK) -rpath ./frameworks \
						-framework SDL2 -framework SDL2_image
OBJ_DIR				= obj/
EXT					= bonus.h

SRC					=
SRC					+= main.c
SRC					+= sdl_func.c
SRC					+= read_from_pipe.c
SRC					+= render.c
SRC					+= buttons.c
SRC					+= mouse_hooks.c

OBJ					= $(patsubst %.c,$(OBJ_DIR)%.o,$(SRC))
.SILENT:

LIBFT_DIR			= ../libft/
LIBFT_FLAGS			= -L$(LIBFT_DIR) -lft
LIBFT_INC			= -I$(LIBFT_DIR)

FWORK				= -F ./frameworks

all: $(NAME)

$(NAME): $(OBJ) $(EXT)
	@make -C $(LIBFT_DIR) -j4
	@gcc $(FLAGS) $(LIBFT_FLAGS) $(FWORKS) $(OBJ) -o $(NAME)

obj/%.o: %.c $(EXT)
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -c $< -o $@ $(LIBFT_INC) $(FWORK)
	@echo "... compiling $< ..."

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "... cleaning fdf obj ..."

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "... cleaning $(NAME) ..."

re: fclean all

.PHONY: clean fclean re all test
