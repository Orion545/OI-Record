#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n,m;
int map[10005][3],degs=1;//[1,2m][0,1](to,next)
bool visL[10005];//[1,2m]
bool pvis[5005];//[1,n]
int head[5005];//[1,n]
int ans[5005],steps;

int ok;

void put(int from,int to){
	map[degs][0] = to;
	map[degs][1] = head[from];
	head[from] = degs++;
}

bool check(){
	for(int i = 1;i <= n;i++){
		if(!pvis[i]) return false;
	}
	return true;
}

void dfs(int pos,int last,int step){
	pvis[pos] = 1;
	if(check()) ok = step;
	if(ok){
		return;
	}
	int next = head[pos];
	vector<short> cango[2];//[0,1](point,line)[0,cnt-1]
	//short cango[5005][2],cnt;//[0,cnt-1][0,1](point,line)
	while(next){
		//cango[cnt][0] = map[next][0];
		//cango[cnt++][1] = next;
		cango[0].push_back(map[next][0]);
		cango[1].push_back(next);
		next = map[next][1];
	}
	
	/*for(int i = 0;i < cnt;i++){
		bool swaped = 0;
		for(int j = 0;j < cnt-1;j++){
			if(cango[j][0] > cango[j+1][0]){
				swaped = 1;
				swap(cango[j][0],cango[j+1][0]);
				swap(cango[j][1],cango[j+1][1]);
			}
			
		}
		if(!swaped) break;
	}*/
	for(int i = 0;i < cango[0].size();i++){
		bool swaped = 0;
		for(int j = 0;j < cango[0].size()-1;j++){
			if(cango[0][j] > cango[0][j+1]){
				swaped = 1;
				swap(cango[0][j],cango[0][j+1]);
				swap(cango[1][j],cango[1][j+1]);
			}
			
		}
		if(!swaped) break;
	}
	
	for(int i = 0;i < cango[0].size();i++){
		if(ok){
			return;
		}
		if(!visL[cango[1][i]]){
			visL[cango[1][i]] = 1;
			if(!pvis[cango[0][i]]){
				ans[step] = cango[0][i];
				dfs(cango[0][i],pos,step+1);
				pvis[cango[0][i]] = 0;
			} else{
				dfs(cango[0][i],pos,step);
			}
			visL[cango[1][i]] = 0;
		}
	}
}


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	int t1,t2;
	for(int i = 1;i <= m;i++){
		scanf("%d%d",&t1,&t2);
		put(t1,t2);
		put(t2,t1);
	}
	pvis[1] = 1;
	dfs(1,0,0);
	cout << 1 << " ";
	for(int i = 0;i < ok;i++){
		if(i < ok-1){
			cout << ans[i] << " ";
		}else{
			cout << ans[i];
		}
	}
}
/*
6 5
1 3
2 3
2 5
3 4
4 6
*/
