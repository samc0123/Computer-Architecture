#include <stdio.h>
#include <stdlib.h>

void swapNums(int * currentMin, int * i){
	int temp;
	temp=*currentMin;
	*currentMin=*i;
	*i=temp;
}
void sortEven(int arr[],int evenSize){ // does ascending sort on evens
	int i;								// insertion sort
	int j;
	int currentMin; 
	
	for(i=0;i<evenSize;i++){
		currentMin=i;
		for(j=i+1;j<evenSize;j++){
			if(arr[j]<arr[currentMin]){
				currentMin=j;
				 // performs the swapping
			}
		}
		swapNums(&arr[currentMin],&arr[i]);
	}
	return;
}
void sortOdd(int arr[],int evenSize){ // does ascending sort on evens
	int i;								// insertion sort
	int j;
	int currentMin; 
	
	for(i=0;i<evenSize;i++){
		currentMin=i;
		for(j=i+1;j<evenSize;j++){
			if(arr[j]>arr[currentMin]){
				currentMin=j;
				
			}
		}
		swapNums(&arr[currentMin],&arr[i]); // performs the swapping
	}
	return;
}


	
	
	


// -----------placeholder of the main method-----------------
int main(int argc, char** argv){
	if(argc<2){
		printf("\n");
		return 0;
	}
	 FILE *fptr=fopen(argv[1],"r");
	 // read size of the array from the first line
	 int  sortedSize;
	 fscanf(fptr,"%d",&sortedSize); // setup final size of array
	 int sorted[sortedSize];
	 int atThatSpot;
	  //allocates the array
	 int evenSize=0;// even terms
	 int oddSize=0; // odd terms
	 int initial;	 
	 int evenNums[20];
	 int oddNums[20]; // odd array
	 // can try to malloc, or keep it static
	 for(initial=0;initial<sortedSize;initial++){
		 //populates the array with the terms 
		fscanf(fptr,"%d",&atThatSpot);
		if(atThatSpot%2==0){
			evenNums[evenSize]=atThatSpot;
			evenSize++;
		}
		else{
			oddNums[oddSize]=atThatSpot;
			oddSize++;
		}
	  }
	 sortEven(evenNums,evenSize);// even sorting
	 sortOdd(oddNums,oddSize);// odd sorting
	 int eCount; 
	 for(eCount=0;eCount<evenSize;eCount++){
		 sorted[eCount]=evenNums[eCount];
	 }
	 int oCount;
	 for(oCount=0;oCount<oddSize;oCount++){
		 sorted[eCount+oCount]=oddNums[oCount];
		 // backwards inputs into array 
	 }
	 int finalPrint;
	 for(finalPrint=0;finalPrint<sortedSize;finalPrint++){
		 printf("%d\t",sorted[finalPrint]);
	 }
	
	 
	 


	return 0;
	
} 

