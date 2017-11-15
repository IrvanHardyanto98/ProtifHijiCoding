#include<stdio.h>
#include<stdlib.h>
#include<map>
using namespace std;
int* repeatingDigit;

int main(){
	int numerator,denominator;
	int remainder = 0;
	bool first = 1;
	while( scanf("%d %d",&numerator,&denominator) == 2 ){
		
		map <int,int> remainderMap;
		map <int,int>::iterator it; 
		int idx = 0;
		repeatingDigit = (int*) malloc(100001*sizeof(int));
		printf("%d/%d = %d.",numerator,denominator,numerator/denominator);
		
		if(numerator % denominator == 0){
			printf("(0)\n");
			printf("%c%c%c1 = number of digits in repeating cycle\n\n",' ',' ',' ');//naive input formatting
		}else{
			remainder = numerator % denominator;
			do{						
				remainder *= 10;				
				it = remainderMap.find(remainder);
				if( it != remainderMap.end()){
					break;
				}
				remainderMap[remainder] = idx;
				//tadi salah di sini... ada yang dimasukkin dua kali di map					
				if(idx<50)repeatingDigit[idx]= remainder/ denominator;
				idx ++;//tadi juga salah nempatin bagian ini, jadinya posisi digit nya salah..
				remainder = remainder % denominator;
			
			}while(remainder != 0 );
			
		
			if(remainder == 0 ){
				for(int i = 0 ; i < idx ; i ++){
					printf("%d",repeatingDigit[i]);
				}
				printf("(0)\n%c%c%c1 = number of digits in repeating cycle\n\n",' ',' ',' ');
			}else{
				for(int i = 0; i < (it->second) ;i++)printf("%d",repeatingDigit[i]);				
				printf("(");
				int limit = idx;
				if(idx > 50) limit = 50;
				for(int i = (it->second) ; i < limit ;i++){
					printf("%d",repeatingDigit[i]);
				}				
				if(idx>49)printf("...");
				printf(")\n");
				printf("%c%c%c%d = number of digits in repeating cycle\n\n",' ',' ',' ',idx-(it->second));
			}
		}
		free(repeatingDigit);
	}
	return 0;
}
