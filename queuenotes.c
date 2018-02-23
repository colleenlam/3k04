#include <stdio.h>
#include <stdlib.h>

#define SIZE 16

typedef int MYTYPE;

MYTYPE data[SIZE]; //new array data of size SIZE

int front;
int back;

//initialize variables 
void init(void){
    front=1;
    back=0;
}

//returns true false, is queue empty or not 
int empty(void){
    return((back+1)%SIZE==front); 
}

void push(MYTYPE val){
    if((back+2)%SIZE==front){ //if queue is full 
        printf("Full \n");
        return;
    }
    back=(back+1)%SIZE; //increase back value  
    printf("%d \n", back);
    data[back]=val; //make back value of queue equal val 
}

MYTYPE pop(void){
    MYTYPE val;
    if(empty()){ //if empty function returns true 
        printf("Empty \n");
        return(0);
    }
    val=data[front]; //store top value in var 
    front=(front+1)%SIZE; //increase front value 
    //printf("%d \n", front);
    return(val);
}

int main(void){
    int i;
    init();
    for(i = 0; i < SIZE; i++)push(i);
    printf("The top is %d \n",pop());
	printf("The top is %d \n",pop());
	printf("The top is %d \n",pop());
}