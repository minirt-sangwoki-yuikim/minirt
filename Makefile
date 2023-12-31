

CC = cc
CFLAGS = -Wextra -Werror -Wall
LINKING_FLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit

NAME = miniRT
SRCS = ./color/mlx_color.c \
		./color/mlx_func.c \
		./color/mlx_draw.c \
		./parsing/__init__.c \
		./parsing/error_handle.c \
		./parsing/extract.c \
		./parsing/extract2.c \
		./parsing/format_check.c \
		./parsing/ft_math.c \
		./parsing/ft_split_group.c \
		./parsing/ft_split.c \
		./parsing/utility.c \
		./parsing/utility2.c \
		./parsing/cylinder.c \
		./parsing/parsing.c \
		./setting/check_hit.c \
		./setting/check_hit2.c \
		./setting/check_world_hit.c \
		./setting/view.c \
		./utils/color.c \
		./utils/equation.c \
		./utils/geometry.c \
		./utils/max_func.c \
		./utils/min_func.c \
		./utils/ray.c \
		./utils/vector.c \
		./utils/vector2.c \
		./utils/vector3.c \
		./tracing/ray_color.c \
		./tracing/phong_lighting.c \
		./main.c \

OBJS = $(SRCS:.c=.o)
INCS = ./color/mlx_utility.h \
		./parsing/__init__.h \
		./parsing/parsing.h \
		./setting/view.h \
		./utils/ray.h \
		./utils/utils.h

all : $(NAME)
$(NAME) : $(OBJS)
	make -C mlx all
	$(CC) $(CFLAGS) $^ $(LINKING_FLAGS) -o $@
%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
clean :
	make -C mlx clean
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY: all re fclean clean