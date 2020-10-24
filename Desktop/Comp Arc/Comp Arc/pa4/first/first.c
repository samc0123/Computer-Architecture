#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// linked list class 
 typedef struct Node{
    int data;
    char * name; 
    struct Node* next;
 } Node;
//individual gates
int NOTGate(int A){
	if (A==1){
		return 0;
	}else{
		return 1;
	}
}
int ANDGate(int B, int C){
	if(B==1 && C==1){
		return 1;
	}else{
		return 0;
	}
}
int ORGate(int D, int E){
	if(D==1 || E==1){
		return 1;
	}else{
		return 0;
	}
}
int NANDGate(int F, int G){
	if(F==1 && G==1){
		return 0;
	}else{
		return 1;
	}
}
int NORGate(int H, int I){
	if(H==1 || I==1){
		return 0;
	}else{
		return 1;
	}
}
int XORGate(int J, int K){
	if(J==1 && K==1){
		return 0;
	}
	else if(J==1 || K==1){
		return 1;
	}else{
		return 0;
	}
}
// get the number requested from the string 
int getNum(char * nameOfInput, Node * inputLink, Node * tempLink){
	int theValue;
	// traverse both lists until found
	struct Node * inputLinkTrav=inputLink;
	struct Node * tempLinkTrav=tempLink;
	while(inputLinkTrav!=NULL){
		if(strcmp(inputLinkTrav->name,nameOfInput)==0){
			theValue=inputLinkTrav->data;
		}
		inputLinkTrav=inputLinkTrav->next;
	}
	while(tempLinkTrav!=NULL){
		if(strcmp(tempLinkTrav->name,nameOfInput)==0){
			theValue=tempLinkTrav->data;
		}
		tempLinkTrav=tempLinkTrav->next;
	}
	return theValue;
}
void assignNum(int result, char * willInsert, Node ** outputLL, Node ** tempLL){
	struct Node * outputLLTrav=  (*outputLL);
	struct Node * tempLLTrav=  (*tempLL);
	struct Node * tempLLAttach=  (*tempLL);
	struct Node * insertToTemp= (struct Node *)malloc(sizeof(Node));
	// look for it in the outputs, attempt to modify one of the outputs
	while(outputLLTrav!=NULL){
		if(strcmp(outputLLTrav->name,willInsert)==0){
			outputLLTrav->data=result;
			return;
		}
		outputLLTrav=outputLLTrav->next;
	}
	// look for it in temps, attempt to modify temp.
	// if not found, must be a new temp variable 
	
	while(tempLLTrav!=NULL){
		if(strcmp(tempLLTrav->name,willInsert)==0){
			tempLLTrav->data=result;
			return;
		}
		tempLLAttach=tempLLTrav;
		tempLLTrav=tempLLTrav->next;
		// new variable, must go to the temp list
		if(tempLLTrav==NULL){
			insertToTemp->name=malloc(100*sizeof(char));
			strcpy(insertToTemp->name,willInsert);
			insertToTemp->data=result;
			insertToTemp->next=NULL;
			tempLLAttach->next=insertToTemp;
			return;
		}
	}
	// changing gave an experiment error
	if(tempLLTrav==NULL){
			insertToTemp->name=malloc(100*sizeof(char));
			strcpy(insertToTemp->name,willInsert);
			insertToTemp->data=result;
			insertToTemp->next=NULL;
			(*tempLL)=insertToTemp;
			return;
	}
	return; 

} 
void printLL(Node * printHead){
	while(printHead!=NULL){
		printf("%d",printHead->data);
		printf("%s",printHead->name);
		printHead=printHead->next;
	}
	return;
}

//------placeholder for main method-----//
int main(int argc, char ** argv){
	// Truth table= 2^N rows
	if(argc<2){
	   printf("\n");
	   return 0;
	} 
	FILE *fptr=fopen(argv[1],"r");
	if(fptr==NULL){ // do nothing if empty file 
		printf("error\n");
		return 0;
	}
	int inNum,outNum;
	fscanf(fptr, "INPUTVAR %d", &inNum); // amount of inputs
	// read in the input variables into a char LL
	struct Node * inputHead=NULL;
	int i;
	char * inName=malloc(100*sizeof(char));
	for(i=0;i<inNum;i++){
		fscanf(fptr,"%s",inName); // might not move to next input name
		struct Node * inNewNode=(struct Node*)malloc(sizeof(struct Node));
		inNewNode->name=malloc(100*sizeof(char));
		strcpy(inNewNode->name,inName);
		inNewNode->data=0;
		inNewNode->next=NULL;
		if(inputHead==NULL){ // only node in the list
			inputHead=inNewNode;
		}else{ // inserts at the end of the list
			struct Node * iteratorIn=inputHead;
			while(iteratorIn!=NULL){
				if(iteratorIn->next==NULL){
					iteratorIn->next=inNewNode;
					break;
				}
				iteratorIn=iteratorIn->next;
				
			} // inputs now sorted in order in the LL in order of input
		}
	}
	fscanf(fptr,"\n");
	fscanf(fptr, "OUTPUTVAR %d",&outNum); // amount of outputs
	// make a linked list for all of the outputs of each line of truth table
	struct Node * outputHead=NULL;
	char * outName=malloc(100*sizeof(char));
	int j;
	for(j=0;j<outNum;j++){
		fscanf(fptr,"%s",outName); // might not move to next input name
		struct Node * outNewNode=(struct Node*)malloc(sizeof(struct Node));
		outNewNode->name=malloc(100*sizeof(char));
		strcpy(outNewNode->name,outName);
		outNewNode->data=0;
		outNewNode->next=NULL;
		if(outputHead==NULL){ // only node in the list
			outputHead=outNewNode;
		}else{ // inserts at the end of the list
			struct Node * iteratorOut=outputHead;
			struct Node * beforeOut=outputHead;
			while(iteratorOut!=NULL){
				beforeOut=iteratorOut;
				iteratorOut=iteratorOut->next;
				if(iteratorOut==NULL){
					beforeOut->next=outNewNode;
				}
			} // inputs now sorted in order in the LL in order of output 
		}
	}
	// make a LL for all of the temp variables
	struct Node * tempHead=NULL;
	int numRow=pow(2,inNum);// number of rows in the final matrix
	int numCol=inNum+outNum;// number of columns in the final matrix 
	// fill input column values with mod(2)
	/* for example, given inputs A B C
	 * write a for loop from i=0--> i<2^number of inputs
	 * C will correpsond with i%2
	 * B will correspond with (i/2)%2
	 * A will correspond with ((i/2)/2)%2
	 * so on and so forth for more inputs
	 * put those into a linked list to operate on 
	 * Geeks for Geeks link in Bookmarks 
	 */ 
	 // make the 2D Array for all the possible inputs 
	 int final[numRow][numCol]; // declares the 2d array 
	 int r,c;
	 double multiplier,truthVal;
	 for(r=0;r<numRow;r++){
		 for(c=0;c<numCol-outNum;c++){
			 multiplier=pow(2,numCol-outNum-1-c);
			 multiplier=1/multiplier;
			 truthVal=multiplier*r;
			 truthVal=fmod(truthVal,2);
			 final[r][c]=(int)truthVal;
		 }
		 while(c!=numCol){
			 final[r][c]=0;
			 c++;
		 }
	 }
	 // DEBUG PROBLEM @ 2:10 WED----> MATRIX FULL OF 0s
	 // @ 2.27 PM Wed, problem fixed. Stopped here 
	 // base truth table and matrix should be assembled 
	 char * operation=malloc(100*sizeof(char));
	 char * in1=malloc(20*sizeof(char));
	 char * in2=malloc(20*sizeof(char));
	 char * out=malloc(20*sizeof(char));
	 int rowCounter=0;
	 int input1, input2, result,colCounter;
	 while(rowCounter<numRow){ // operations from the file 
		 tempHead=NULL;
		 struct Node * fillTheInputs=inputHead;
		 // assign the #'s in the truth table to the input LL 
		 for(colCounter=0;colCounter<numCol-outNum;colCounter++){
			fillTheInputs->data=final[rowCounter][colCounter];
			fillTheInputs=fillTheInputs->next; 
		 }
		 while(fscanf(fptr, "%s ", operation)==1){
			if(strcmp("INPUTVAR", operation) == 0 || strcmp("OUTPUTVAR", operation) == 0 ){       
				fscanf(fptr, "%*[^\n]\n"); // Next line iterator
				continue;
			}
			if(!strcmp(operation, "AND")){ // DEBUG PROB WED 5:51--> DOES NOT ADVANCE TO NEXT LINE
				fscanf(fptr, "%s %s %s\n", in1, in2, out);
				input1 = getNum(in1, inputHead, tempHead); 
				input2 = getNum(in2, inputHead, tempHead);
				result = ANDGate(input1, input2);
				assignNum(result, out, &outputHead, &tempHead); 
			}else if(!strcmp(operation, "NOT")){
				fscanf(fptr, "%s %s\n", in1, out);
				input1 = getNum(in1, inputHead, tempHead);
				result = NOTGate(input1);
				assignNum(result, out, &outputHead, &tempHead);
			}else if(!strcmp(operation, "OR")){
				fscanf(fptr, "%s %s %s \n", in1, in2, out);
				input1 = getNum(in1, inputHead, tempHead);
				input2 = getNum(in2, inputHead, tempHead);
				result = ORGate(input1, input2);
				assignNum(result, out, &outputHead, &tempHead);
			}else if(!strcmp(operation, "XOR")){
				fscanf(fptr, "%s %s %s\n", in1, in2, out);
				input1 = getNum(in1, inputHead, tempHead);
				input2 = getNum(in2, inputHead, tempHead);
				result = XORGate(input1, input2);
				assignNum(result, out, &outputHead, &tempHead);
			}else if(!strcmp(operation, "NOR")){
				fscanf(fptr, "%s %s %s\n", in1, in2, out);
				input1 = getNum(in1, inputHead, tempHead); // NOT DONE 
				input2 = getNum(in2, inputHead, tempHead);
				result = NORGate(input1, input2);
				assignNum(result, out, &outputHead, &tempHead);
			}else if(!strcmp(operation, "NAND")){
				fscanf(fptr, "%s %s %s\n", in1, in2, out);
				input1 = getNum(in1, inputHead, tempHead);
				input2 = getNum(in2, inputHead, tempHead);
				result = NANDGate(input1, input2);
				assignNum(result, out, &outputHead, &tempHead); // NOT DONE
			}else{
				printf("Parsed Incorrectly: %s", operation);    
			}
		}
		// fill in the output columns of the matrix 
		int putOut, outputDigit;
		struct Node * outputPlacer=outputHead;
		for(putOut=numCol-outNum;putOut<numCol;putOut++){
			outputDigit=outputPlacer->data;
			final[rowCounter][putOut]=outputDigit;
			outputPlacer=outputPlacer->next;
			if(outputPlacer==NULL){
				break;
			} 
		}
		// start reading the instructions for the next input 
		rewind(fptr);
		free(tempHead);//NOT DONE
		rowCounter++;
	}
	// need to create freeTheList
	// print out the matrix
	int rPrint,cPrint;		 
	for(rPrint=0;rPrint<numRow;rPrint++){
		for(cPrint=0;cPrint<numCol;cPrint++){
			printf("%d ",final[rPrint][cPrint]);
		}
		printf("\n");
	}
	// free input list, output list, temp list, all of the chars
		 
	 
	 
	
	
	
	
	fclose(fptr);
	return 0;
}
