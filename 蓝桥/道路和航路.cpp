#include<iostream>
#include<vector>
#define MIN_INT M
using namespace std;

class Solution{
private:
	int cities,rout,nav,begin;
	vector<vector<vector<int> > > road;
	vector<int> min;
public:
	typedef struct{
		int end,cost;
	}line;
	void minCost(){
		vector<vector<line> > a;
		cin >> cities >> rout >> nav >> begin;		
		//road = vector<vector<vector<line> > >(cities+1,a);
		for(int i = 0; i < rout; i++){
			int a,b,c;
			cin >> a >> b >> c;
			line d;
			d.end = a; d.cost = c;
			for(int j = 0;j < road[b][j].size(); j++){
				if(d.cost < road[a][j][1]) road[a][j].insert(j,d);
			}
			
			d[2] = {a,c};
			d.push_back(a);
			d.push_back(c);
			for(int j = 0;j < road[a][j].size(); j++){
				if(d[1] < road[b][j][1]) road[b][j].insert(j,d);
			}
		}
	} 
};

int main(){
	return 0;
} 
