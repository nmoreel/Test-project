NAME 	= workshop

TEST_NAME = test-$(NAME)

CC 		= gcc

SRCS	= ./src/my_putstr.c

SRCS_MAIN = ./src/main.c

SRCS_TEST = ./tests/src/test-putstr.c

OBJS 	:= $(SRCS:.c=.o)

OBJS_MAIN := $(SRCS_MAIN:.c=.o)

OBJS_TEST := $(SRCS_TEST:.c=.o)

BUILD = release

cflags.common := -Wall -Wextra -I./include
cflags.debug := -g3 -O0
cflgas.release := 
cflags.tests := -fprofile-arcs -ftest-coverage

ldflags.common := -lstring -Llib/libstring
ldflags.debug := 
ldflgas.release := 
ldflags.tests := -lcriterion -lgcov

CFLAGS = ${cflags.${BUILD}} ${cflags.common}
LDFLAGS = ${ldflags.${BUILD}} ${ldflags.common}

$(NAME) : $(OBJS) $(OBJS_MAIN)
		make -C lib/libstring
		gcc -o $(NAME) $(OBJS) $(OBJS_MAIN) $(LDFLAGS)

$(TEST_NAME): set_rules	$(OBJS_TEST) $(OBJS)
			make -C lib/libstring
			$(CC) -o $(TEST_NAME) $(OBJS_TEST) $(OBJS) $(LDFLAGS)

all		: 
		make $(NAME)
		make clean
		make $(TEST_NAME)

set_rules :
			$(eval BUILD=tests)
			$(eval CFLAGS=${cflags.tests} $(cflags.common))
			$(eval LDFLAGS=${ldflags.tests} $(ldflags.common))

tests_run : set_rules $(TEST_NAME)
			@./$(TEST_NAME)
			@gcovr

clean	:
		rm -rf $(OBJS)
		rm -rf $(OBJS_MAIN)
		rm -rf $(OBJS_TEST)
		@make -C lib/libstring clean
		find -name "*.gcda" -delete
		find -name "*.gcno" -delete
		find -name "*.gcov" -delete

fclean	: clean
		rm -rf $(NAME)
		rm -rf $(TEST_NAME)
		@make -C lib/libstring clean

re		: fclean all

.c.o:
		@echo Compile $< source file in $(BUILD) mode.
		@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re tests_run
