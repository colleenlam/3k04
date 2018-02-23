#include <stdio.h>
#include <stdlib.h>

#define SIZE 256

typedef int DATA;
typedef int TREE_T;
DATA my_tree[SIZE];//tree of size SIZE

//if tree is valid 
int valid_tree(TREE_T tree){
    return((tree>0)&&(tree<=SIZE)); //
}

//ACCESS FUNCTIONS 

//returns root index of tree
TREE_T get_root(void){
    return(1);
}

//return left child of the tree
TREE_T get_left_child(TREE_T tree){
    if(!valid_tree(tree)){ //tree is invalid 
        printf("Invalid tree \n");
        return(1); //return root node index
    }
    if(tree*2>=SIZE){ //left child index exceeds max 
        printf("No left child \n");
        return(tree); //return index of inputted val
    }
    return(tree*2);//return index of left child 
}

//get right child of a node 
TREE_T get_right_child(TREE_T tree){
    if(!valid_tree(tree)){ //tree is invalid 
        printf("Invalid tree \n");
        return(1);
    }
    if(tree*2+1>SIZE){ //right child index exceeds max size
        printf("No right child \n");
        return(tree); //return index inputted
    }
    return(tree*2+1); //return right child index 
}

TREE_T get_parent(TREE_T tree){
    if(!valid_tree(tree)){ //tree is invalid 
        printf("Invalid tree \n");
        return(1);
    }
    return(tree/2); // return parent node 
}

void set_value(TREE_T tree, DATA val){
    if(!valid_tree(tree)){
        printf("Invalid tree \n");
        return;
    }
    my_tree[tree]=val; //set index tree in tree w val
}

DATA get_value(TREE_T tree){
    if(!valid_tree(tree)){
        printf("Invalid tree \n");
        return(0);
    }
    return (my_tree[tree]); //return value at index tree
}


//----------------------------------------------------------------
// The user can only see this:
// This is called the declaration, or interface
TREE_T get_root(void);
TREE_T get_parent(TREE_T tree);
TREE_T get_left_child(TREE_T tree);
TREE_T get_right_child(TREE_T tree);
void set_value(TREE_T tree,DATA val);
DATA get_value(TREE_T tree);

int main(void){
    // You can use the tree here without knowing how it works
	///We created a "tree language"
	TREE_T t1;
	TREE_T t2;
	t1=get_root();
	set_value(t1,12);
	t2=get_right_child(t1);
	set_value(t2,11);
	set_value(get_left_child(t1),15);

	printf("The root value is %d \n",get_value(get_root()));
	printf("The Right child  is %d \n",get_value(t2));

	if(get_parent(t2)==t1){
		printf("Yes its the parent \n");
	}
	

	return(0);
}