NAME		:= minishell
INC			:= $(shell find includes -name "*.h" -exec dirname {} \; | sort -u | sed 's/^/-I /')
SRCS_DIR	:= ./srcs
SRCS		:= $(shell find srcs -name "*.c")
LIBS		= libft/libft.a
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

$(NAME)	: $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lreadline -L $(shell brew --prefix readline)/lib

$(LIBS):
	$(MAKE) -C ./libft

$(OBJS_DIR)/%.o: srcs/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

clean		:
	make -C ./libft clean
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
