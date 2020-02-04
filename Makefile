output: main.o generate.o encrypt.o /usr/local/lib/libsodium.so 
	gcc main.o generate.o encrypt.o -o output -L/usr/local/lib/libsodium.so -lsodium

main.o: src/main.c
	gcc -c src/main.c

generate.o: src/generate.c src/generate.h /usr/local/lib/libsodium.so
	gcc -c src/generate.c -L/usr/local/lib/libsodium.so -lsodium

encrypt.o: src/encrypt.c src/encrypt.h
	gcc -c src/encrypt.c

clean:
	rm *.o output
