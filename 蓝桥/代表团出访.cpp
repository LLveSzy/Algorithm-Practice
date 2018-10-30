#include<iostream>
#include<vector>
#include<string> 
using namespace std;

class Solution{
private:
	int res = 0;
	int people[6] = {4,2,2,1,1,3};
	void dfs(int index,int left,string s){
		if(left==0) {
			res++;
			cout << s << endl;
			return;
		}		
		if(index > 5) return;
		
		if(people[index]-1 >= 0) {
			people[index]--;
			
			dfs(index,left-1,s+char(index+'A'));
			//dfs(index+1,left-1);
			people[index]++;	
		}
				
		dfs(index+1,left,s);
	}
public:
	int count(){
		dfs(0,5,"");
		return res;
	}	
};


int main(){
	Solution s;
	cout << s.count();
	return 0;
} 


