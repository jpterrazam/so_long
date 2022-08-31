LIBFT_PATH		=	./libs/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./libs/minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_DIR		=	.
OBJ_DIR			=	objects

SOURCES_FILES	=	so_long.c \
					init.c \
					init_utils.c \
					utils.c \
					map.c \
					map_check.c \
					press_key.c \
					exit_free.c

HEADER			=	$(SOURCES_DIR)/so_long.h
SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
OBJECTS			=	$(SOURCES:$(SOURCES_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME			=	so_long

CC				=	cc
RM				=	rm -rf

CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-L. -lXext -L. -lX11

$(OBJ_DIR)/%.o:		$(SOURCES_DIR)/%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJ_DIR) $(MINILIBX) $(OBJECTS) $(HEADER)
					$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) \
					$(MLXFLAGS) -o $(NAME)

$(LIBFT):
					$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
					$(MAKE) -C $(MINILIBX_PATH)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(MAKE) -C $(LIBFT_PATH) clean
					$(MAKE) -C $(MINILIBX_PATH) clean
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(MAKE) -C $(LIBFT_PATH) fclean
					$(RM) $(NAME) $(NAME_BONUS)

re:					fclean all

.PHONY:				all clean fclean re
