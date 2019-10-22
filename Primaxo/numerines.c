#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int cont;
    for(cont = 2; cont < 101; cont++){
        printf("%d\n", cont);
    }
    printf("%d\n", -1);
}