###               auto-generated Makefile               ###

NAME		=	P-42

SRC_DIR		=	src/
OBJ_DIR		=	obj/
BIN_DIR		=	bin/
BIN			=	$(BIN_DIR)$(NAME)

SRC			=	ClassContact.cpp \
				ClassPhonebook.cpp \
				P-42.cpp \

OBJ 		=	$(addprefix $(OBJ_DIR), $(SRC:%.cpp=%.o))

CFLAGS		=	-Wall -Werror -Wextra -std=c++98 -g #-fsanitize=address
CC			=	c++

vpath %.cpp $(SRC_DIR)

all: $(BIN)

$(BIN): $(OBJ)
	@echo
	@echo "\033[36mLinking binary file:     $@ 📞📖\033[0m"
	@echo
	@$(CC) $^ $(CFLAGS) -o $@

$(OBJ_DIR)%.o:%.cpp
	@mkdir -p $(@D)
	@echo "\033[34mCompiling object file:   $@\033[0m"
	@$(CC) -c $< $(CFLAGS) -o $@

clean:
	@echo "\033[31mRemoving object files\033[0m"
	@echo
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[31mRemoving binary\033[0m"
	@echo
	@rm -f $(BIN)

re: clean all

reall: fclean all

rerun: re
	./miniRT

.PHONY:	all libft norme clean fclean re reall

