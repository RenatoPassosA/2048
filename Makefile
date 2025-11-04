NAME=2048
NAME_TEST=2048_test

FILES=./main.o ./src/game_control.o ./src/board.o ./src/tile.o ./src/board_state.o ./src/direction_factory.o ./src/down.o ./src/up.o ./src/left.o ./src/right.o ./graphics/render_tile.o ./graphics/render_board.o ./graphics/tile_colors.o ./tests/utils.o
TEST_FILES=./src/board.o ./src/tile.o ./src/board_state.o ./src/direction_factory.o ./src/down.o ./src/up.o ./src/left.o ./src/right.o ./tests/board.test.o ./tests/utils.o

CC_WARNING_FLAG=-ggdb -g -Wall -Wextra #-Werror -
COMPILADOR=g++ $(CC_WARNING_FLAG)
GRAPHICS_FLAGS=-I /usr/include/SFML -L /usr/lib/x86_64-linux-gnu -lsfml-graphics -lsfml-window -lsfml-system
TEST_FLAGS=-lgtest -lgtest_main -pthread

all: $(NAME)

$(NAME): $(FILES)
	$(COMPILADOR) $^ -o $(NAME) $(GRAPHICS_FLAGS)

%.o: %.cpp
	$(COMPILADOR) -c $< -o $@

clean:
	@rm -f $(FILES) $(TEST_FILES) 2048_test

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: $(NAME_TEST)
	@clear
	./$(NAME_TEST)

$(NAME_TEST): $(TEST_FILES)
	$(COMPILADOR) $^ -o $(NAME_TEST) $(TEST_FLAGS)

