#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int val;
	struct Node* left;
	struct Node* right;
} Node;



void insert(int value,struct Node* top){
	// establish the new node of the tree
	struct Node *toBePutIn= (struct Node*)malloc(sizeof(struct Node));
	toBePutIn->val=value;
	toBePutIn->right=NULL;
	toBePutIn->left=NULL;
	// find where to insert 
	struct Node* tempHead=top;
	struct Node* before=top;
	int cValue,bValue;
	cValue=tempHead->val;
	bValue=tempHead->val;
	while(tempHead!=NULL){
		if(value>cValue){
			// current Node and before Node both smaller
			// iterate one to the right- look for bigger values
			before=tempHead;
			tempHead=tempHead->right;
			bValue=before->val;
			if(tempHead==NULL){
				break;
			}
			cValue=tempHead->val;
		}
		else if(value<cValue){
			// current Node & previous Node both greater
			// iterate left to look for smaller value
			before=tempHead;
			tempHead=tempHead->left;
			bValue=before->val;
			if(tempHead==NULL){
				break;
			}
			cValue=tempHead->val;
		}
		else{
			return; // checks duplicates
		}
	}
	//tempHead is now NULL and thus must check before value
	if(value<bValue){
		// value before is greater, insertion must happen to left of before
		before->left=toBePutIn;
		
		// all other sides still have nothing in them
	}
	else{
		// value before is less, insertion happens to right of before 
		before->right=toBePutIn;
		
	}
	return;
} 

void print(Node* printed){
	if(printed==NULL){
		return;
	}
	print(printed->left);
	printf("%d\t",printed->val);
	print(printed->right);			
}
void postFree(Node* end){
	if(end == NULL){
		return;
	}
	postFree(end->left);
	postFree(end->right);
	free(end);
}


//-----placeholder for main method----//
int main(int argc, char** argv){
	if(argc<2){
		printf("\n");
		return 0;
	}
	FILE *fptr=fopen(argv[1],"r");
	// Check if the file exists
	if(fptr==NULL){
		printf("error");
		return 0;
	}
	char operation;
	int value;
	struct Node* head;
	head=NULL;
	while(fscanf(fptr,"%c\t%d\n",&operation,&value)!=EOF){
		if(operation=='i'){
			if(head==NULL){//first term into the list
				head=(struct Node *)malloc(sizeof(struct Node));
				head->val=value;
				head->left=NULL;
				head->right=NULL; // iterate to find the next thing to do
			}
			else{ // already an established head on top
				insert(value,head);
			}
		}
	}
	// TO-DO: print out the list using an In-Order Traversal
	print(head);
	postFree(head);			
	fclose(fptr);
	return 0;
}

