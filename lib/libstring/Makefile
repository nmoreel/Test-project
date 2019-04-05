NAME 	= libstring.a

TEST_NAME = test-libstring

CC 		= gcc

SRCS	= ./srcs/epurstr.c \
		./srcs/my_cpy.c \
		./srcs/my_getnbr_base.c \
		./srcs/my_str_to_wordtab.c \
		./srcs/my_strdup.c \
		./srcs/my_strlen.c \
		./srcs/my_strndup.c

SRCS_TEST = ./tests/src/test-strcpy.c \
			./tests/src/test-strncpy.c \
			./tests/src/test-strdup.c \
			./tests/src/test-strndup.c \
			./tests/src/test-strlen.c

OBJS 	:= $(SRCS:.c=.o)

OBJS_TEST := $(SRCS_TEST:.c=.o)

BUILD = release

cflags.common := -Wall -Wextra -I./include -I./tests/lib/include
cflags.debug := -g3 -O0
cflgas.release := 
cflags.tests := -fprofile-arcs -ftest-coverage 

ldflags.common := 
ldflags.debug := 
ldflgas.release := 
ldflags.tests := -lcriterion -lgcov -lmimick -L./tests/lib/

CFLAGS = ${cflags.${BUILD}} ${cflags.common}
LDFLAGS = ${ldflags.${BUILD}} ${ldflags.common}

$(NAME) : $(OBJS)
		ar rc $(NAME) $(OBJS)

set_rules :
			$(eval BUILD=tests)
			$(eval CFLAGS=${cflags.tests} $(cflags.common))
			$(eval LDFLAGS=${ldflags.tests} $(ldflags.common))

$(TEST_NAME): $(OBJS_TEST) set_rules $(OBJS)
			$(CC) -o $(TEST_NAME) $(OBJS_TEST) $(OBJS) $(LDFLAGS)

tests_run : $(TEST_NAME)
			@./$(TEST_NAME)
			@gcovr

all		: $(NAME)

clean	:
		rm -rf $(OBJS)
		rm -rf $(OBJS_TEST)
		find -name "*.gcda" -delete
		find -name "*.gcno" -delete
		find -name "*.gcov" -delete

fclean	: clean
		rm -rf $(NAME)
		rm -rf $(TEST_NAME)

re		: fclean all

.c.o:
		@echo Compile $< source file in $(BUILD) mode.
		@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re tests_run
