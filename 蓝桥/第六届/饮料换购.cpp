#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
	int addJuice(int n, int b){
		if((n+b)/3 == 0) return n;
		return n + addJuice((n+b)/3,(n+b)%3);
	}
public:
	int countJuice(int n){		
		return addJuice(n , 0);
	}
};

int main(){
	Solution s;
	int n;
	cin >> n; 
	cout << s.countJuice(n); 
	return 0;
}
