#include<iostream>
using namespace std;
int head[7001];
int e[18001][3];
bool pd[7001][60];
int et;
void dfs(int x,int y){
	int c;
	if(pd[x][y])return;
	pd[x][y]=1;
	c=head[x];
	while(c>0){
		dfs(e[c][0],((y+e[c][1])%60+60)%60);
	    c=e[c][2];
	}
}
void insert(int u,int v,int w){
	et++;
	e[et][0]=u;
	e[et][1]=w;
	e[et][2]=head[v];
	head[v]=et;
}
int main(){
	int n,m,u,v,w;
	et=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		insert(u,v,w);
		insert(v,u,w);
	}
	dfs(1,0);
	for(int i=0;i<=59;i++){
		if(pd[2][i]){
			if(i<10)cout<<0;
			cout<<i;
			return 0;
		}
	}
	cout<<60; 
	return 0;
}
