#include<iostream>
#include<vector>
#include<cstdio>
#include<bitset>
#include<cstring>
using namespace std;
int n,m;
vector<int>road[5005];
bitset<5005>map[5005];
int vis[5005];
bitset<5005>onr;
bitset<5005>cg;
bitset<5005>ungo;
int lowbit(bitset<5005>a){
	for(int i=1;i<=n;i++)if(a[i])return i;
}
void basic_dfs(int x,bool ret){
	if(!ungo[x])return;
	cout<<x<<' ';
	ungo[x]=false;
	cg|=map[x];
	if(!onr[x]){for(int i=1;i<=n;i++)if(ungo[i]&&map[x][i])basic_dfs(i,ret);}
	else{
		for(int i=1;i<=n;i++){
			if(cg[i]&&onr[i]&&!map[x][i]){
				if(ret)basic_dfs(i,false);
			}
			if(map[x][i])basic_dfs(i,ret);
		}
	}
}
void dfs(int x,int p){
	vis[x]++;
	if(vis[x]==3)
		onr[x]=1;
	if(vis[x]==4)return;
	for(int i=0;i<road[x].size();i++)
		if(road[x][i]!=p)dfs(road[x][i],x);
	vis[x]--;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)ungo[i]=1;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		map[x][y]=map[y][x]=1;
		road[x].push_back(y);
		road[y].push_back(x);
	}
	dfs(1,0);
	basic_dfs(1,1);
}
