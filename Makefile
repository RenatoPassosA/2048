# Nome do projeto
NAME=2048

# Arquivos fonte do programa principal
FILES=./src/main.o ./src/board.o ./src/tile.o

# Flags para o compilador (lib para Google Test e warnings)
CC_WARNING_FLAG=-ggdb -Wall -Wextra #-Werror 
COMPILADOR=g++ $(CC_LIB_FLAG) $(CC_WARNING_FLAG)

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
test:
	g++ src/board.cpp src/tile.cpp tests/board.test.cpp -o 2048_test -lgtest -lgtest_main -pthread
	./2048_test
