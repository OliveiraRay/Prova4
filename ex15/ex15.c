#include <stdio.h>
#include <stdlib.h>

char *FaseLua(char**, int, int);

int main(){
    char **fases = (char**) malloc(4*sizeof(char*));
    for(int i=0; i<4; i++){
        fases[i] = (char*) malloc(15*sizeof(char*));
    }
    fases[0] = "Nova";
    fases[1] = "Crescente";
    fases[2] = "Cheia";
    fases[3] = "Minguante";

    int qtd_oper, n1, n2;
    scanf("%d", &qtd_oper);
    for(int i=0; i<qtd_oper; i++){
        scanf("%d %d", &n1, &n2);
        printf("%s", FaseLua(fases, n1, n2));
    }

    return 0;
}

char *FaseLua(char** fases, int n1, int n2){
    if(n1 >= 0 && n2 < 2){
        return fases[0];
    }else if(n1 >= 2 && n2 <= 96){
        return fases[1];
    }else if (n1 > 96 && n2 <= 3 && n2>n1){
        return fases[3];
    }else if(n1>96 && n2 <=100){
        return fases[2];
    }
}