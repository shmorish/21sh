NAME		:= minishell
INC			= $(shell find . -name "*.h" -print0 | xargs -0 -I {} dirname {} | sort -u | sed 's/^/-I /' | tr '\n' ' ')
SRCS_DIR	:= ./srcs
SRCS		:= $(shell find . -name "*.c" | grep -v readline | grep -v libft | tr '\n' ' ')
LIBFT		:= libft/libft.a
LIBREADLINE	:= readline/libreadline.a
LDFLAGS		:= -Llibft -Lreadline
LDLIBS		:=  -lft -lreadline -lncurses
OBJS_DIR	:= ./objs
OBJS		:= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))
DEPS		:= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.d))

CC			:= cc
CFLAGS		= -Wall -Wextra -Werror $(INC) -MMD -MP

# Debug
ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += -DDEBUG
endif

ifeq ($(MAKECMDGOALS), address)
	CFLAGS += -g3 -fsanitize=address
endif

all			: $(NAME)

$(NAME)	: $(LIBFT) $(LIBREADLINE) $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS) $(LDLIBS)

$(LIBFT):
	@git submodule update --init --recursive
	$(MAKE) -C ./libft

$(LIBREADLINE):
	@git submodule update --init --recursive
	cd readline && ./configure -q --prefix=$(PWD)/readline --enable-shared=no && $(MAKE) && $(MAKE) install

$(OBJS_DIR)/%.o: srcs/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	make -C ./libft clean
	$(RM) -r $(OBJS_DIR)

fclean		: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re			: fclean all

debug		: re

address		: re

help		: Makefile
	@echo "Usage: make [target]"
	@echo ""
	@echo "Targets:"
	@echo "  all		- build $(NAME)"
	@echo "  clean		- remove object files"
	@echo "  fclean	- remove object files and $(NAME)"
	@echo "  re		- remove object files and $(NAME) then build"
	@echo "  debug		- build $(NAME) with debug flag"
	@echo "  help		- show this help"

.PHONY		: all clean fclean re debug address help

-include $(DEPS)
