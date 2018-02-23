// MvM List 

#include <stdio.h>
#include <stdlib.h>

/*----------------------- Type declaration ----------------- */

typedef int DATA;

typedef struct container{
	DATA val;
	struct container * next;
} container;


/*----------------------- Factory --------------------------*/

container* makeEle(DATA val)
{
	container* tmp;
	tmp=(container*)malloc(sizeof(container));
	if(tmp==NULL){
			printf("NO MEMORY \n");
			exit(1);
	}
	tmp->next=NULL;
	tmp->val=val;
	return(tmp);
}

/*----------------------- Access--------------------------- */ 

container* top;

void init(void)
{
	top=NULL;
}


void addList(DATA val)
{
	 container* tmp;
	tmp=makeEle(val);
	if(top==NULL)
		top=tmp;
	else{	
		tmp->next=top;
		top=tmp;
	}
}


DATA getList(void)
{

	container* tmp;
	DATA val;
	if(top==NULL){		
		printf("ERROR \n");
		return(0);
	}

	tmp=top;
	val=top->val;
	top=top->next;
	free(tmp);
	return(val);
};


void printList(container* list)
{
	container* tmp;
	tmp=top;
	while(tmp!=NULL){
		printf("VALUE is %d \n",tmp->val);
		tmp=tmp->next;
	}

}


int count(container* list)
{
	int n;
	n=0;
	while(list!=NULL){
		list=list->next;
		n++;
	}
	return(n);

}





/*----------------------- Main --------------------------- */ 

int main(void)
{
	int i;
	init();
	for(i=1;i<=10;i++)addList(i);
	printList(top);

	printf("THe size is %d \n",count(top));

	
	for(i=0;i<10;i++){
		printf("Value is %d \n",getList());
	}		
	
	
	return(0);
}