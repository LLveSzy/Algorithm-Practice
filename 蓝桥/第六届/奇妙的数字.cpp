#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int memo[10] = {0};
	int sq,sq3;
	for(int i = 1; i < 9000; i ++){
		sq = i*i;
		sq3 = i*i*i;
		while(sq!=0){
			memo[sq%10] ++;
			sq/=10;
		}
		while(sq3!=0){
			memo[sq3%10] ++;
			sq3/=10;
		}
		int j = 0;
		while(memo[j]==1&&j<10){
			j++;
		}
		if(j == 10) cout << i;
		memset(memo,0,sizeof(memo));
	}
	return 0;	
} 
