#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(int a,int b){
		return abs(a) < abs(b);
	}

class Solution{
private:
	
public:	
	int countAnt(int ant[],int n){
		vector<bool> memo(n,false);
		int sickAnt = ant[0],antsOn = n,endAnt = n-1;
		int sicks = 1;
		sort(ant,ant+n,compare);
		for(int i = 0; i < n; i++)
			if(ant[i] == sickAnt){
				memo[i] = true;
				break;
			}

		int beginAnt = 0,min = 2;
		while(antsOn > 0){
			for(int i = beginAnt; i <= endAnt;i++) cout << ant[i] << "  ";
			cout << endl;
			while(ant[beginAnt] <= 0 && antsOn > 0) {
				beginAnt++;	
				antsOn--;
			}
			while(ant[endAnt] > 0 && antsOn > 0){
				endAnt--;
				antsOn--;	
			} 
			int minLine = 999;
			for(int i = beginAnt; i <= endAnt && antsOn > 0 ;i ++){
				ant[i]+=min/2;
				if(abs(abs(ant[i])-abs(ant[i+1])) < minLine
					&& abs(abs(ant[i])-abs(ant[i+1]))!=1) minLine = abs(abs(ant[i])-abs(ant[i+1]));
				if(i!=beginAnt&&ant[i] == -ant[i-1]){
					ant[i]*=-1;
					ant[i-1]*=-1;
					if(memo[i] ^ memo[i-1]){
						memo[i] = true;
						memo[i-1] = true;
						sicks++;
					}
				}			
			}
			min = minLine;				
		}
		return sicks;	
	}
	
};

int main(){
	int n,sickAnt;
	cin >> n;
	int ant[n];
	cin >> ant[0];
	for(int i = 1; i < n; i++){
		cin >> ant[i];
	}
	
	Solution s;
	cout << s.countAnt(ant,n);
	return 0;
} 
