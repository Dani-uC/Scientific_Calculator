#include "core.h"



//__________________syntax checker___________________
/*
    -The syntax checker function checks for mathemathically correct arrangement of operators and operands
    that the calculator can parse and calculate.
*/


int syntaxCheck(char * string){
    int parentheses_open=0,parentheses_close=0,consecutive=0;
    int length = strlen(string);

    //mathematical expression cannot begin with any of the these
    if(string[0]=='*' || string[0]=='/' || islower(string[length-1]) || string[0]=='z' || string[0]=='n' || string[0]=='s')
        return 0;

    for(int i=0;i<length; i++){
        if(islower(string[i])){
            if((string[i]==string[i+1]) )
            return 0;
        }
        

        if(string[i]=='+' || string[i]=='/' || string[i]=='*' || string[i]=='-' || string[i]=='z' || string[i]=='n' || string[i]=='s' || string[i]=='.'){

            
            if(string[i]==string[i+1])
                return 0;
            if(string[i]=='/' && string[i+1]=='*')
                return 0;
            if(string[i]=='*' && string[i+1]=='/')
                return 0;
            if(string[i]=='+' && string[i+1]=='-')
                return 0;
            if(string[i]=='-' && string[i+1]=='+')
                return 0;
            if((string[i]=='z'  && !(isdigit(string[i+1])) && !(isdigit(string[i-1]))) || (string[i]=='n'  && !(isdigit(string[i+1])) && !(isdigit(string[i-1])))  || (string[i]=='s'  && !(isdigit(string[i+1])) && !(isdigit(string[i-1]))) )
                return 0;
        }
        if(string[i]=='(')
        parentheses_open++;
        if(string[i]==')')
        parentheses_close++;
    }

    if(parentheses_open!=parentheses_close){
        printf("incomplete parenthesis:");
        return 0;
    } 
    
return 1;
    
}




//__________________listFormer___________________
/*
    -The list former function trasverses through an array ( string ) creating a doubly linked list node for each operand, operator and special
     function.
    -For special functions that require only one variable (for example :sin x ) ,a single node is made with the function identifier ('b' for cosine )
     and linked to the variable node as a separate branch.
    -Other mathematical operations that require two variables are placed in the main doubly linked list ( +, *, hyp ) alonside operands.
    -Operator nodes come between operand nodes in the doubly linked list. 
*/


node* listFormer(char* string){
    int node_no=0;
    int index=0;
    char buffer[100];
    node* head=NULL;
    node* temp=NULL;
    node* tail=NULL;

    for(int i=0; i < (strlen(string)); i++){
        if(isdigit(string[i]) || string[i]=='.'){
            buffer[index]=string[i];
            index++;

            if(!(isdigit(string[i+1])) && string[i+1]!='.'){
                buffer[index]='\0';
                
                node* currnode=(node*)malloc(sizeof(node));
                if(currnode !=NULL){
                    node_no++;
                    currnode->next=NULL;
                    currnode->prev=NULL;
                    currnode->middle=NULL;
                    currnode->value=strtold(buffer,NULL);
                    
                    currnode->operator='N';


                    if(node_no==1)
                        head=currnode;
                    else
                        temp->next=currnode;
                    
                    tail=currnode;
                    currnode->prev=temp;
                    temp=currnode;


                    if(isalpha(string[i-index]) && string[i-index]!='s' && string[i-index]!='n' && string[i-index]!='z' ){

                        node* branch=(node*)malloc(sizeof(node));
                        if(branch !=NULL){
                            node_no++;
                            branch->next=NULL;
                            branch->prev=NULL;
                            branch->middle=NULL;
                            branch->operator=string[i-index];
                            
                            currnode->middle=branch;
                        }
                         else{
                    printf("***************malloc Error***************");
                }
                    }


                }
                else{
                    printf("***************malloc Error***************");
                }
                index=0;  
            }
            
        }
        if(string[i]=='+' || string[i]=='-' || string[i]=='*' || string[i]=='/' || string[i]=='s' || string[i]=='n' || string[i]=='(' || string[i]==')' || string[i]=='z'){

                node* currnode=(node*)malloc(sizeof(node));
                if(currnode !=NULL){
                    node_no++;
                    currnode->next=NULL;
                    currnode->prev=NULL;
                    currnode->middle=NULL;

                    currnode->operator=string[i];
                    //printf("%c\n",currnode->operator);
                    if(node_no==1)
                        head=currnode;
                    else
                        temp->next=currnode;
                    
                    tail=currnode;
                    currnode->prev=temp;
                    temp=currnode;
                }
                else{
                    printf("***************malloc Error***************");
                } 
                if(string[i]=='(' && (string[i-1]!='s' || string[i-1]!='n' || string[i-1]!='z')){

                        node* branch=(node*)malloc(sizeof(node));
                        if(branch !=NULL){
                            node_no++;
                            branch->next=NULL;
                            branch->prev=NULL;
                            branch->middle=NULL;
                            branch->operator=string[i-1];
                            
                            currnode->middle=branch;
                        }
                         else{
                    printf("***************malloc Error***************");
                }
            } 

        }
    }
    node_no=0;

    return head;
}

