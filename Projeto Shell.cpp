#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <unistd.h>

main(){
	int i=0,contv=0;
	char linha[512];
	char *str1,*token1,*str2,*argumentos,*cmd;
	char **argv;
	do{
		i=0;
		printf("meu shell> ");
		fflush(stdin);
		gets(linha);


		str1 = linha;
		
		//achar metodo para separar comandos
		while((token1 = strtok_r(str1,",",&str1))){

			printf("%s\n",token1);
			
			contv=strlen(token1);

			argv = (char**)malloc(sizeof(char*)*(contv+1));
			
			i=0;
			str2 = token1;
			while((argumentos = strtok_r(str2," ",&str2))){
				argv[i] = argumentos;
				printf("%s--\n",argv[i]);
				i++;
			}
			argv[i] = NULL;
			
			cmd = argv[0];
			printf("%s..\n",cmd);
			if(execvp(cmd,argv)==-1){
				printf("Comando invalido");
			}
		}
			
	}while(strcmp(linha,"quit") != 0);

	return 0;
}
