#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 256

//sorts and merges 2 lists 
void merge(int *a, int i1, int j1, int i2,int j2){
    int temp[MAX_SIZE]; //create array to merge
    int i,j,k;
    i=i1; //beginning of first list
    j=i2;//beginning of second list 
    k=0;

    printf("merge called with %d %d %d %d \n", i1, j1, i2,j2);

    while(i<=j1 && j<=j2){ //first and last values of list 1 smaller than values in list 2
        if(a[i]<a[j]){ //first list 1 value smaller than second list 1 value 
            temp[k]=a[i]; //merge array adds first value of first list 
            k++;i++; //next value in merge list, next value in first list 
        }
        else //second list value smaller 
            temp[k++]=a[j++]; //else, add first value of second list and change values 
    }

    //take the rest of the lists 
    while(i<=j1) //next index in list 1 less than first index in list 2 
        temp[k++]=a[i++]; //fill next value of array with list 1 value 

    while(j<=j2)
        temp[k++]=a[j++]; 

    //transfer elements from temp[] back to a[]
     for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
}

//recursively calls merge function to sort a list 
void merge_sort(int *a, int i, int j){
    int mid;

    if(i<j){
        mid=(i+j)/2; //find mid value 
        merge_sort(a, i, mid); //sort left side of list
        merge_sort(a, mid+1, j); //sort right side of list 
        merge(a,i,mid,mid+1,j); //merge sorted sub arrays 
    }
}

//prints array 
void print_array(int* a, int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");
}

//fill array with random numbers
void fillArray(int *a, int n){
    int i;
    for(i=0; i<n; i++)a[i]=rand()%n;
}

int main(){
    srand(time(NULL)); //random value 

    int a[MAX_SIZE]; // local array for data 
    int n; 
    n=20;

    fillArray(a,n);
    print_array(a,n);
    merge_sort(a,0,n-1);
    printf("\n Sorted array is: \n");
    print_array(a,n);
    return(0);
}