#include <stdio.h>
#include <stdlib.h>

   typedef struct Node{
    int data;
    struct Node* next;
   }
   Node;
   struct Node * head; //linkedList creation
   
   void Insert(int value){
		// make a new Node from the value given
		struct Node *toBePutIn=(struct Node *)malloc(sizeof(struct Node));
		toBePutIn->data=value;
		toBePutIn->next=NULL;
		struct Node * tempHead=head;
		struct Node * before=head;
		if(head==NULL){
			toBePutIn->next=head;
			head=toBePutIn;
			return;
		}
		else if(head->data > toBePutIn-> data){
			// means first node is greater than input
			// insert in front of list
			toBePutIn->next = head;
			head=toBePutIn;
			return;
		}
		else{
		while(tempHead!=NULL){
			if(toBePutIn->data <= tempHead->data){
				// inserts after when it finds a value that is equal 
				// or smaller
				toBePutIn->next = before->next;
				before->next = toBePutIn;
				return; // insertion complete
			}
			//iterator thru the list
			before=tempHead;
			tempHead=tempHead->next;
			if(tempHead==NULL){ 
				// tempHead reaches end, add at the tail
				before->next = toBePutIn;
				return;
		}
	}
}
}
		// all nodes less, must be inserted @ the end 
		
	

 
   void DeleteIt(int value ){
   	//deletes the value in the list that is given
	struct Node * tempHead= head;
	struct Node * before=head;
	// nothing to delete
	if(tempHead==NULL){
		return;
	}
	// deleting the first node	
    if(head->data == value){
		head=head->next;
		return;
	}	
	// iterating to find value
	while(tempHead!=NULL){
		if(tempHead->data == value){
			before->next=tempHead->next;
			return;
		}
		before=tempHead;
		tempHead=tempHead->next;
	}	

	// reconfigure the node connections

	
	return;
}
int nodeAmount(Node * comingIn){
	// final output of the program
	int temp=0;
	struct Node* ptr= comingIn;
	while(ptr!=NULL){
		temp++;
		ptr=ptr->next;
	}
	return temp;
}
void removeDuplicates(Node * head){ // get rid of dups after counting
	struct Node* tempHead=head;
	struct Node* nextNode;
	if(tempHead==NULL){
		return;
	}
	while(tempHead->next != NULL){
		if(tempHead->data == tempHead->next->data){
			nextNode=tempHead->next->next;
			free(tempHead->next);
			tempHead->next=nextNode;
		}else{
			tempHead=tempHead->next;
		}
	}
	return;
}

//--------placeholder for main method-------//

 int main(int argc, char ** argv){
	FILE *fptr=fopen(argv[1],"r");
	// Check if the file exists
	if(fptr==NULL){
		printf("error\n");
		return 0;
	}
	// Quietly do nothing if empty file
	if(argc<2){
	   printf("\n");
	   return 0;
	   
	}
	// if there is only 1 thing in input
	char operation;
	int value;
	// variables for i/d
	head=NULL;
	// entry to list
	while(fscanf(fptr,"%c\t%d\n",&operation,&value)==2){
	   if(operation=='i'){//insertions
			Insert(value);
		   //inserts in all cases of linked list
		}
	
	   else if(operation=='d'){//deletions
			DeleteIt(value);
	   }
	   
	}
	
	int numberNodes;
	numberNodes=nodeAmount(head);
	printf("%d\n",numberNodes);
	removeDuplicates(head);
	while(head!=NULL){ // prints the list
		printf("%d\t",head->data);
		head=head->next;
	} 
	free(head);
	fclose(fptr);
	return 0; // final statement of main
   }   
 
   
