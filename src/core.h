#ifndef CORE_H
#define CORE_H

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    long double value;
    char operator;
    struct node* middle;
    struct node* next;
    struct node* prev; 
}node;

int syntaxCheck(char* string);

node* listFormer(char* string);


#endif