SRCS =	ft_atoi_cub.c \
		ft_error.c \
		ft_get_cub_info.c \
		ft_raycasting.c \
		ft_resolution_and_color.c \
		ft_texture.c \
		get_next_line_utils.c \
		get_next_line.c \
		main.c \
		ft_fencing.c \
		ft_init.c

OBJS_DIR = objs/

LIBFT_A =	libft.a

LIB_DIR = lib/

NAME = Cub3D

MLX_DIR = minilibx-linux

MLX = libmlx.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

SRCS_DIR = srcs/

INC_DIR = include/

OBJS_IN_DIR = $(addprefix $(OBJS_DIR),$(SRCS:.c=.o))

SRCS_IN_DIR = $(addprefix $(SRCS_DIR),$(SRCS))

OBJS = $(SRCS:.c=.o)

all: $(NAME) $(OBJS)

$(NAME): $(OBJS)
		@echo LIBFT START
		@make -C $(LIB_DIR)
		@echo Copying $(LIBFT_A) to root.
		@cp $(LIB_DIR)$(LIBFT_A) .
		${CC} $(CFLAGS) -o $(NAME) $(OBJS_IN_DIR) -L. -lft -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext
		@echo $(NAME) : Created !

$(OBJS):
		@rm -rf $(OBJS_DIR)
		@mkdir $(OBJS_DIR)
		${CC} $(CFLAGS) -I $(INC_DIR) -I $(MLX_DIR) -c $(SRCS_IN_DIR)
		@mv $(OBJS) $(OBJS_DIR)

clean:
		@rm -rf $(OBJS_DIR)
		@echo "objs deleted"

fclean:	clean
		@rm -rf $(NAME)
		@echo "[$(NAME)]: deleted"

 re: fclean all
