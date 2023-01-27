#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char name[100];
char x,c[100]={0};
int i,j,a,f=1,g=0;
int main(){
    fgets(name, 100, stdin);

    a=strlen(name)-1;
    for(i=a;i>=0;i--){
        if(name[i]==' '){
            x=name[i+1];
            x=toupper(x);
            c[0]=x;
            name[i]='.';
            for(j=i+2;j<a;j++){
                c[f]=(name[j]);
                f++;
            }
            printf("%s,",c);
            g=1;
            break;
            }
    }

    g=0;f=0;
    for(i=0;i<a;i++){
        if(name[i]=='.'){
            break;

        }if(name[i]==' '){
            g=0;
            i++;
            if(name[i+2]==' '||name[i+2]=='.'){
                i+=2;g=1;
            }
        }
        if(name[i]==' '){
            g=0;i++;
        }
        if(g==0){
            if(name[i+2]!=' '){
                x=name[i];
                g=1;

                printf(" %c.", toupper(x));
            }
        }
    }
   printf("\n");
   return 0;
}