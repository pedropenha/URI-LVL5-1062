#include <stdio.h>
#include <stdlib.h>
#include "TAD.h"

void concatena(Pilha &p1, Pilha p2);

int main(){

    Pilha p1;
    Pilha p2;
    int num[] = {34, 87, 32, 45, 28, 74, 56, 41, 23}, result;

    inicializa(p1,p2);

    for(int i = 0; i < 9; i++){
        push(p1, num[i], 1);
    }

    exibir(p1, 1);
    puts("");
    result = pop(p1, 1);
    while(!vazia(p1, 1)){
        if(result != 87)
            push(p2, result, 2);
        result = pop(p1, 1);
    }

    exibir(p2, 2);

    puts("");

    while (!vazia(p2, 2)){
        push(p1, pop(p2, 2), 1);
    }

    puts("");

    exibir(p1, 1);


}