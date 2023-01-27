#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int long long numeroEntrada, q, resto, i;
char hexa[10000000] = {'\0'}, getInt[10000000] = {'\0'};

int main(void)
{	while(scanf("%lli", &numeroEntrada) != EOF)
	{	
		printf("\n");
		do{
			q = numeroEntrada / 16;
			resto = numeroEntrada % 16;
			numeroEntrada /= 16;
			
			switch(resto){
				case 10:
					strcat(hexa, "A");
				break;
				case 11:
					strcat(hexa, "B");
				break;
				case 12:
					strcat(hexa, "C");
				break;
				case 13:
					strcat(hexa, "D");
				break;
				case 14:
					strcat(hexa, "E");
				break;
				case 15:
					strcat(hexa, "F");
				break;
				case 16:
					strcat(hexa, "G");
				break;
				default:
					sprintf(getInt, "%lli", resto);
					strcat(hexa, getInt);
				}
			
		}
		while(q != 0);
		
		for(i=strlen(hexa); i >= 0; i--){
			printf("%c", hexa[i]);
			hexa[i] = 0;
		}
	}
	printf("\n");
	return 0;
}