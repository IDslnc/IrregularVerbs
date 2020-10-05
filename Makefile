.PHONY: clean all test run runtest

BIN_DIR = ./bin
BUILD_DIR = ./build
SRC_DIR = ./src
TEST_DIR = ./test
FLAGS = -Wall

all: $(BIN_DIR)/main

$(BIN_DIR)/main: $(BUILD_DIR)/src/main.o $(BUILD_DIR)/src/function.o
	g++ $(FLAGS) $(BUILD_DIR)/src/main.o $(BUILD_DIR)/src/function.o -o $(BIN_DIR)/main
$(BUILD_DIR)/src/main.o:
	g++ $(FLAGS) -c $(SRC_DIR)/main.c -o $(BUILD_DIR)/src/main.o
$(BUILD_DIR)/src/function.o:
	g++ $(FLAGS) -c $(SRC_DIR)/function.c -o $(BUILD_DIR)/src/function.o


test: $(BUILD_DIR)/src/function.o $(BUILD_DIR)/test/test.o
	g++ $(FLAGS) $(BUILD_DIR)/test/test.o $(BUILD_DIR)/src/function.o -o $(BIN_DIR)/test
$(BUILD_DIR)/test/test.o:
	g++ $(FLAGS) -c $(TEST_DIR)/test.c -o $(BUILD_DIR)/test/test.o

run:
	./bin/main

runtest:
	./bin/test

clean:
	rm -f bin/test
	rm -f build/src/*.o
	rm -f build/test/*.o
	rm -f bin/main
	rm -f verbs.txt
