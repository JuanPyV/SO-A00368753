#include <stdio.h>
#include <stdlib.h>

int main(){
    int next, nextNext;

    scanf("%d", &next);
    fprintf(stderr, "%d, ", next);
    scanf("%d", &nextNext);
    while (nextNext != -1) {
        if (nextNext%next != 0) {
            printf("%d\n", nextNext);
        }
        scanf("%d", &nextNext);

    }
    printf("%d\n", -1);
    return 0;
}