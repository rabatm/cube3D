# Colors
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m

NAME = cub3d
MINILIBX = minilibx

# Dossiers
SRCDIR = src
OBJDIR = obj
INCLUDEDIR = includes
LIBFTDIR = lib/libft
LIBMINIDIR_ORIGIN = lib/minilibx

# Compilateur et options
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra

MACFLY =  -lXext -lX11 -lm -lbsd
# Noms des fichiers
LIBFT = $(LIBFTDIR)/libft.a
LIBMINI = $(LIBMINIDIR_ORIGIN)/libmlx.a lib/minilibx/libmlx_Linux.a


# Fichiers sources et objets
SRC = $(wildcard $(SRCDIR)/*.c $(SRCDIR)/utils/*.c $(SRCDIR)/map/*.c $(SRCDIR)/parsing/*.c)
OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(SRC)))

# Règle de compilation des fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(shell mkdir -p $(OBJDIR))
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/utils/%.c
	$(shell mkdir -p $(OBJDIR))
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/map/%.c
	$(shell mkdir -p $(OBJDIR))
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/parsing/%.c
	$(shell mkdir -p $(OBJDIR))
	$(CC) $(CFLAGS) -c $< -o $@

# Règle par défaut
all: $(NAME)

# Règle de construction de l'exécutable
$(NAME): $(LIBMINI) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMINI) $(MACFLY) -o $(NAME)
	@echo "$(BLUE)$(NAME) READY IN BIN FOLDER$(DEF_COLOR)"

# Règle de construction de la bibliothèque libft.a
$(LIBFT):
	$(MAKE) -sC $(LIBFTDIR) all
	@echo "$(YELLOW)LIBFT COMPILED$(DEF_COLOR)"

$(LIBMINI):
	$(MAKE) -C $(LIBMINIDIR_ORIGIN)
	@echo "$(GREEN)LIBMINI COMPILED$(DEF_COLOR)"

# Règle de nettoyage des fichiers objets
clean:
	$(MAKE) clean -sC $(LIBFTDIR)
	$(MAKE) clean -sC $(LIBMINIDIR_ORIGIN)
	rm -rf $(OBJDIR)
	@echo "$(BLUE)cleaned!$(DEF_COLOR)"

# Règle de nettoyage complet
fclean: clean
	#$(MAKE) fclean -sC $(LIBFTDIR)
	rm -f $(NAME)
	@echo "$(RED)cleaned!$(DEF_COLOR)"

# Règle de recompilation complète
re: fclean all

.PHONY: all clean fclean re