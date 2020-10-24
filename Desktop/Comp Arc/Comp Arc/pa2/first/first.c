#include <stdlib.h>
#include <stdio.h>


unsigned short Set(unsigned short x, int n, int v){
	// new # operated on in next iteration
	unsigned short setNewNum;
	// sets the (nth) bit of (x) to (v)
	int tempS=1;
	tempS=tempS << n;// shift over n spots
	if(v==1){ // perform or to swap if 0
		setNewNum= x | tempS;
	}else{ // case where v=0
		// must swap out 1 for 0 or do nothing
		tempS=~tempS;
		setNewNum=x & tempS;
	}
	printf("%d\n",setNewNum);
	return setNewNum;
}
void Get(int x, int n){
	// bit to be returned to the program
	int getBit;
	int tempG=1; // shift over to place 
	tempG=tempG << n;
	int foo= x & tempG; // >0 if bit is 1, else 0
	if(foo>0){
		getBit=1; // two ones @ the spot, int value 
	}else{
		getBit=0; // 1 in foo, 0 in main, returns no valuation
	}
	printf("%d\n",getBit); // print it
	return;
}
unsigned short Comp(unsigned short x, int n){
	// new number to operated on in next iteration
	unsigned short compNewNum;
	// sets the (nth) bit of (x) to complement
	//0=1, anything else=0
	unsigned short temp=1;
	unsigned short tempC;
	tempC=temp << n; // shift over to spot
	compNewNum= x ^ tempC; // do XOR to flip 0->1 & 1 ->0
	printf("%d\n",compNewNum);
	return compNewNum;
}



int main(int argc, char* argv[])
{
	// open the file and get the input #
	FILE *fptr=fopen(argv[1],"r");
	if(argc<2){
		printf("error");
	}
	unsigned short x;
	char operation[10];
	int num1n,num2v;
	fscanf(fptr,"%hu\n",&x);
	// begin reading the operations to be performed
	while(fscanf(fptr,"%s\t%d\t%d\n",operation,&num1n,&num2v)!=EOF){
		// operation, first number, second number read into temps
		// begin operating on the binary
		if(operation[0]=='g'){
			// Get operates, prints the binary value
			Get(x,num1n);
		}
		else if(operation[0]=='c'){
			// Comp operates, prints the number
			//printf("%d\t%d\n",x,num1n);
			x=Comp(x,num1n);
			
		}
		else{ // set must operate then, print the #
			x=Set(x,num1n,num2v);
			
		}
	
	} // closes while 
	fclose(fptr);
	return 0;
}

