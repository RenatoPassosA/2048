# Nome do projeto
NAME=2048
NAME_TEST=2048_test

# Arquivos fonte do programa principal
FILES=./src/main.o ./src/board.o ./src/tile.o ./src/moves.o ./tests/utils.o
TEST_FILES=./src/board.o ./src/tile.o ./src/moves.o ./tests/board.test.o ./tests/utils.o

# Flags para o compilador
CC_WARNING_FLAG=-ggdb -g -Wall -Wextra #-Werror -
COMPILADOR=g++ $(CC_WARNING_FLAG)
TEST_FLAGS=-lgtest -lgtest_main -pthread

# Regras principais
all: $(NAME)

# Compilação do programa principal
$(NAME): $(FILES)
	$(COMPILADOR) $^ -o $(NAME)

# Compilação de arquivos .o
%.o: %.cpp
	$(COMPILADOR) -c $< -o $@

# Limpeza dos arquivos .o
clean:
	@rm -f $(FILES) $(TEST_OBJ) 2048_test

# Limpeza total (remover binários)
fclean: clean
	@rm -f $(NAME)

# Recompilar tudo
re: fclean all

# Compilação e execução dos testes
test: $(NAME_TEST)
	@clear
	./$(NAME_TEST)

$(NAME_TEST): $(TEST_FILES)
	$(COMPILADOR) $^ -o $(NAME_TEST) $(TEST_FLAGS)

