output: main.o generate.o store.o  /usr/local/lib/libsodium.so 
	gcc main.o generate.o store.o -o output -L/usr/local/lib/libsodium.so -lsodium

main.o: src/main.c
	gcc -c src/main.c

generate.o: src/generate.c src/generate.h /usr/local/lib/libsodium.so
	gcc -c src/generate.c -L/usr/local/lib/libsodium.so -lsodium

store.o: src/store.c src/store.h
	gcc -c src/store.c

clean:
	rm *.o output
