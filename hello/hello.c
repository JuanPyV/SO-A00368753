#include <stdio.h>

void printHello(char *fulanito){
    printf("Hola %s\n", fulanito);
}
int main(int argc, char **argv){
    int i = 0;
    for(i = 1; i < argc; i++){
        printf("Hola %s \n", argv[i]);
    }
    return 0;
}