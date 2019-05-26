#include <bits/stdc++.h>
using namespace std;
const int maxn=5e4 + 10;
struct edge{
	int to,v;
}e[maxn*2];
int edge_num;
vector <int>p[maxn];
int n,m,l,r,mid,Longest_Path,Longest_Point,cnt;

inline int read(){
	int ret=0,f=1;char c=getchar();
	while(!isdigit(c)) {if(c=='-')f=0;c=getchar();}
	while(isdigit(c)) ret=ret*10+(c^48),c=getchar();
	return f?ret:-ret;
}
void add_edge(int x,int y,int z){
	edge_num++;
	e[edge_num].to=y;
	e[edge_num].v=z;
	p[x].push_back(edge_num);
	edge_num++;
	e[edge_num].to=x;
	e[edge_num].v=z;
	p[y].push_back(edge_num);
}
void dfs(int u,int f,int Strenth){
	if(Strenth>Longest_Path){
		Longest_Path=Strenth;
		Longest_Point=u;
	}
	for(int i=0;i<(int)p[u].size();i++){
		if(e[p[u][i]].to==f) continue;
		dfs(e[p[u][i]].to,u,Strenth+e[p[u][i]].v);
	}
}
void DFS(int u,int f,int Strenth,int sum,int tk){
	if(Strenth>=tk){
		sum++;
		Strenth=0;
	}
	if(sum==m){
		cnt=1;
		return;	
	}
	for(int i=0;i<(int)p[u].size();i++){
		int v=e[p[u][i]].to;
		if(v==f) continue;
		DFS(v,u,Strenth+e[p[u][i]].v,sum,tk);
	}
}
bool Judge(int Path_long){
	cnt=0;
	DFS(Longest_Point,0,0,0,Path_long);
	if(cnt) return 1;
	return 0;
	
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int x,y,z;
	n=read();m=read();
	for(int i=1;i<n;i++){
		x=read();y=read();z=read();
		add_edge(x,y,z);
	}
	Longest_Path=-1;
	dfs(1,0,0);
	Longest_Path=-1;
	dfs(Longest_Point,0,0);
	if(m==1){
		printf("%d\n",Longest_Path);
		return 0;
	}
	l=0;r=Longest_Path+1;
	while(l+1<r){
		mid=(l+r)/2;
//		cout<<l<<' '<<r<<' '<<mid<<endl;
		if(Judge(mid)) l=mid;
		else r=mid;
	}
	printf("%d\n",l);
	return 0;
}
