#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
	int count(int memo[],int n,int countd){					
		if(countd == 0) return 1;
		if(memo[n]<=0) return 0;		
		int res;
		memo[n] --;							
		res = count(memo,0,countd - 1)+count(memo,1,countd - 1)+count(memo,2,countd - 1);
		
		memo[n] ++;	
		return res;		
	}
public:
	int countJew(){
		int memo[3] = {3,4,5};
		return count(memo,0,12)+count(memo,1,12)+count(memo,2,12);
		
	}
};

int main(){
	Solution s;
	cout << s.countJew(); 
	return 0;
}
