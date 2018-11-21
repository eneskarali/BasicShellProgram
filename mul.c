#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strtoint(char* charnums)
{
 int number=0;
 int index=0;
 while(charnums[index])
 {
    if(('0'<=charnums[index]) && (charnums[index]<='9'))
    {

    if(!number)
        number= ( (int) charnums[index]) - 48;
    else
    {
        number = (number *= 10) + ((int) charnums[index] - 48);
    }
    index++;
         }
         else
         {
            number=-1;
            break;
         }
 }
 return number;
}
int main(int argc , char *argv[]){
	
	if(strtoint(argv[0])==-1 || strtoint(argv[1])==-1){
		printf("Hatali parametre girisi!\n");
		
	}
	else{
	printf("%s * %s = %d\n",argv[0],argv[1],atoi(argv[0])*atoi(argv[1]));
}

return 0;
}
