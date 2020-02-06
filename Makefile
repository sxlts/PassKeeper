output: main.o generate.o encrypt.o store.o  /usr/local/lib/libsodium.so 
	gcc main.o generate.o encrypt.o store.o -o output -L/usr/local/lib/libsodium.so -lsodium

main.o: src/main.c
	gcc -c src/main.c

generate.o: src/generate.c src/generate.h /usr/local/lib/libsodium.so
	gcc -c src/generate.c -L/usr/local/lib/libsodium.so -lsodium

encrypt.o: src/encrypt.c src/encrypt.h
	gcc -c src/encrypt.c

store.o: src/store.c src/store.h src/encrypt.h src/encrypt.c
	gcc -c src/store.c src/encrypt.c

clean:
	rm *.o output
