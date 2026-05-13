#include "input.h"

/*
    -The getInput function is responsible for taking input from the console using the fgets function 
     and the input is stored in the local_buffer array.
    -Unwanted characters like newline, space and tabs are removed.
*/

int getInput(char* buffer){
    int index=0;
    char local_buffer[MAX_LENGTH];         
    fgets(local_buffer,sizeof(local_buffer),stdin);
    int length=strlen(local_buffer);
    
    for(int i=0;i<length;i++){
        if(local_buffer[i]!=' ' && local_buffer[i]!='\t' && local_buffer[i]!='\n'){
            buffer[index]=local_buffer[i];
              
            if(!(islower(buffer[index])) && buffer[index]!='+' && buffer[index]!='-' &&  buffer[index]!='/'
             &&  buffer[index]!='*' &&  buffer[index]!='.' &&  !(isdigit(buffer[index])) &&  buffer[index]!='(' 
             &&  buffer[index]!=')' ){
                return 0;
            }

            index++;
            buffer[index]='\0';

        }
    }
  return 1;  
    
}
