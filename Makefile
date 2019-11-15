##
## EPITECH PROJECT, 2019
## my_libc
## File description:
## Makefile
##

NAME	=	my_libc.a
TESTS_NAME	=	my_libc.tests

# Output function
ECHO	=	echo -e
ERROR_COLOR =	sed -E "s/error/`printf "\\e[1;31m"`error`printf "\\e[0m"`/"
WARNING_COLOR = 	sed -E "s/warning/`printf "\\e[1;33m"`warning`printf "\\e[0m"`/"
SED_BOLD	=	sed -E "s/\‘\S*\’/`printf "\\e[1m"`&`printf "\\e[0m"`/g"

# Colors
DEFAULT	=	\e[0m
BOLD	=	\e[1m
BLACK	=	\e[30m
RED	=	\e[31m
GREEN	=	\e[32m
YELLOW	=	\e[33m
BLUE	=	\e[34m
MAGENTA	=	\e[35m
CYAN	=	\e[36m
WHITE	=	\e[37m

# Compile Strings
RE_COMPILE		=	$$'$(BOLD)$(GREEN)[ Recompiled the project ! ]\t$(DEFAULT)'
OK			=	$$'$(BOLD)$(GREEN)[ OK ]\t$(DEFAULT)'
WARNING			=	$$'$(BOLD)$(YELLOW)[ WARNING ]\t$(DEFAULT)'
ERROR			=	$$'$(BOLD)$(RED)[ ERROR ]\t$(DEFAULT)'
CLEAN			=	$$'$(BOLD)$(RED)Removing object files ! [$(OBJ_DIR)]\t$(DEFAULT)'
FCLEAN			=	$$'$(BOLD)$(RED)Removing [$(NAME)] !\t$(DEFAULT)'

# Directories
INC_DIR	=	./include/
SRC_DIR	=	./src/
OBJ_DIR	=	./obj/
TESTS_DIR	=	./tests/

# Object Compile Status
define compile_check
	@$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		$(ECHO) $(ERROR) $$'$(@F)'; \
		cat $@.log | sed -E "s/^/`printf "\\e[1;31m"`>`printf "\\e[0m"`  /" | $(ERROR_COLOR) | $(WARNING_COLOR) | $(SED_BOLD);	\
	elif [ -s $@.log ]; then \
		$(ECHO) $(WARNING) $$'$(@F)'; \
		cat $@.log | sed -E "s/^/`printf "\\e[1;33m"`>`printf "\\e[0m"`  /" | $(ERROR_COLOR) | $(WARNING_COLOR) | $(SED_BOLD);	\
	else \
		$(ECHO) $(OK) $$'$(@F)'; \
		cat $@.log | sed -E "s/^/`printf "\\e[1;32m"`>`printf "\\e[0m"`  /" | $(ERROR_COLOR) | $(WARNING_COLOR) | $(SED_BOLD);	\
	fi
	@$(RM) $@.log;
	@exit $$RESULT
endef

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(call compile_check,$(CC) $(CFLAGS) -c -o $@ $<)

$(TESTS_DIR)%.o : $(TESTS_DIR)%.c
	@mkdir -p $(@D)
	@$(ECHO) -n `printf "\\e[36m"`test: `printf "\\e[0m"`
	$(call compile_check,$(CC) $(CFLAGS) -c -o $@ $<)

# Compile
CC		=	gcc
RM		=	rm -f
SRCS	=	$(wildcard $(SRC_DIR)*.c)
OBJS	=	$(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
TESTS_SRCS	=	$(wildcard $(TESTS_DIR)*.c)
TESTS_OBJS	=	$(TESTS_SRCS:$(TESTS_DIR)%.c=$(TESTS_DIR)%.o)
CFLAGS	+=	-I$(INC_DIR)

all:		$(NAME)

debug:	CFLAGS += -g
debug:	fclean $(NAME)

setup:
	@mkdir -p $(SRC_DIR)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(INC_DIR)

$(NAME):	setup $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@$(call compile_check)

tests_run:	CFLAGS += -fprofile-arcs -ftest-coverage -fPIC -O0
tests_run: fclean $(NAME) $(TESTS_OBJS)
	@$(CC) -o $(TESTS_NAME) $(OBJS) $(TESTS_OBJS) --coverage -lcriterion
	@$(call compile_check)
	@$(ECHO) '\e[1;35m[ RUN ]\e[0m $(TESTS_NAME)'
	@./$(TESTS_NAME)
	@$(ECHO) '\e[1;35m[ RUN ]\e[0m gcovr'
	@gcovr --exclude tests
	@$(RM) $(TESTS_DIR)*.o
	@$(RM) $(TESTS_DIR)*.gcno
	@$(RM) $(TESTS_DIR)*.gcda
	@$(RM) *.gcno
	@$(RM) *.gcda
	@$(RM) $(TESTS_NAME)

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(ECHO) $(CLEAN)

fclean:	clean
	@$(RM) $(NAME)
	@$(ECHO) $(FCLEAN)

re:	fclean all
	@$(ECHO) $(RE_COMPILE)

.PHONY:		all debug setup tests_run tests_clean clean fclean re