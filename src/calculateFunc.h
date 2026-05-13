#ifndef CALCULATEFUNC_H
#define CALCULATEFUNC_H

#include "core.h"

#include <math.h>

#define PI 3.14159265358979323846

node* estimate(node* head,node* tail);

void addMultiplication(node* nnode);

node* calculate(node* start, node* stop);



node* add(node* operand1, node* operand2);

node* subtract(node* operand1, node* operand2);

node* divide(node* operand1, node* operand2);

node* multiply(node* operand1, node* operand2);

node* exponent(node* operand1, node* operand2);

node* mrt(node* operand1, node* operand2);

node* hyp(node* operand1, node* operand2);




long double inverse(long double operand);

long double factorial(long double operand);


void specialFunc(node* operand);


#endif