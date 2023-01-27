#include <stdio.h>

int main(){
    int n, i, n2, cont = 1;
    while(scanf("%d",&n) != EOF){
        for(i = 1; i <= n; i++){
            scanf("%d", &n2);
            if(i == n2){
                printf("Teste %d\n%d\n\n", cont++, n2);
                }
            }
    }
    return 0;
}