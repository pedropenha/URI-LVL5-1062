struct Pilha{
    int v[100], topo;
};

void inicializa(){

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