#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
private:
public:
	int countQue(vector<vector<int> > a){
		int n = a.size();
		int kidnMot = 0;
		for(int j = n ; j > 0 ; j --){
			for(int i = 0; i < j-1; i ++){
				int count = 0;
				if(a[i][0] > a[i+1][0]){
					a[i][2]++;
					a[i][1] += a[i][2];
					a[i+1][2]++;
					a[i+1][1] += a[i+1][2];
					kidnMot += a[i+1][2] + a[i][2];
					swap(a[i],a[i+1]);	
					count ++;				
				}
				if(!count) break;
			}
		}
		return kidnMot;
	}

};

int main(){
	int n,c;
	vector<vector<int> > a;
	cin >> n; 
	for(int i = 0; i < n; i++){
		vector<int> cd;		
		cin >> c;
		cd.push_back(c);
		cd.push_back(0);
		cd.push_back(0);
		a.push_back(cd);
	}
	Solution s;
	cout << s.countQue(a);	
	
}
