NAME		=	megaphone

SRC_DIR		=	src/
OBJ_DIR		=	obj/
BIN_DIR		=	bin/
BIN			=	$(BIN_DIR)$(NAME)
INCLUDE_DIR	=	include/

SRC			=	megaphone.cpp

OBJ 		=	$(addprefix $(OBJ_DIR), $(SRC:%.cpp=%.o))

CFLAGS		=	-Wall -Werror -Wextra -g #-fsanitize=address
CC			=	c++

vpath %.cpp $(SRC_DIR)

all: $(BIN)

bonus: all

$(BIN): $(OBJ)
	@echo
	@echo "\033[36mLinking binary file:     $@ 📢\033[0m"
	@echo
	@$(CC) $^ $(LIB) $(CFLAGS) -o $@

$(OBJ_DIR)%.o:%.cpp
	@mkdir -p $(@D)
	@echo "\033[34mCompiling object file:   $@\033[0m"
	@$(CC) -c $< $(CFLAGS) $(INCLUDES) -o $@

libft:
	@make bonus -C libft

clean:
	@echo "\033[31mRemoving object files\033[0m"
	@echo
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[31mRemoving binary\033[0m"
	@echo
	@rm -f $(NAME)
	@make fclean -C libft

re: clean all

reall: fclean all

rerun: re
	./miniRT

.PHONY:	all libft norme clean fclean re reall
