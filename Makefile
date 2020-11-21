##
## EPITECH PROJECT, 2020
## OOP_nanotekspice_2019
## File description:
## Makefile
##

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
LINE_RETURN	=	$(ECHO) ""

NAME	=	nanotekspice

TESTS_DIR	=	tests

SRC	=	src/components/True.cpp	\
		src/components/False.cpp \
		src/components/Input.cpp \
		src/components/Output.cpp   \
		src/components/And.cpp \
		src/components/Or.cpp \
		src/components/Xor.cpp \
		src/components/Nor.cpp \
		src/components/Nand.cpp \
		src/components/Not.cpp	\
		src/components/Sum.cpp	\
		src/components/Comp_4081.cpp \
		src/components/Comp_4001.cpp \
		src/components/Comp_4011.cpp \
		src/components/Comp_4030.cpp \
		src/components/Comp_4071.cpp \
		src/components/Comp_4069.cpp \
		src/components/Comp_4008.cpp \
		src/components/Comp_4514.cpp \
		src/components/Comp_4013.cpp \
		src/components/Comp_4040.cpp \
		src/Shell.cpp    \
		src/components/Factory.cpp  \
		src/Parser/Parser.cpp   \
		src/errors/Errors.cpp   \
		src/Circuit.cpp

SRC_TESTS	=	tests/directlink_main.cpp   \
                tests/error_main.cpp	\
 				tests/shell.cpp	\
                tests/clock_main.cpp   \
                tests/true_main.cpp \
                tests/false_main.cpp    \
                tests/and_main.cpp	\
 				tests/or_main.cpp	\
 				tests/nand_main.cpp	\
 				tests/nor_main.cpp	\
 				tests/not_main.cpp	\
 				tests/xor_main.cpp	\
 				tests/4081_main.cpp	\
 				tests/4071_main.cpp	\
 				tests/4001_main.cpp	\
 				tests/4011_main.cpp	\
 				tests/4030_main.cpp	\
 				tests/4008_main.cpp	\
 				tests/4514_main.cpp	\
 				tests/4040_main.cpp	\
 				tests/4013_main.cpp

SRCS	=	$(SRC) src/main.cpp

SRC_TEST =  $(SRC)

OBJ	=	$(SRCS:.cpp=.o)

OBJ_SRC_TEST =   $(SRC_TEST:.cpp=.o)

OBJ_TESTS = 	$(SRC_TESTS:.cpp=.o)

CXXFLAGS	=	-Wall -Wextra -Werror -I include/

LDFLAGS	=	-lcriterion

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_TESTS)
	@$(RM) $(SRCS:.cpp=.gcda)
	@$(RM) $(SRCS:.cpp=.gcno)
	@$(RM) $(SRC_TESTS:.cpp=.gcda)
	@$(RM) $(SRC_TESTS:.cpp=.gcno)
	@$(RM) *.gcno
	@$(RM) *.gcda
	@$(RM) vgcore.*

fclean: clean
	@$(RM) $(NAME)
	@$(RM) unit_tests

re:	fclean all

tests_run: CXXFLAGS += --coverage
tests_run: fclean $(OBJ_SRC_TEST) $(OBJ_TESTS)
	@$(CXX) -o unit_tests $(OBJ_SRC_TEST) $(OBJ_TESTS) $(CXXFLAGS) $(LDFLAGS)
	./unit_tests
	gcovr ./src/ --exclude ./tests/ --exclude ./include/


debug: CXXFLAGS += -g3
debug: fclean all

.PHONY: all clean fclean re debug tests_run
