NAME		:= minishell

# SOURCES
SRCS_DIR	:= ./srcs
SRCS		:= $(shell find ./srcs -name "*.c" | grep -v readline | grep -v libft | tr '\n' ' ')
TESTS_DIR	:= ./tests
TEST_SRCS	:= $(shell find ./tests -name "*.cpp" | tr '\n' ' ')

# OBJECTS
OBJS_DIR	:= ./objs
OBJS			:= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))
TEST_OBJS	:= $(subst $(TESTS_DIR), $(OBJS_DIR)/tests, $(TEST_SRCS:.cpp=.o)) $(filter-out $(OBJS_DIR)/main.o, $(OBJS))
DEPS			:= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.d))

# LIBRARIES
LIBFT		:= libft/libft.a
LIBREADLINE	:= readline/libreadline.a
LIBCPPUTEST := cpputest/lib/libCppUTest.a cpputest/lib/libCppUTestExt.a

# LINKER
INC			= -I ./includes/ -I ./libft/include -I ./readline/include -I ./cpputest/include
LDFLAGS		:= -Llibft -Lreadline
LDLIBS		:= -lft -lreadline -lncurses
TEST_LDFLAGS 	:= $(LDFLAGS) -Lcpputest/lib
TEST_LDLIBS		:= $(LDLIBS) -lCppUTest -lCppUTestExt

# COMPILER
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

$(LIBCPPUTEST):
	@git submodule update --init --recursive
	cd cpputest &&  autoreconf . -i && ./configure && $(MAKE) tdd

$(OBJS_DIR)/%.o: srcs/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/tests/%.o: $(TESTS_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CFLAGS) -c $< -o $@

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

test: $(LIBCPPUTEST) $(LIBFT) $(LIBREADLINE) $(TEST_OBJS)
	$(CXX) $(CFLAGS) -o test $(TEST_OBJS) $(TEST_LDFLAGS) $(TEST_LDLIBS)

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
