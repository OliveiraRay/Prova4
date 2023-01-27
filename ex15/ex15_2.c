#include <stdio.h>
#include <string.h>

int main(){
    int l1, l2, n;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
            scanf("%d", &l1); 
            scanf("%d", &l2);
           
        if( (l2>=0) && (l2<=2)){
            printf("Nova\n");
        }else if(l2>=3 && l2<=96 && l2>l1 ){
            printf("Crescente\n");
        }else if(l2>=97 && l2<=100){
            printf("Cheia\n");
        }else if(l1>l2 && l2>=3 && l2<=96){
            printf("Minguante\n");
        }
    }
    
    
    
    return 0;
}