#include <stdio.h>
#include <stdlib.h>

char * oMes(int, char**);

int main(){

    char **meses = (char **) malloc(12*sizeof(char*));
    for(int i=0; i<12;i++){
        meses[i] = (char*) malloc(12*sizeof(char));
    }
    meses[0] = "Janeiro";
    meses[1]  = "Fevereiro";
    meses[2] = "Marco";
    meses[3] = "Abril";
    meses[4] = "Maio";
    meses[5] ="Junho";
    meses[6] = "Julho";
    meses[7] = "Agosto";
    meses[8] = "Setembro";
    meses[9] = "Outubro";
    meses[10] = "Novembro";
    meses[11] = "Dezembro";

    int dia, mes, ano;
    while(scanf("%d %d %d", &dia, &mes, &ano)!=EOF){

        printf("%.2d de %s de %d\n", dia, oMes(mes, meses), ano);
    }


    return 0;
}

char * oMes(int mes, char**meses){
    if(mes == 1){
        return meses[0];
    }else if(mes ==2){
        return meses[1];
    }else if(mes ==3){
        return meses[2];
    }else if(mes ==4){
        return meses[3];
    }else if(mes ==5){
        return meses[4];
    }else if(mes ==6){
        return meses[5];
    }else if(mes ==7){
        return meses[6];
    }else if(mes ==8){
        return meses[7];
    }else if(mes ==9){
        return meses[8];
    }else if(mes ==10){
        return meses[9];
    }else if(mes ==11){
        return meses[10];
    }else{
        return meses[11];
    }
}