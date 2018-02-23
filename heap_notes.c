//root value is smallest value in the heap

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 512 

typedef int DATA;

DATA heap[MAX_SIZE]; //create heap of size MAX_SIZE
int size; 

//swaps positions i and j in array 
void swap(int i, int j){
    DATA tmp; //new temp variable of type DATA
    tmp=heap[i]; 
    heap[i]=heap[j];
    heap[j]=tmp; 
}

//go up tree and check values
void fixUp(void)
{
	int i,j;
	i=size; //leaf node 
	while(i>1){
		j=i/2; //parent node 
		if(heap[i]<heap[j]) // parent node has larger value than child
			swap(i,j); //swap values
		else
			return; //end 
		i=j; //go to next parent node 
	}

}

void fixDown(void)
{
        int j,i;
        j=1; //root node
        i=2; //left child node 
        while(i<=size){ //node is not past leaf node
                // LEFT OR RIGHT CHILD ?
                if((i<=size)&&(heap[i]>heap[i+1]))i++; //left child larger than right child, switch to right node
                if(i>size)return; //past the leaf node, exit loop
                if(heap[j]>heap[i]){ //parent node larger than child node 
                                swap(j,i); //swap values 
                                j=i; //child becomes parent node
                                i=i*2; //next child node 
                }else
                        return;
        }

}

//----------------------

//print heap
void print_heap(void){
    int i;
    for(i=1; i<=size; i++)printf("%d ", heap[i]);
    printf("\n");
}

//initialize empty heap
void init_heap(void){
    size=0;
}

void put(DATA n){
    if(size==MAX_SIZE-1){ //there are no nodes
        printf("EMPTY \n");
        return; //exit loop
    }
    size++; //add node to tree
    heap[size]=n; //make next leaf node in tree have value n 
    fixUp(); //go up tree to put everything in order
}

DATA get(void){
    DATA tmp;
    if(size<=0){ //heap is empty
        printf("EMPTY \n");
        return(0); //exit loop
    }
    tmp = heap[1]; //make temp value equal to root node 
    heap[1]=heap[size]; //copy last leaf node value to root node 
    size--; //remove last node 
    if(size>1)fixDown(); //if heap greater than one node, go down tree to sort
        return(tmp);//remove value removed 
}

//------------------------

int main(void){
    int i;
    init_heap();
    put(5);
    print_heap();
    put(3);
    print_heap();

    printf("REMOVE \n");

    for(i = 0; i<=size;i++){
        printf("TOP IS %d \n", get());
        print_heap();
    }

    return(0);
}