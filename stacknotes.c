#include <stdio.h>

#define STACK_SIZE 256
int stack[STACK_SIZE];
int stack_top;

//initialize stack
void init(void){
    stack_top=-1;
}

//push new element into stack, output msg if stack is full
void push(int val){
    if(stack_top>=STACK_SIZE){//value in stack larger than size
        printf("Stack Full \n");
        return;//end loop
    }
    stack_top++;//next element in stack
    stack[stack_top]=val;//add new value 'val' to stack 
}

//return top value of the stack, 0 if stack is empty
int top(void){
    if (stack_top==-1){//top of stack element is = 1  
        printf("Stack Empty \n");
        return(0);
    }
    return(stack[stack_top]);//return top value of stack
}

//remove element from stack, print msg if stack is empty
void pop(void){
    if(stack_top==-1){//if top of stack element is =1 
        printf("Stack Empty \n");
        return;
    }
    stack_top--;//go back value in stack
}

//check if stack is empty
int is_empty(void){
    return(stack_top<0);
}

int main(void){
    init();
    push(2);
    push(3);
    printf("OUT %d \n", top());//print top value of stack
    pop();
    printf("OUT %d \n", top());
    pop();
    return(0);
}