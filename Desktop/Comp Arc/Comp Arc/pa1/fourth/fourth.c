#include <stdio.h>
#include <stdlib.h>
/* @ 5:45PM on Sat, Sept 28
 * To Do List: 
 * 1. Finish Multiply Method
 * 2. Understand how to iterate along rows of first matrix
 * in the main driver 
 */


// ----------- placeholder for main method--------------------
int main(int argc, char ** argv){
	FILE *fptr=fopen(argv[1],"r");
	// find out amount of rows and columns
	int** firstMatrix;
	int** secondMatrix;
	int** finalMatrix;
	int rFirst,cFirst;
	fscanf(fptr,"%d\t%d\n",&rFirst,&cFirst);
	//allocate memory for first matrix
	firstMatrix= (int**)malloc(rFirst*sizeof(int *));
	int memFirst;
	for(memFirst=0;memFirst<rFirst;memFirst++){
		firstMatrix[memFirst]=(int*)malloc(cFirst*sizeof(int));
	}
	// assign terms to first matrix
	int iOne, jOne;
	for(iOne=0;iOne<rFirst;iOne++){
		for(jOne=0;jOne<cFirst;jOne++){
			fscanf(fptr,"%d\t",&firstMatrix[iOne][jOne]);
			//assignment step
		} // new line for new row
	}
	// allocate memory to second matrix
	int rSecond,cSecond;
	fscanf(fptr,"%d\t%d\n",&rSecond,&cSecond);
	secondMatrix=(int **)malloc(rSecond*sizeof(int *));
	int memSecond;
	for(memSecond=0;memSecond<rSecond;memSecond++){
		secondMatrix[memSecond]=(int*)malloc(cSecond*sizeof(int));
	}
	// assign terms to second matrix
	int iTwo,jTwo;
	for(iTwo=0;iTwo<rSecond;iTwo++){
		for(jTwo=0;jTwo<cSecond;jTwo++){
			fscanf(fptr,"%d\t",&secondMatrix[iTwo][jTwo]);
			// assignment step
		} // new line for new row
	}	
	// check if multiplication is possible
	// # of columns in firstMat=
	// # of rows in secondMat
	if(cFirst != rSecond){
		printf("bad-matrices");
		return 0;
	}
	/* allocate memory for final matrix
	 * Dimensions: Rows of first by columns of Second
	 */
	 int rFinal,cFinal,memFinal,iFinal,jFinal;
	 rFinal=rFirst;
	 cFinal=cSecond;
	 finalMatrix= (int **)calloc(rFinal,sizeof(int *));
	 for(memFinal=0;memFinal<rFinal;memFinal++){
		 finalMatrix[memFinal]=(int *)calloc(cFinal,sizeof(int));
	 }
	 // term assignment for the final matrix
	 int value;
	 for(iFinal=0;iFinal<rFinal;iFinal++){
		 for(jFinal=0;jFinal<cFinal;jFinal++){
			 for(value=0;value<cFirst;value++){
				 finalMatrix[iFinal][jFinal] += firstMatrix[iFinal][value] * 
				 secondMatrix[value][jFinal];
				 // computational assignment step for final matrix
			 }
		 }
	 }
	// print out the final output
	int rPrint,cPrint;		 
	for(rPrint=0;rPrint<rFinal;rPrint++){
		for(cPrint=0;cPrint<cFinal;cPrint++){
			printf("%d\t",finalMatrix[rPrint][cPrint]);
		}
		printf("\n");
	}
	int fOne,fTwo,fFinal;
	for (fOne=0;fOne<rFirst;fOne++){
		free(firstMatrix[fOne]);
	}
	free(firstMatrix);
	for(fTwo=0;fTwo<rSecond;fTwo++){
		free(secondMatrix[fTwo]);
	}
	free(secondMatrix);
	for(fFinal=0;fFinal<rFinal;fFinal++){
		free(finalMatrix[fFinal]);
	}
	free(finalMatrix);
	
	
	return 0;
}	
