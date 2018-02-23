//import libraries 
#include <stdio.h>
#include <stdlib.h>

//create constant size for array 
#define SIZE 12

//create array 
int a[SIZE];

//pass in pointer int, as ponter points to different position make value =0 
void init(int* b){
    int n;
    for(n=0;n<SIZE;n++)b[n]=0;
}

//print each value in array
void print(void){
    int n;
    for(n=0;n<SIZE;n++)printf("%d,",a[n]); //%d -formatting expression for decimal
    printf("%d",a[n]); //print last space in array so there will be no comma 
    printf("\n");
}

//write values of array into file 
void write_data(void){
    FILE* file; //create pointer file type
    int n;
    file=fopen("DATA","w"); //open file to write 
    for(n=0;n<SIZE;n++)fprintf(file,"%d\n",a[n]); //print values of array one each line 
    fclose(file); //close file 
}

//open file and add vlaues in file to array 
void read_data(void){
    FILE*file;
    int n; //position in array 
    int val;

    n=0;
    file=fopen("DATA", "r"); //open file 'DATA' to read
    while((n<SIZE)&&(fscanf(file,"%d",&val)==1)){ //scan file and move pointer 
        a[n]=val; //add read value into array
        n++; //move down array
    }
    if(n<SIZE)printf("MISSING DATA \n"); //if there is no more data in file 
    if(fscanf(file,"%d", &val)!=EOF) //EOF = end of file 
        printf("too much \n"); //reach end of file
    fclose(file);
}

int main(void){
    init(a);
    print();
    write_data();
    

    //read_data();
    //print();

    return(0);
}