#include <stdio.h>
#include <stdlib.h>
// define the node class
typedef struct Node{
	int value;
	struct Node* next;
} Node;


int hashInsert(Node** bigTable,int thisNum,int hashedVal, int numCollision){
	// allocate space for new Node
	struct Node** tempTable=bigTable;
	struct Node* toBePutIn= (struct Node*) malloc(sizeof(Node));
	int tempCollision=numCollision;
	// no collison case
	if(tempTable[hashedVal]==NULL){
		toBePutIn->next=NULL;
		toBePutIn->value=thisNum;
		tempTable[hashedVal]=toBePutIn;
	}else{ // something there, collision case
		toBePutIn->value=thisNum;
		toBePutIn->next=tempTable[hashedVal];
		tempTable[hashedVal]=toBePutIn;
		tempCollision++; // increases number of collisions
	}
		
	
	return tempCollision; // returns that one greater collision occured
}
int findIt(struct Node** thisBigTable,int looking,int lookingHash){
	struct Node** tempLooking=thisBigTable;
	struct Node* atThisSpot=thisBigTable[lookingHash];
	if(tempLooking[lookingHash]==NULL){
		return 0;
	}
	else{
		while(atThisSpot!=NULL){
			if(atThisSpot->value==looking){
				return 1;
			}
			atThisSpot=atThisSpot->next;
		}
	}
	
	return 0;
}

// ----------- placeholder for main method--------------------
int main(int argc, char** argv){
	// open the file
	FILE *fptr=fopen(argv[1],"r");
	if(fptr==NULL){
		printf("error");
		return 0;
	}
	char operation;
	int number;
	//create the hash table
	struct Node** table;
	// allocate inital value to NULL
	table=(struct Node**)malloc(10000*sizeof(Node*));
	int hashVal,collisionCount,searchOutcome,searchCount;
	collisionCount=0;
	searchCount=0;
	// begin to scan in inputs
	while(fscanf(fptr,"%c\t%d\n",&operation,&number)!=EOF){
		if(operation=='i'){
			hashVal=number%10000;
			if(hashVal<0){
				hashVal+=10000; // handle negative hash values
			}
			collisionCount=hashInsert(table,number,hashVal,collisionCount);
		}
		else if(operation=='s'){
			hashVal=number%10000;
			if(hashVal<0){
				hashVal+=10000;
			}
			searchOutcome=findIt(table,number,hashVal);
			if(searchOutcome==1){
				searchCount++;
			}
		}
	}
	printf("%d\n%d",collisionCount,searchCount);
	fclose(fptr);	
			
	
	return 0;
}
