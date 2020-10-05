all:main

main:build/src/main.o build/src/function.o
	gcc build/src/main.o build/src/function.o -o bin/main
build/src/function.o:src/function.c
	gcc -c src/function.c -o build/src/function.o
build/src/main.o:src/main.c
	gcc -c src/main.c -o build/src/main.o	
	
test:build/test/test.o build/test/main.o build/src/function.o 
	gcc -I thirdparty -Wall -Werror build/test/test.o build/test/main.o build/src/function.o -o bin/test	
build/test/test.o:test/test.c
	gcc -I src -I thirdparty -Wall -Werror -c test/test.c -o build/test/test.o
build/test/main.o:test/main.c
	gcc -I thirdparty -c test/main.c -o build/test/main.o


testing:
	bin/./test
	
run:
	bin/./main


clean:
	rm -rf build/test/*.o
	rm -rf build/src/*.o 
	rm -rf bin/*
	
checkdir:
	mkdir -p bin build build/test build/src
