#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
	int addCandy;
	void divideCan(vector<int>& a){
		int beforeHalf = a[a.size()-1]/2,nowHalf = 0;
		for(int i = 0; i < a.size(); i++){
			nowHalf = a[i]/2; 
			a[i]/=2;
			a[i] += beforeHalf;	
			beforeHalf = nowHalf;	
			
		}
	}
	void addCan(vector<int>& a){
		for(int i = 0; i < a.size(); i++){
			if(a[i] % 2 != 0){
				a[i]++;
				addCandy++;				
			}	
		}
	}
	bool equal(vector<int>& a){
		for(int i = 0; i < a.size()-1; i++){
			if(a[i] != a[i+1]) return false;
		}
		return true;
	}
public:
	int countCandy(vector<int> a){
		int n = a.size();
		addCandy = 0;
		while(!equal(a)){
			divideCan(a);			
			if(equal(a)) break;
			addCan(a);			
		}
		return addCandy;
	}
};

int main(){
	int n,c;
	cin >> n;
	vector<int> a;
	for(int i = 0; i < n; i++){
		cin >> c;
		a.push_back(c);
	}
	Solution s;
	cout << s.countCandy(a);
	return 0;
} 
