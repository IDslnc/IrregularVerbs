all:main


main:build/src/main.o
	gcc build/src/main.o -o bin/main
build/src/main.o:src/main.c
	gcc -c src/main.c -o build/src/main.o
	
run:
	bin/./main

clean:
	rm -f build/*.o
	rm -f bin/main

checkdir:
	mkdir -p bin build build/test build/src
