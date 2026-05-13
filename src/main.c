#include "input.h"
#include "core.h"
#include "calculateFunc.h"
#include <stdio.h>

int main (int argc,char* argv[]) {
    if(argc > 1 && !(strcmp("help",argv[1]))){
        printf("\tThis is a console based scientific calculator\n");
        printf("a--sin\nb--cos\nc--tan \nd--arcsin\ne--arccos\nf--arctan\ng--sinh\nh--cosh\ni--tanh\nj--arcsinh\nk--arccosh\nl--arctanh\n");
        printf("m--e^x\nn--hyp(x,y)\no--log2 x \np--log10\nq--ln x\nr--10^x\ns--x^y\nt--sqrt x\nu--cbrt x\nv--square\nw--cube\nx--!\n");
        printf("y--1/x\nz--multiroot(x root y)\n");
        printf("\n");
        printf("symbols of functions with two variables are to be placed between the variables eg: 2n3 for hyp(2,3)\n");
        printf("\n");
        printf("symbols of functions with one variable should be placed before the variable eg: a30 for sin 30\n");
        printf("\n");
        printf("Other mathematical symols include +,-,/,*,(,)\n");
        printf("\n");
        printf("Use parentheses to show preecedence,all alphabets must be in lower case\n");
        printf("\n");
        printf("Brought to you by Troonics\n");
    }


    node* head=NULL;
    node* tail=NULL;
    node* temporary=NULL;
    int state;
    char buffer_input[MAX_LENGTH];
    while(1){
    state=getInput(buffer_input);
    if(!state){
        printf("********invalid input**************\n");
        continue;
    }
    state=syntaxCheck(buffer_input);
       if(!state){
        printf("********Syntax Error**************\n");
        continue;
        }

    head=listFormer(buffer_input);

     addMultiplication(head);

     temporary=head;

     while(temporary!=NULL){

        tail=temporary;
        temporary=temporary->next;
    }

    temporary=estimate(head,tail);

    if(temporary!=NULL){
        printf("\t%Lf\n",temporary->value);

    }

    else{
        printf("********Math Error*********\n");
        continue;
    }

}


    return 0;
}