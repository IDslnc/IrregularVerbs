all:main


main:build/src/main.o build/src/function.o
	gcc build/src/main.o build/src/function.o -o bin/main
build/src/main.o:src/main.c
	gcc -c src/main.c -o build/src/main.o
build/src/function.o:src/function.c
	gcc -c src/function.c -o build/src/function.o

run:
	bin/./main

clean:
	rm -f build/src/*.o
	rm -f bin/main
	rm -f verbs.txt

checkdir:
	mkdir -p bin build build/test build/src
