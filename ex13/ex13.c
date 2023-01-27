#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char posFinal(char *, int );

int main(){
    int n, i;
    char *comandos;

    scanf("%d", &n);
    comandos = (char*) malloc(n*sizeof(char));
    scanf("%s", comandos);

    printf("%c\n", posFinal(comandos, n));



    return 0;
}
char posFinal(char * com, int n){
    int i;
    double angulo = 0.0, x;

    for(i = 0; i<n; i++){
        if(com[i] == 'D'){
            angulo = angulo + 90.0;
        }else{
            angulo = angulo - 90.0;
        }
    }
    x = angulo * M_PI/180.0;

    if(cos(x) == 1){
        return 'N';
    }else if(cos(x) == -1){
        return 'S';
    }

    else if(sin(x) == 1){
        return 'L';
    }else{
        return 'O';
    }
}
