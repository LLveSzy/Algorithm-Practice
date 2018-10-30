#include<iostream>//11:35
#include<vector>

using namespace std;

class Solution{
private:
	vector<vector<bool> > memoRow;
	vector<vector<bool> > memoCol;
	vector<vector<bool> > memoBlo;
	bool dfs(vector<vector<int> >& chart,int i, int j){
		if(i*10+j == 90) {
		cout << endl;
			for(int i = 0; i < 9; i ++){
				for(int j = 0; j < 9; j ++){
					cout << chart[i][j];
				}
				cout << endl;
			}				
			exit(0);			
		}
		//cout << "---i:" << i << " ---j:" << j << endl;
		if(chart[i][j] != 0) dfs(chart,i+(j+1)/9,(j+1)%9);
		else
			for(int t = 1; t <= 9; t++){
				//cout << chart[i][j] << endl;
				if(chart[i][j] == 0){
					if(isValid(chart,t,i,j)){	
						memoRow[i][t] = true;
						memoCol[j][t] = true;
						memoBlo[j/3 + 1 + (i/3) * 3][t] = true;				
						chart[i][j] = t;
						if(dfs(chart,i+(j+1)/9,(j+1)%9)) return true; 
						chart[i][j] = 0;
						memoRow[i][t] = false;
						memoCol[j][t] = false;
						memoBlo[j/3 + 1 + (i/3) * 3][t] = false;	
					}
				}											
			}
		return false;
	} 
	bool isValid(vector<vector<int> > chart,int x,int i,int j){
		if(memoRow[i][x]) return false;
		if(memoCol[j][x]) return false;
		if(memoBlo[j/3  + 1 + (i/3) * 3][x]) return false;

		return true;
	}
public:
	void fillCh(){
		memoRow = vector<vector<bool> >(10,vector<bool>(10,false));
		memoCol = vector<vector<bool> >(10,vector<bool>(10,false));
		memoBlo = vector<vector<bool> >(10,vector<bool>(10,false));
		vector<vector<int> > chart(9,vector<int> (9,0));

		for(int i = 0; i < chart.size(); i++){			
			for(int j = 0; j < chart[0].size(); j++){
				cin >> chart[i][j];
				memoRow[i][chart[i][j]] = true;
				memoCol[j][chart[i][j]] = true;
				memoBlo[j/3  + 1 + (i/3) * 3][chart[i][j]] = true;
			}
		}
		dfs(chart,0,0);					
	}
}; 

int main(){
	Solution s;
	s.fillCh();
	return 0;
}
