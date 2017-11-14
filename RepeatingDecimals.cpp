#include<stdio.h>
#include<stdlib.h>
int* repeatingDigit;

int main(){
	int numerator,denominator;
	int remainder = 0;
	while( scanf("%d %d",&numerator,&denominator) != EOF ){
		int idx = 0;
		repeatingDigit = (int*) malloc(100000*sizeof(int));
		printf("%d/%d = %d.",numerator,denominator,numerator/denominator);
		
		remainder = numerator % denominator;
		do{			
			remainder *= 10;		
			repeatingDigit[idx]= remainder/ denominator;
			idx ++;
			remainder = remainder % denominator;
			
		}while();
		
		
		free(repeatingDigit);
	}
	return 0;
}