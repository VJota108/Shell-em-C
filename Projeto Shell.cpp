#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

#ifdef unix
    #include <unistd.h>
    #include <stdlib.h>
#elif defined(_WIN32) || defined(WIN32)
    #define OS_Windows
    #include <windows.h>
#endif

void erroduploesp(){
	printf("Comando invalido, verifique os espacos\n");
	main();
}


int main(){
	int i=0,j=0,n,v=0,vettam=0,cont=0;
	char linha[512];
	char *str,**vetComando;
	char str1[512];
	char str2[512];
	int g=0;
	//Comando para criar o malloc

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
				i++;	
			}
		}
		//achar metodo para separar comandos em um vetor com virgula 
    
    	    for(int y=0;y<512;y++){
    	        if(linha[y]==','|| linha[y]==' '){
    	            printf("entrou\n");
    	        }else{
    	            str1[g]=linha[y];
    	            g++;
    	            if(linha[y+1]==','|| linha[y+1]==' '){
    	                str1[g]=',';
    	                g++;
    	            }
    	            
    	        }
    	        
    	    }
    	    
    	printf("%s\n",str1);
    	strcpy(str2,str1);
    	printf("%s\n",str2);
    	g=strlen(str2);
    	printf("%d--Numero de caracteres\n",g);
    	//str1 agora será usado para contar quantos comandos existem...
    	//str2 já será usado para passar os comandos para a matriz dinamica...
    	
    	//Contando quantos comandos tem, para fazer a alocacao em seguida
    	str = strtok(str1,","); 
    	do{
			printf("%s \n", str);
			v++;
			str = strtok(NULL, ",");
    	}while(str!=NULL);

        printf("\n%d---Numero de comandos\n",v);
       //Comando para criar o malloc
	   vetComando = (char**)malloc (v * sizeof(char*));
	   if(vetComando==NULL){
	       printf("Erro memória insuficiente\n");
	   }
	   for(vettam=0;vettam<v;vettam++){
		       vetComando[vettam] = (char*)malloc (20 * sizeof(char));
	   }

	  
	   //Colocando valores dentro da alocacao dinamica
	   i=0;
       j=0;
        for(i=0;i<g;i++){
            if(str2[i]==','){
                j++;
                cont=0;
            }
            else{
                vetComando[j][cont]=str2[i];
                cont++;
                //printf("%c--Printe matriz\n",str2[i]);
            }
            
            if(str2[i]=='\0'){
                break;
            }
        }
        
        //printar valores da matriz  
	   	for(vettam=0;vettam<v;vettam++){
		       printf("%s--Printe matriz\n",vetComando[vettam]);
	   }
	    cont=0;
    	v=0;   		            
    	g=0;
        for(vettam=0;vettam<v;vettam++){
			free(vetComando[vettam]);
		}
	    free(vetComando);
			
	}while(strcmp(linha,"quit") != 0);

	return 0;
}
