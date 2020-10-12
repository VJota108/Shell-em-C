#include <stdio.h>
#include <string.h>
#include<stdlib.h>

main(){
char linha[512];
do{
	
printf("meu shell> ");
fflush(stdin);
gets(linha);

}while(strcmp(linha,"exit") != 0);

}
