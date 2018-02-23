#include <stdio.h>
#include <stdlib.h>

#define SIZE 256

typedef int MYTYPE; //create new int type 

//new type caleld stack with int and mytype array of size SIZE
typedef struct stack{
    int stack_top; //index of top stack
    MYTYPE data[SIZE];//array of stack elements 
}stack;

/*--------------------------------------*/
//memory allocation 
stack* make_stack(void){
    stack *st;//pointer of type stack
    st=(stack *)malloc(sizeof(stack)); //allocates requested memory of size stack and returns pointer type stack 
    st->stack_top=-1; //(*st).stack_top=-1, changes the value of stack_top to -1 
    return(st); 
}

//deallocate, takes pointer s of type stack 
void free_stack(stack *s) {
    if(s!=NULL)free(s); //deallocates memory of s 
}

//pushes a new value to top of stack, outputs if stack is full 
void push(stack *s,MYTYPE val){
    if((s->stack_top)>SIZE){    //stack size larger than max size 
        printf("STACK FULL \n");
        return;
    }
    s->stack_top++;//adds 1 to stack_top 
    s->data[s->stack_top]=val; //adds new value in data to top of stack 
}

//returns top value of stack, output if stack is empty
MYTYPE top(stack *s){
    if(s->stack_top<0){ //stack size less than 0 
        printf("STACK EMPTY \n");
        return(0);
    }
    return(s->data[s->stack_top]); //return top value of stack
}

//pop top value of stack, output if empty 
void pop(stack *s){
    if(s->stack_top<0){
        printf("STACK EMPTY \n");
        return;
    }
    s->stack_top--; //goes one down stack
}

int main(void){
    stack* st1; //new stack initialize
    stack* st2;
    st1=make_stack(); //make stack 
    st2=make_stack();
    push(st1, 12); //add value to top of stack 
    printf("TOP IS %d \n", top(st1));
    return(0);
}

