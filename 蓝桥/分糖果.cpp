#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
	static int addCandy;
	void divideCan(vector<int> a){
		for(int i = 0; i < a.size(); i++){
			a[(i+1)%a.size()] += a[i]/2;
		}
	}
	void addCan(vector<int> a){
		for(int i = 0; i < a.size()-1; i++){
			if(a[i] % 2 != 0){
				a[i]++;
				addCandy++;
			}
		}
	}
	bool equal(vector<int> a){
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
			addCan(a);
			if(equal(a)) break;
			divideCan(a);
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
