#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ----------- placeholder for main method--------------------
int main(int argc, char ** argv){
	char currentChar;
	int xIterate;
	int yIterate=0;
	
	for(xIterate=1;xIterate<argc;xIterate++){
		// looking thru the characters in strings
		while((currentChar=argv[xIterate][yIterate])){
			if(currentChar=='a' || currentChar=='e' || 
			currentChar=='i' || currentChar=='o' ||
			currentChar=='u' || currentChar=='A' || 
			currentChar=='E' || currentChar=='O' ||
			currentChar=='U'){
				printf("%c",currentChar);
			}
			yIterate++;	
		}
	}  // vowels should have all vowels in the char array 
	printf("\n");
	
	
	

	return 0;
}
