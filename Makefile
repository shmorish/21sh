NAME		:= minishell
INC			:= $(shell find includes -name "*.h" -exec dirname {} \; | sort -u | sed 's/^/-I /')
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
CFLAGS		:= -Wall -Wextra -Werror $(INC) -MMD -MP
CFLAGS		+= -I $(shell brew --prefix readline)/include

# Debug
ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += -DDEBUG
endif

ifeq ($(MAKECMDGOALS), address)
	CFLAGS += -g3 -fsanitize=address
endif

all			: $(NAME)

$(NAME)	: $(OBJS) $(LIBS) $(LIBFT) $(LIBREADLINE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS) $(LDLIBS)

$(LIBFT):
	@git submodule update --init --recursive
	$(MAKE) -C ./libft

$(LIBREADLINE):
	@git submodule update --init --recursive
	cd readline && ./configure > /dev/null
	$(MAKE) -C ./readline

$(OBJS_DIR)/%.o: srcs/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

clean		:
	make -C ./libft clean
	make -C ./readline clean
	$(RM) -r $(OBJS_DIR)

fclean		: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re			: fclean all

debug		: re

address		: re

norm		:
	norminette srcs includes

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
