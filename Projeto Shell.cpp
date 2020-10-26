/*
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

void erroduploesp(){
	printf("Comando invalido, verifique os espacos\n");
}


main(){
	int i=0,pos,n;
	char linha[512];
	do{
		i=0;
		printf("meu shell> ");
		fflush(stdin);
		gets(linha);
		
		n = strlen(linha); //ver tamanho da linha
		
		if(n != 0){			//se linha for diferente de vazia separar comandos	
			
			while(linha[i] != '\0'){
			
				if(linha[i] == ' '){
					if(linha[i-1] == ' '){
						erroduploesp();				//chamar função erro espaço duplo
						break;
					}
				}
				
				//achar metodo para separar comandos
				
				i++;	
			}
		}
		
			
	}while(strcmp(linha,"quit") != 0);

	return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main (){
    char *str;
    char str2[100]; //"cat file ,  ,,,,,,,,,,,,,,,,,,,,,,   ,  , ls ,         joga";

    printf("-->");
    gets(str2);

    str = strtok(str2,", ");

    do{
        printf("%s \n", str);
        str = strtok(NULL, ", ");
    }while(str!=NULL);

    return 0;
}
