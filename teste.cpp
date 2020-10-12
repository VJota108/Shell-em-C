#include <stdio.h>
#include <string.h>
#include<stdlib.h>

main(){
char comando[30];
do{
	
printf("sh> ");
fflush(stdin);
gets(comando);
system(comando);

}while(strcmp(comando,"exit") != 0);

}
