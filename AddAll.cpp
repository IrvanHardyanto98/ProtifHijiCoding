#include<stdio.h>
#include<functional>
#include<algorithm>
#include<queue>
#include<vector>
#include<iterator>
using namespace std;
int main(){
	int bnykBilangan;
	while(1){
		int cummulativeSum = 0;
		int minimumCost = 0;
		scanf("%d",&bnykBilangan);
		if(bnykBilangan == 0)break;
		
		priority_queue<int, vector<int>, greater<int> > pQueue;//priorityQueue ascending..
		
		for(int i = 0; i< bnykBilangan ; i++){
			int input;
			scanf("%d",&input);
			pQueue.push(input);
		}
		
		while(pQueue.size() > 1){
			int a = pQueue.top();
			pQueue.pop();
			int b = pQueue.top();
			pQueue.pop();
			minimumCost += a + b;
			pQueue.push(a + b);
		}
		printf("%d\n",minimumCost);
	}
	return 0;
}