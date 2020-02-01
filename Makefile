output: main.o generate.o 
	gcc main.o generate.o -o output

main.o: src/main.c
	gcc -c src/main.c

generate.o: src/generate.c src/generate.h
	gcc -c src/generate.c

clean:
	rm *.o output
