#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int temp=atoi(argv[1]);
	// begin reading inputs
	int parity=0;
	int pairs=0; // counters for parity and pairs
	int numHolder=temp; // operates on the input 
	int compare=1; // 1 bit value that shifts in comparisons
	int result; // outcome of comparisons
	int pairLocator=0;
	// compares bits at the 0th spot
	while(numHolder>0){
		result=numHolder & compare;
		if(result>0){
			parity++; // increments when a 1 is @ 0th spot of both
			pairLocator++;
		}else{
			pairLocator=0;
		}
		if(pairLocator!=0 && pairLocator%2==0){
			pairs++; // finds a pair when pair locator senses 2 ones in a row
			pairLocator=0;
		}
		// shift temporary down to by 1 bit shift
		numHolder=numHolder >> 1;
	}
	
	if(parity%2==0){
		printf("Even-Parity\t");
	}else{
		printf("Odd-Parity\t");
	}
	printf("%d",pairs);
	return 0;
}
