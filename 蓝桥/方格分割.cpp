#include<iostream>
#include<stack>
#include<memory.h>
using namespace std;

enum Direction{
	Up,Down,Left,Right
};
int cnt = 0;
int now = 21;
stack<int> stk; 
static int visited[78] = {1};
static int stacked[78] = {0};
void turn(Direction d){
	switch(d){
		case Up:
			now -= 1;
			break;
		case Down:
			now += 1;
			break;
		case Left:
			now -= 10;
			break;
		case Right:
			now += 10;
			break;
	}
	visited[now] = 1;
	int mir = 8-now%10+(8-now/10)*10;
	visited[mir]= 1;
	if(mir == now) {
		cnt++;
		now = stk.top();	
		return;
	}
	stk.push(mir);
	stk.push(now); 
}
int main()
{
	stk.push(8-now%10+(8-now/10)*10);
	stk.push(now);
	visited[21] = 1;visited[31] = 0;visited[41] = 0;
	visited[47] = 1;visited[57] = 0;visited[67] = 0;
	for(int i = 0; i < 78; i++) visited[i] = 1;
	for(int i = 2; i<=6;i++)
		for(int j = 2; j <= 6; j++) visited[i*10+j] = 0;
	
	while(!stk.empty()){
		if(!stacked[now-1]&&!visited[now-1]){
			turn(Up);
		}
		else if(!stacked[now+1]&&!visited[now+1]){
			turn(Down);
		}
		else if(!stacked[now-10]&&!visited[now-10]){
			turn(Left);
		}
		else if(!stacked[now+10]&&!visited[now+10]){
			turn(Right);
		}//向右方向相邻点没有被压栈过且这条路径没有走过，则向右 
		else{						
			stacked[stk.top()] = 1;
			visited[stk.top()] = 0;
			stk.pop(); //现点出栈 
			stacked[stk.top()] = 1;
			visited[stk.top()] = 0;
			stk.pop(); //对称点出栈 
			now = stk.top();
		}	//无路可走则退栈，加入压栈访问记录数组，并从已访问到的路径记录数组删除 
	}
	cout << cnt;
	return 0;
 } 
