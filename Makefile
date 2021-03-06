# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/07 14:17:38 by ccantin      #+#   ##    ##    #+#        #
#    Updated: 2020/01/22 21:26:56 by ccantin     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all re clean fclean libft mlx

NAME = fractol

###############		OS DEFINITION		###############

OS_NAME := $(shell uname)

###############		FLAGS && COMPILER	###############

CC = clang

CC_FLAGS = -Werror -Wall -Wextra -O2 #-fsanitize=address -g

############### 		LIBFT			###############

LIBFT_PATH = libft

LIBFT = $(LIBFT_PATH)/libft.a

###############			MLX				###############

ifeq ($(OS_NAME),Linux)
	MLX_PATH = mlx_x11
	OS_FLAGS = -lXext -lX11 -lm -pthread -lpthread
else
	MLX_PATH = mlx_macos
	OS_FLAGS = -framework OpenGL -framework AppKit
endif

MLX = $(MLX_PATH)/libmlx.a

###############			INCLUDES		###############

INC_PATH =	includes

INC_NAME =	fractol.h 

INCLUDES = -I$(MLX_PATH) -I$(LIBFT_PATH) -I$(INC_PATH)

INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

###############			SRCS			###############

SRCS_PATH = src

SRCS_NAME = bresenham.c \
			complex.c \
			free_handler.c \
			get_color.c \
			init_functions.c \
			init_fract.c \
			julia_sis.c \
			key_handler.c \
			main.c \
			mandel_bro.c \
			move.c \
			mouse_julia.c \
			ship_cuzin.c \
			zoom_handler.c
			

SRCS = $(addprefix $(SRCS_PATH)/,$(SRCS_NAME))

###############			OBJECTS			###############

OBJ_PATH = obj

OBJ = $(addprefix $(OBJ_PATH)/,$(SRCS_NAME:.c=.o))

###############			RULES			###############

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@ $(CC) $(CC_FLAGS) $(OS_FLAGS) -o $@ $(OBJ) $(INCLUDES)  $(LIBFT) $(MLX)
	@ printf "Compilation de %s ✅\n" $@ 

$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c $(INC)
	@ mkdir $(OBJ_PATH) 2> /dev/null || true
	@ $(CC) $(CC_FLAGS) -o $@ -c $< $(INCLUDES)

$(LIBFT):
	 @ make -C $(LIBFT_PATH)
	 @ printf "Compilation de %s ✅\n" $@

$(MLX):
	 @ make -C $(MLX_PATH)
	 @ printf "Compilation de %s ✅\n" $@ 

clean:
	@ /bin/rm -rf $(OBJ_PATH)
	@ make -C $(LIBFT_PATH) clean
	@ printf "Suppression des .o %s ✅\n" $(OBJ_PATH)

fclean: clean
	@ /bin/rm -f $(NAME)
	@ make -C $(MLX_PATH) clean
	@ make -C $(LIBFT_PATH) fclean
	@ printf "Suppression du binaire %s ✅\n" $(NAME)

re: fclean all
