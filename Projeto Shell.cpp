#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>  
#include <unistd.h>

int executa_comando(char **arqv){
    pid_t pid;
    pid = fork();
    char *cmd = &*arqv[0];
    int status;

	//este cmp esta comparando se o 1 comando é de saida
	if(strcmp(cmd,"quit")==0){
		exit(1);
	}

	//executar comandos
    if(pid==0){
        if(execvp(cmd,arqv)==-1){
            printf("Comando invalido \n");
        }
        exit(1);
    }else{
        if(pid<0){
            printf("Falha na concorrência \n");
        }else{
            do {
                waitpid(pid, &status, WUNTRACED);
            }while (!WIFEXITED(status) && !WIFSIGNALED(status));	//esperar processos acabarem
        }
    }
    return 1;
}
    
int main(){
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

			//printf("%s\n",token1);
			
			contv=strlen(token1);

			argv = (char**)malloc(sizeof(char*)*(contv+1));
			
			i=0;
			str2 = token1;
			while((argumentos = strtok_r(str2," ",&str2))){
				argv[i] = argumentos;
				//printf("%s--\n",argv[i]);
				i++;
			}
			argv[i] = NULL;
			executa_comando(argv);
		}
			
	}while(strcmp(linha,"quit") != 0);

	return 0;
}
