#include <stdio.h>
#include "TADPedroPenha_DanielNegri_GustavoFerruci.h"

int main() {
    int nao_pilha, num_vagoes, i, nao_empilhado, empilhando, zero;
    Pilha p;
    FILE *PtrArq = fopen("Trilhos.txt", "r");
    inicializa(p);
    if(verificaArquivo(PtrArq)){
        num_vagoes = LerArquivo(PtrArq);
        salvaArquivo("OrganizaTrilhos.txt", "\n");
        while(num_vagoes){
            while(1){
                p.topo = -1;
                for(i = 0, empilhando = 1, nao_empilhado = 0, zero = 0; i<num_vagoes && !nao_empilhado && !zero; i++){
                    nao_pilha = LerArquivo(PtrArq);
                    if(!nao_pilha){
                        zero=1;
                        break;
                    }
                    while(1){
                        if(nao_pilha == empilhando){
                            empilhando++;
                            break;
                        }else
                        if(nao_pilha > empilhando){
                            if(!full(p)){
                                push(p, empilhando);
                                empilhando++;
                            }
                        }else{
                            if(p.vetor[p.topo] == nao_pilha)
                                pop(p);
                            else{
                                nao_empilhado=1;
                                for(; i < num_vagoes-1; i++)
                                    nao_pilha = LerArquivo(PtrArq);
                            }
                            break;
                        }
                    }
                }
                if(!zero)
                    if(!nao_empilhado){
                        salvaArquivo("OrganizaTrilhos.txt", "Sim\n");
                    }else{
                        salvaArquivo("OrganizaTrilhos.txt", "Nao\n");
                    }
                else
                    break;
            }
            salvaArquivo("OrganizaTrilhos.txt", "\n\n");
            num_vagoes = LerArquivo(PtrArq);
        }

        fclose(PtrArq);

    }else{
        puts("Arquivo Trilhos.txt nao foi encontrado, insira-o!!!");
    }

    return 0;
}