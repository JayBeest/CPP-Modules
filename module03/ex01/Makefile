###               auto-generated Makefile               ###

NAME		=	scavt

SRC_DIR		=	src/
OBJ_DIR		=	obj/
BIN_DIR		=	bin/
BIN			=	$(BIN_DIR)$(NAME)

SRC			=	ClapTrap.cpp \
				ScavTrap.cpp \
				main.cpp \

OBJ 		=	$(addprefix $(OBJ_DIR), $(SRC:%.cpp=%.o))

CFLAGS		=	-Wall -Werror -Wextra -std=c++98 -g #-fsanitize=address
CC			=	c++

ifeq ("$(VERBOSE)","1")
Q :=
VECHO = @echo
else
Q := @
VECHO = @echo
endif

vpath %.cpp $(SRC_DIR)

all: $(BIN)

$(BIN): $(OBJ)
	$(Q)mkdir -p $(@D)
	$(VECHO)
	$(VECHO) "\033[36mLinking binary file:     $@ 🚨\033[0m"
	$(VECHO)
	$(Q)$(CC) $^ $(CFLAGS) -o $@

$(OBJ_DIR)%.o:%.cpp
	$(Q)mkdir -p $(@D)
	$(VECHO) "\033[34mCompiling object file:   $@\033[0m"
	$(Q)$(CC) -c $< $(CFLAGS) -o $@

clean:
	$(VECHO) "\033[31mRemoving object files\033[0m"
	$(VECHO)
	$(Q)rm -rf $(OBJ_DIR)

fclean: clean
	$(VECHO) "\033[31mRemoving binary\033[0m"
	$(VECHO)
	$(Q)rm -f $(BIN)

re: clean all

reall: fclean all

rerun: re
	./miniRT

.PHONY:	all libft norme clean fclean re reall

