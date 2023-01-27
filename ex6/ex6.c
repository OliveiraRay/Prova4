#include <stdio.h>
#include <string.h>


int main(){
    char t[101], conf;

    while(scanf("%s", t) != EOF){
        printf("%c", t[0]);
        scanf("%c", &conf);
        if(conf == '\n'){
            puts("");
            break;
        }
    }

    return 0;
}