#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	while(1){
		
		printf("myShell>>");
	
		char inputValue[60]; 
		gets(inputValue);
		
		char **parameters = (char**)malloc(sizeof(char*));
		parameters[0] = (char*)malloc(sizeof(char)*30);
		
		char *pt;
		pt = strtok(inputValue," ");
		
		int i=0;
		while(pt!=NULL){
			parameters = (char**)realloc(parameters, sizeof(char*)*(i+1));
			parameters[i]= (char*)realloc(parameters[i], sizeof(char)*30);
			strcpy(parameters[i],pt);
			pt = strtok(NULL, " ");
			i++;
		}
		const char *commands[10] = {"exit", "div", "mul", "rakam", "cat", "clear"};
		int k = 0;
		for(k = 0 ; k < 6 ; k++){
			if(strcmp(commands[k], parameters[0])==0){
				k=-1;
				break;
			}
		}

		if(k!=-1 && strlen(inputValue)>0){
			printf("Geçersiz komut!\n");
			continue;
		}
		if(strcmp(parameters[0],"exit")==0){
			exit(0);
		}
		
		if(strlen(inputValue)>0){
			int *child;
			int fvD = -1;
			char **parameterValues;
			if(i>3){
				fvD = fork();
			}
			if(fvD==0){
				parameterValues = (char**)malloc(sizeof(char*)*2);
				int d = 0;
				for(d = 0 ; d<2 ; d++){
					parameterValues[d] = (char*)malloc(sizeof(char)*20);
				}
				
				strcpy(parameterValues[0], parameters[5]);
				strcpy(parameterValues[1], parameters[6]);
				
				if(i>6){
				i=3;
				}
				else{
				i=2;
				}
			}
			else if(fvD != 0){
				parameterValues = (char**)malloc(sizeof(char*)*2);
				int t=0;
				for(t = 0 ; t<2 ; t++){
					parameterValues[t] = (char*)malloc(sizeof(char)*20);
				}
				if(i>1){
				strcpy(parameterValues[0], parameters[1]);
				}
				if(i>2){
				strcpy(parameterValues[1], parameters[2]);
				}
				if(i>3){
					i=3;
				}
			}
			if(i==3){
				int fv=-1;
				if(fvD!=0){
					fv = fork();
				}
				if(fv==0 || fvD==0){
					char com[15];
					if(fvD==0){
					strcpy(com, parameters[4]);
					}
					else{
					strcpy(com, parameters[0]);
					}
					if(strcmp(com,"mul")==0){
						parameterValues[2]=NULL;
						child = execve("mul",parameterValues);
						perror("hata");
					}
					else if(strcmp(com,"div")==0){
						parameterValues[2]=NULL;
						child = execve("div",parameterValues);
					}
					exit(0);
				}
				else{
				wait(&child);
				}

			}
			else if(i==2){
				int fv = fork();
				if(fv==0){
				if(strcmp(parameters[0],"rakam")==0){
					parameterValues[1]=NULL;
					child = execve("rakam",parameterValues);
				}
				else if(strcmp(parameters[0],"cat")==0){
					printf("cat: %s\n",parameterValues[0]);
				}
				exit(0);
				}
				else{
				wait(&child);
				}				
			}
			else if(i==1){
				system("clear");
			}
			else{
				printf("Eksik veya fazla parametre gridiniz!");
			}
			wait(&child);
		}
	}

return 0;
}
