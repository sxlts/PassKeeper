output: main.o generate.o encrypt.o 
	gcc main.o generate.o encrypt.o -o output

main.o: src/main.c
	gcc -c src/main.c

generate.o: src/generate.c src/generate.h
	gcc -c src/generate.c

encrypt.o: src/encrypt.c src/encrypt.h
	gcc -c src/encrypt.c

clean:
	rm *.o output
