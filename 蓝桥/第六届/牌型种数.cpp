#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
	int count(int i, int n){
		if(n == 0) return 1;		
		if(i > 13) return 0;
		
		return count(i+1,n-1)+count(i+1,n-2)+count(i+1,n-3)+count(i+1,n-4)+count(i+1,n);
	}
public:
	int countComb(){
		int allCount;
		allCount = count(1,13);
		return allCount; 
	}	
};

int main(){
	Solution s;
	cout << s.countComb(); 
	return 0;
}
