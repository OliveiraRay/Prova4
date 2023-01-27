#include <stdio.h>
#include <string.h>


int main(){
    int gols1, gols2, jogos, pontos1, pontos2, desempate1;
    int desempate2, desempateParte1, desempateParte2;
    char separa[2];
    
    scanf("%d", &jogos);
    
    while(jogos>0)
    {
        pontos1 = 0; pontos2 = 0;
        desempate1 = 0, desempate2 = 0;
        scanf("%d", &gols1);  scanf("%s", separa); scanf("%d", &gols2);
        if(gols2==gols1){
            pontos1 += 1; pontos2 += 1; 
        }else if(gols2>gols1){
            pontos2 += 3;
        }else if(gols2<gols1){
            pontos1 += 3;
        }
        desempate2 += gols2;
        desempate1 += gols1;
        desempateParte2 = gols2;
 
        scanf("%d", &gols2);  scanf("%s", separa); scanf("%d", &gols1);
        if(gols2==gols1){
            pontos1 += 1; pontos2 += 1; 
        }else if(gols2>gols1){
            pontos2 += 3;
        }else if(gols2<gols1){
            pontos1 += 3;
        }
        desempate1 += gols1;
        desempate2 += gols2;
        desempateParte1 = gols1;
       
        if(pontos1 == pontos2){
            if(desempate1 > desempate2){
                printf("Time 1\n");
            }else if(desempate2 > desempate1){
                printf("Time 2\n");
            }else{
                if(desempateParte1 > desempateParte2){
                    printf("Time 1\n");
                }else if(desempateParte2 > desempateParte1){
                    printf("Time 2\n");
                }else{
                    printf("Penaltis\n");
                }
            }
        }else if(pontos1>pontos2){
            printf("Time 1\n");
        }else if(pontos2 > pontos1){
            printf("Time 2\n");
        }
        jogos--;
    }
    

    
    
    
    return 0;
}