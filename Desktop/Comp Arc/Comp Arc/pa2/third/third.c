#include <stdlib.h>
#include <stdio.h>

// from first part, get method
int Get(unsigned short x, int n){
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
	 // print it
	return getBit;
}
//-----placeholder for main method----//
int main(int argc, char* argv[])
{
	unsigned short input=atoi(argv[1]);
	int back=15; // back of binary	
	int front=0; // front of binary
	//check first binary term against last
	int backVal=0;
	int frontVal=0;
	while(backVal==frontVal && back>front){
		backVal=Get(input,back);
		frontVal=Get(input,front);
		if(backVal!=frontVal){
			printf("Not-Palindrome\n");
			return 0;
		}
		back--; // move to next last bit
		front++; // move to next bit
		
	}
	printf("Is-Palindrome\n"); // if all equate, must be palindrome
	
	return 0;
}
