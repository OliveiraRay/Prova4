#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void RNA(char *, int);

int main(){

    int tam;
    char *molecula = (char*) malloc(1000000*sizeof(char));
    
    while(scanf("%s", molecula) != EOF){
        
        tam = strlen(molecula);
        RNA(molecula, tam);
        
    }
    return 0;
}

void RNA(char *molecula, int tam){
    char *rna = (char*) malloc(1000000*sizeof(char));
    for(int i=0; i<tam; i++){
        if(molecula[i] == 'A'){
            rna[i] = 'U';
        }else if (molecula[i] == 'C'){
            rna[i] ='G';
        }else if (molecula[i] == 'G'){
            rna[i] = 'C';
        }else{
            rna[i] = 'A';
        }
    }
    printf("%s\n", rna);
    
}