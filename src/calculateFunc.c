#include "calculateFunc.h"

//____________estimate___________________

/*
    -The estimate function is a recursive function that invokes itself whenever it reaches a ' ( ' node  such that the node immediately after
     the open parenthesis node is passed as an argument to the new function call.
    -The new function call returns a calculated node when it reaches the corresponding closing parenthesis or is recursed if another open parenthesis 
     node is encountered before the closing parenthesis   (" nested parenthesis ").
*/



node* estimate(node* head,node* tail){
    node* current=head;
    node  *hold=NULL;
    node* answer=NULL;

        
    while(current!=NULL ){
        
       if(current==head && current->operator==')')
           return NULL;
        

        if( current->operator==')')
            break;
                  

        if(current->operator=='('){
             
             
            answer=estimate(current->next,NULL);

            if(answer==NULL)
                return NULL;
            

            if(current->middle!=NULL)
                answer->middle=current->middle;

            
            if(current->prev!=NULL){
             current->prev->next=answer;
             answer->prev=current->prev;



            }
            

            else{
                head=answer;
                answer->prev=NULL;


            }
                

            
            hold=answer->next;
            answer->next=answer->next->next;
            if(answer->next==NULL){
                tail=answer;
                break;
            }
            answer->next->prev=answer;


                
            
            free(hold);
            free(current); 

            current=answer;
            

         if(current->prev!= NULL && current->next!=NULL){

            if(current->prev->operator=='(' && current->next->operator==')'){
               return NULL;
            }
         }
        

        }
    
       
                
    
        current=current->next;



    }
    

        if(head->operator=='+' && head->next->operator=='N' ){
        hold=head;
        head=head->next;
        head->prev=NULL;
        free(hold);
        hold=NULL;
    }
     if(head->operator=='-' && head->next->operator=='N' ){
        head->next->value*=-1;
        hold=head;
        head=head->next;
        head->prev=NULL;
        free(hold);
        hold=NULL;
    }

             
               
    if(current!=NULL){ 
        
    if(current->operator==')')
    return calculate(head,current->prev);

    }
    
    
   return calculate(head,tail); 
}



//____________________add multiplication________________
/*
    -This function takes care of the parenthesis multiplication syntax { "2(3)  or 2a45"} by inserting a new node between the parenthesis and the 
     multiplying number { "2*(3) or 2*a45"} where a45 is sin 45
*/

void addMultiplication(node* nnode){
     
    node* current=nnode->next;

    while(current!=NULL){

        if((current->operator=='('  && (current->prev->operator=='N' || current->prev->operator==')')) || (current->middle!=NULL && current->prev->operator=='N')){

 

            node* ins_node=(node*)malloc(sizeof(node));
                if(ins_node !=NULL){
                    ins_node->next=NULL;
                    ins_node->prev=NULL;
                    ins_node->middle=NULL;
                    ins_node->operator='*';
                        
                   current->prev->next=ins_node;
                   ins_node->prev=current->prev;
                   ins_node->next=current;
                   current->prev=ins_node;
                    
                            

                }
                else{
                    printf("***************malloc Error***************");
                    exit(0);
                 }
    
        }    
        current=current->next;
        
    }



}


//____________calculate___________________

/*
    -The calculate function takes the doubly linked list and performs each mathematical operation on the nodes in the order of BODMAS
    -It is called in the estimate function.
    -It calls the corresponding function for each mathematical operation
*/


node* calculate(node* start, node* stop){
node* current=start;
    

    while(current != stop->next){
        if(current->operator=='N' && current->middle!=NULL)
         specialFunc(current);
      current=current->next;
    }
    current=start;
    while(current != stop->next){
        if(current->operator=='z')
            current=mrt(current->prev, current->next);
      current=current->next;
    }
            current=start;
    while(current != stop->next){
        if(current->operator=='n')
            current=hyp(current->prev, current->next);
      current=current->next;
    }

        current=start;
    while(current != stop->next){
        if(current->operator=='s')
            current=exponent(current->prev, current->next);
      current=current->next;
    }

        current=start;
    while(current != stop->next){
        if(current->operator=='/')
          current=divide(current->prev, current->next);

        if(current==NULL)
          return NULL;

      current=current->next;
    }

        current=start;
    while(current != stop->next){
        if(current->operator=='*')
           current=multiply(current->prev, current->next);
      current=current->next;
    }
    

        current=start;
    while(current != stop->next){
        if(current->operator=='+')
           current=add(current->prev, current->next);
      current=current->next;
    }
    
    
        current=start;
    while(current != stop->next){
        if(current->operator=='-')
           current=subtract(current->prev, current->next);
      current=current->next;
    }
    

    return start;
}

/*
    -The following functions below are called by the calculate function 
    -they perform operations that involves two operand node, store the answer in the preceeding node (overwrite )and remove the irrelevant node from the
     list (they remove the operator node and the second operand node ).
*/


node* add(node* operand1, node* operand2){
    operand1->value+=operand2->value;
    operand1->next=operand2->next;
    if(operand2->next!=NULL)
    operand2->next->prev=operand1;
    
    
    free(operand2->prev);
    free(operand2);


    return operand1;
}

node* subtract(node* operand1, node* operand2){
        operand1->value-=operand2->value;
    operand1->next=operand2->next;
    if(operand2->next!=NULL)
    operand2->next->prev=operand1;

    free(operand2->prev);
    free(operand2);

    return operand1;
}

node* divide(node* operand1, node* operand2){
    if(operand2->value==0){
        return NULL;
    }

    operand1->value/=operand2->value;
    operand1->next=operand2->next;
    if(operand2->next!=NULL)
    operand2->next->prev=operand1;

    free(operand2->prev);
    free(operand2);

    return operand1;
}

node* multiply(node* operand1, node* operand2){
        operand1->value*=operand2->value;
    operand1->next=operand2->next;
    if(operand2->next!=NULL)
    operand2->next->prev=operand1;

    free(operand2->prev);
    free(operand2);

    return operand1;
    
}

node* exponent(node* operand1, node* operand2){
    operand1->value=powl(operand1->value, operand2->value);
    operand1->next=operand2->next;
    if(operand2->next!=NULL)
    operand2->next->prev=operand1;

    free(operand2->prev);
    free(operand2);

    return operand1;
    
}

node* mrt(node* operand1, node* operand2){
    operand1->value=powl(operand2->value,inverse(operand1->value));
    operand1->next=operand2->next;
    if(operand2->next!=NULL)
    operand2->next->prev=operand1;

    free(operand2->prev);
    free(operand2);

    return operand1;
       
}

node* hyp(node* operand1, node* operand2){
    operand1->value=hypotl(operand2->value,operand1->value);
    operand1->next=operand2->next;
    if(operand2->next!=NULL)
    operand2->next->prev=operand1;

    free(operand2->prev);
    free(operand2);

    return operand1;
       
}


// -These functions are custom mathematical functions that are not in the math.h library



long double inverse(long double operand){
      return 1/operand;
}

long double factorial(long double operand){
    int j=1;
    int x=(int)operand;
    if(x==operand && x < 13){
        for(int i=1;i<=x;i++)
        j*=i;
    }
    else{
        printf("*********math Error!!!***********");
        exit(0);
    }

    return (long double)j;

}




//______________special function______________
/*
    -This function resolves all the special functions that are branch node and require only one variable.
    -The special function is perforemed on the variable node and the branch node is deleted.
*/

void specialFunc(node* operand){
    switch (operand->middle->operator){
        case 'a':
            operand->value=(operand->value/180)*PI;
            operand->value=sinl(operand->value);
            free(operand->middle);
             break;
        case 'b':
            operand->value=(operand->value/180)*PI;
            operand->value=cosl(operand->value);
            free(operand->middle);
             break;
        case 'c':
            operand->value=(operand->value/180)*PI;
            operand->value=tanl(operand->value);
            free(operand->middle);
             break;
        case 'd':
            operand->value=asinl(operand->value);
            operand->value=(operand->value/PI)*180;
            free(operand->middle);
             break;
        case 'e':
            operand->value=acosl(operand->value);
            operand->value=(operand->value/PI)*180;
            free(operand->middle);
             break;
        case 'f':
            operand->value=atanl(operand->value);
            operand->value=(operand->value/PI)*180;
            free(operand->middle);
             break;
        case 'g':
            operand->value=sinhl(operand->value);
            free(operand->middle);
             break;
        case 'h':
            operand->value=coshl(operand->value);
            free(operand->middle);
             break;
        case 'i':
            operand->value=tanhl(operand->value);
            free(operand->middle);
             break;
        case 'j':
            operand->value=asinhl(operand->value);
            free(operand->middle);
             break;
        case 'k':
            operand->value=acoshl(operand->value);
            free(operand->middle);
             break;
            operand->value=atanhl(operand->value);
            free(operand->middle);
             break;
        case 'm':
            operand->value=expl(operand->value);
            free(operand->middle);
             break;
        case 'o':
            operand->value=log2l(operand->value);
            free(operand->middle);
             break; 
        case 'p':
            operand->value=log10l(operand->value);
            free(operand->middle);
             break; 
        case 'q':
            operand->value=logl(operand->value);
            free(operand->middle);
             break; 
        case 'r':
            operand->value=powl(10,operand->value);
            free(operand->middle);
             break; 
        case 't':
            operand->value=sqrtl(operand->value);
            free(operand->middle);
             break;
        case 'u':
            operand->value=cbrtl(operand->value);
            free(operand->middle);
             break; 
        case 'v':
            operand->value=powl(operand->value,2);
            free(operand->middle);
             break; 
        case 'w':
            operand->value=powl(operand->value,3);
            free(operand->middle);
             break; 
        case 'x':
            operand->value=factorial(operand->value);
            free(operand->middle);
             break; 
        case 'y':
            operand->value=inverse(operand->value);
            free(operand->middle);
             break; 
    }
}
