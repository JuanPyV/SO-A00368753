libhello.o: libhello.c
#-c lo compila como una libreria de funciones
	gcc -c libhello.c
hello: hello.c libhello.o
#el archivo con .o es que gcc lo hace binario, luego los combina y crea un ejecutable (hello)
	gcc hello.c libhello.o -o hello
test: hello
	./hello Fulanito Perengano Juanito
