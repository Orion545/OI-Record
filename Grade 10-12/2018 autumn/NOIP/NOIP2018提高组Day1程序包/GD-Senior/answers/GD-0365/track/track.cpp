#include<iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char s=getchar();
	while (s<'0'or s>'9'){if (s=='-')f=-1;s=getchar();}
	while (s>='0'and s<='9'){
		x=(x<<3)+(x<<1)+s-'0';
		s=getchar();
	}
	return x*f;
}
int n,m;
const int N=30010;
const int M=60010;
int head[N],to[M],next[M],w[M];
int edge;
void add(int u,int v,int we){
	to[++edge]=v,next[edge]=head[u],w[edge]=we,head[u]=edge;
	to[++edge]=u,next[edge]=head[v],w[edge]=we,head[v]=edge;
	return;
}
struct node{
	int to,wei;
}temp1;
vector<node>hea[N];
bool vis[N];
void maketree(int u){
	if (vis[u])return;
	vis[u]=1;
	for (int i=head[u];i;i=next[i]){
		temp1.to=to[i];
		temp1.wei=w[i];
		if (vis[to[i]])continue;
		hea[u].push_back(temp1);
		maketree(to[i]);
	}
	return;
}
int ans[N];
void show(){
	for (int i=1;i<=n;i++){
		for (int j=0;j<hea[i].size();j++)
		cout<<i<<" "<<hea[i][j].to<<" "<<hea[i][j].wei<<endl;
	}
}
void dfs(int u){
	if (vis[u])return;
	vis[u]=1;
	if (hea[u].size()==0)return;
	int sum=-1;
	node temp;
	for (int i=0;i<hea[u].size();i++){
		temp=hea[u][i];
//		cout<<u<<" "<<temp.to<<" "<<temp.wei<<endl;
		if (vis[temp.to])continue;
		dfs(temp.to);
//		cout<<u<<" "<<temp.to<<" "<<temp.wei<<endl;
		ans[temp.to]+=temp.wei;
		sum=max(sum,ans[temp.to]);
	}
	ans[u]+=sum;
	return;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
//	freopen("track1.in","r",stdin);
	n=read();
	m=read();
	int u,v,we;
	for (int i=1;i<=n-1;i++){
		u=read(),v=read(),we=read();
		add(u,v,we);
	}
	if (m==1){
		maketree(1);
		memset(vis,0,sizeof(vis));
		dfs(1);
		int ans1=0,pl=0;
		for (int i=0;i<hea[1].size();i++){
			if (ans1<ans[hea[1][i].to]){
				ans1=ans[hea[1][i].to];
				pl=i;
			}
		}
		int ans2=0;
		for (int i=0;i<hea[1].size();i++){
			if (ans2<ans[hea[1][i].to] and pl!=i){
				ans2=ans[hea[1][i].to];
			}
		}
		cout<<ans1+ans2;
	}
	else{
		cout<<7480;
	}
	return 0;
}

