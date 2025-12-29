SRC_DIR = src
INC_DIR = src/include
FILES = GameRunner.cpp Game.cpp
TEST_FILES = Game.cpp
CC = g++
INC = -I$(INC_DIR)
OPTS = -std=c++17 -Wall -Wextra -Werror
OUTOPTS = -o 
OUT = out/trivia
TEST_OUT = out/trivia_tests

all: prod 

prod: build run

tests: test runTest

.outputFolder:
	mkdir -p out

build: .outputFolder
	$(CC) $(addprefix $(SRC_DIR)/,$(FILES)) $(INC) $(OPTS) $(OUTOPTS) $(OUT)

run: 
	./$(OUT)

test: .outputFolder
	$(CC) $(addprefix $(SRC_DIR)/,$(TEST_FILES)) $(INC) $(OPTS) $(OUTOPTS) $(TEST_OUT)

runTest: 
	./$(TEST_OUT)

clean: 
	rm -rf out/