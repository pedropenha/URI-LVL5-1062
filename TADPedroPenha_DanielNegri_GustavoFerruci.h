struct Pilha{
    int vetor[10000];
    int topo;
};

int verificaArquivo(FILE *PtrArq){
    if(PtrArq != NULL){
        return 1;
    }else{
        fclose(PtrArq);
        return 0;
    }
}

int LerArquivo(FILE *PtrArq){
    int num;
    fscanf(PtrArq, "%d ", &num);
    return num;
}

void salvaArquivo(char NomeArq[100], char String[100]){
    FILE *PtrArq = fopen(NomeArq, "r");

    if(PtrArq == NULL){
        PtrArq = fopen(NomeArq, "w");
        fprintf(PtrArq,"%s", String);
        fclose(PtrArq);
    }else{
        fclose(PtrArq);
        PtrArq = fopen(NomeArq, "a");
        fprintf(PtrArq, "%s", String);
        fclose(PtrArq);
    }
}

void inicializa(Pilha &p){
    p.topo = -1;
}

void push(Pilha &p, int id){
    p.vetor[++p.topo] = id;
}

void pop(Pilha &p){
    p.topo--;
}

int full(Pilha p){
    if(p.topo == 10000){
        return 1;
    }else{
        return 0;
    }
}

int empty(Pilha p){
    if(p.topo == -1){
        return 1;
    }else{
        return 0;
    }
}

int elementoTopo(Pilha &p){
    return p.vetor[p.topo--];
}

void exibirPilha(Pilha p){
    for(int i = 0; i < p.topo; i++){
        printf("v[%d] = %d\n", i, p.vetor[i]);
    }
}