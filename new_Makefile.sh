#!/bin/bash

SRC_DIR="src/"
OBJ_DIR="obj/"
BIN_DIR="bin/"

if ! [ -e "$BIN_DIR" ]
then
  mkdir $BIN_DIR
fi

if ! [ -e "$SRC_DIR" ]
then
  mkdir $SRC_DIR
fi

if [ "$1" == "" ]
then
  read -p "Project name: " -r NAME
  case "$NAME" in
    [])
      exit
      ;;
  esac
else
  NAME=$1
fi

if [ -f "Makefile" ]
then
  read -p "Makefile already exists? Overwrite? " ANSWER
  case "$ANSWER" in
    [yY] | [yY][eE][sS])
    echo 'Overwriting...'
    ;;
    *)
      exit
      ;;
  esac
fi

echo 'Generating Makefile'
echo "###               auto-generated Makefile               ###" > Makefile
echo >> Makefile
echo "NAME		=	$NAME" >> Makefile
echo >> Makefile
echo "SRC_DIR		=	$SRC_DIR" >> Makefile
echo "OBJ_DIR		=	$OBJ_DIR" >> Makefile
echo "BIN_DIR		=	$BIN_DIR" >> Makefile
echo 'BIN			=	$(BIN_DIR)$(NAME)' >> Makefile
echo >> Makefile

echo -n "SRC			=	" >> Makefile
ls -1 src/*.cpp | sed 's/.*\///' | awk ' NR>1 {printf "\t\t\t\t"}; {print $1 }' >> Makefile

echo >> Makefile
echo 'OBJ 		=	$(addprefix $(OBJ_DIR), $(SRC:%.cpp=%.o))' >> Makefile
echo >> Makefile
echo 'CFLAGS		=	-Wall -Werror -Wextra -g #-fsanitize=address' >> Makefile
echo "CC			=	c++" >> Makefile
echo >> Makefile
echo 'vpath %.cpp $(SRC_DIR)' >> Makefile
echo >> Makefile
echo 'all: $(BIN)' >> Makefile
echo >> Makefile
echo '$(BIN): $(OBJ)' >> Makefile
echo '	@echo' >> Makefile
printf '	@echo "\\033[36mLinking binary file:     $@ 🚨\\033[0m"\n' >> Makefile
echo '	@echo' >> Makefile
echo '	@$(CC) $^ $(CFLAGS) -o $@' >> Makefile
echo >> Makefile
echo '$(OBJ_DIR)%.o:%.cpp' >> Makefile
echo '	@mkdir -p $(@D)' >> Makefile
printf '	@echo "\\033[34mCompiling object file:   $@\\033[0m"\n' >> Makefile
echo '	@$(CC) -c $< $(CFLAGS) -o $@' >> Makefile
echo >> Makefile
echo 'clean:' >> Makefile
printf '	@echo "\\033[31mRemoving object files\\033[0m"\n' >> Makefile
echo '	@echo' >> Makefile
echo '	@rm -rf $(OBJ_DIR)' >> Makefile
echo >> Makefile
echo 'fclean: clean' >> Makefile
printf '	@echo "\\033[31mRemoving binary\\033[0m"\n' >> Makefile
echo '	@echo' >> Makefile
echo '	@rm -f $(BIN)' >> Makefile
echo >> Makefile
echo 're: clean all' >> Makefile
echo >> Makefile
echo 'reall: fclean all' >> Makefile
echo >> Makefile
echo 'rerun: re' >> Makefile
echo '	./miniRT' >> Makefile
echo >> Makefile
echo '.PHONY:	all libft norme clean fclean re reall' >> Makefile
echo >> Makefile