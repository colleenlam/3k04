#include <stdio.h>
#include <stdlib.h>

#define SIZE 16

typedef int MYTYPE;

MYTYPE a[SIZE];

//initialize array with decreasing values 
void init(){
    int i;
    for(i=0;i<SIZE;i++)a[i]=SIZE-i;
}

void print(MYTYPE* a){
    int i;
    for(i=0;i<SIZE-1;i++)printf("%d, ",a[i]);//print array 
    printf("%d\n",a[i]);
}

//finds position of value 
int find(MYTYPE *a, MYTYPE b){
    int i;
    for(i=0;i<SIZE;i++)//go through array 
        if(a[i]==b)return(i);//if value equals b return position 
    return(-1); //return -1 if not in array 
}

//ONLY WORKS IF YOU INSERT A AS SMALLER VALUE THAN B
int bin_search(MYTYPE* data, MYTYPE val, int a, int b){
    int mid;
    mid=(a+b)/2; //create mid value to split in two 

    printf("Called with a=%d b=%d mid=%d \n", a,b, mid);
    if(data[mid]==val)return(mid); //if mid value is value wanted
    if(a==b)return(-1); //searched through and value not found 
    if(data[mid]>val) //mid value is bigger than wanted
        return(bin_search(data, val, mid+1, b)); //search upper half 
    else
        return(bin_search(data, val,a, mid-1));
}

//true false if a greater than b
int greater(int a, int b){
    return(a>b);
}

//true false if a smaller than b
int smaller(int a, int b){
    return(a<b);
}

//swaps values in position i and j
void swap(int i, int j){
    MYTYPE tmp;
    tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
}

void sort(MYTYPE *data, int (*compare)(MYTYPE a, MYTYPE b)){ //takes in array, function 
    int i, j;
    for(j=0;j<SIZE;j++)
        for(i=0;i<SIZE;i++)
            if(compare(data[i],data[i+1]))swap(i,i+1);
}

int main(void){
    init();
    print(a);
    sort(a, &greater); //orders in increasing 
    print(a);
    return(0);
    
}