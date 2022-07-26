NAME		=	GlobalBanksters

SRC_DIR		=	src/
OBJ_DIR		=	obj/
BIN_DIR		=
BIN			=	$(BIN_DIR)$(NAME)
INCLUDE_DIR	=	src/

SRC			=	tests.cpp \
				Account.cpp

OBJ 		=	$(addprefix $(OBJ_DIR), $(SRC:%.cpp=%.o))

TEMP_CFLAGS	=	-g -Wno-unused #-fsanitize=address
CFLAGS		=	-Wall -Werror -Wextra $(TEMP_CFLAGS)
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

bonus: all

$(BIN): $(OBJ)
	$(Q)mkdir -p $(@D)
	$(VECHO)
	$(VECHO) "\033[36mLinking binary file:     $@ 📢\033[0m"
	$(VECHO)
	$(Q)$(CC) $^ $(CFLAGS) -o $@

$(OBJ_DIR)%.o:%.cpp
	$(Q)mkdir -p $(@D)
	$(VECHO) "\033[34mCompiling object file:   $@\033[0m"
	$(Q)$(CC) -c $< $(CFLAGS) -o $@

libft:
	$(Q)make bonus -C libft

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
