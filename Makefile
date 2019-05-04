# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/27 15:44:23 by vapiatko          #+#    #+#              #
#    Updated: 2019/05/03 17:55:29 by apelissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = doom-nukem

SRCDIR = srcs/

SRCNAMES =  expose_hook.c \
			get_grid.c \
			get_map.c \
			get_perso.c \
			get_view.c \
			key_hook.c \
			main.c \
			utils.c\
			raycast.c\
			get_textures.c\
			get_objects.c\
			init_sdl.c\
			mouse_hook.c\
			print_hud.c\
			print_torch.c\
			is_wall.c\
			init_raycast.c\
			find_height.c\
			build_text.c\
			init_search_impacts.c\
			print_wall.c\
			wall_type.c\
			skybox.c\
			multi_thread.c\
			draw_player.c\
			make_co.c\
			print_sprite.c\
			ch_cl_bl.c\
			editeur/main.c\
			editeur/draw1.c\
			editeur/draw2.c\
			editeur/draw3.c\
			editeur/map.c\
			editeur/mouse_event.c\
			editeur/exit.c\




INC = include/
SRC = $(addprefix $(SRCDIR), $(SRCNAMES))
OBJ = $(patsubst %.c,%.o, $(SRC))

LIBDIR = Libft/
LIBFT = Libft/libft.a
LIBINC = Libft/libft.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SDLFLAGS = ~/Library/Frameworks/SDL2.framework/Versions/A/Headers
FRAMEWKRS = ~/Library/Frameworks/ -framework SDL2
RM = rm -f
SANI = -fsanitize=address -g3

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) $(CFLAGS) -o $(NAME) -I $(SDLFLAGS) -F $(FRAMEWKRS) $(SRC) $(LIBFT)
	@echo "\033[0;32m[OK] \033[0m\033[0;33m Binary Has been Created:\033[0m " $@

clean:
	@make -C libft clean
	@echo "\033[0;32m[OK] \033[0m\033[0;33m :\033[0m " $@
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@echo "\033[0;32m[OK] \033[0m\033[0;33m :\033[0m " $@
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
