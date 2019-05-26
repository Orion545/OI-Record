#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char s=getchar();
	while (s<'0'or s>'9'){if (s=='-')f=-1;s=getchar();}
	while (s>='0'and s<='9'){x=(x<<3)+(x<<1)+s-'0';s=getchar();	}
	return x*f;
}
const int N=5010;
const int M=10010;
int he[M],to[M],r[M];
int head[N];
int n,m;
int edge;
void add(int u,int v){
	he[++edge]=u,to[edge]=v,r[edge]=edge;
	he[++edge]=v,to[edge]=u,r[edge]=edge;
	return ;
}
bool cmp(int x,int y){
	if (he[x]==he[y]){
		return to[x]<to[y];
	}
	return he[x]<he[y];
}
bool vis[N];
void dfs1(int u){
	printf("%d ",u);
	if (!head[u]){
		return ;
	}
	if (vis[u]){
		return ;
	}
	vis[u]=1;
	for (int i=head[u];he[r[i]]==u;i++){
		int e=r[i];
		if (vis[to[r[i]]]==0)dfs1(to[r[i]]);
	}
	return;
}
void dfs(int pre,int now,int p_n){
	if (vis[now]==0)printf("%d ",now);
	vis[now]=1;
	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	freopen("travel1.in","r",stdin);
	n=read();
	m=read();
	int u,v;
	for (int i=1;i<=m;i++){
		u=read(),v=read();
		add(u,v);
	}
	sort(r+1,r+1+edge,cmp);
	int temp=he[r[1]];
	head[temp]=1;
	for (int i=2;i<=edge;i++){
		if(he[r[i]]!=temp){
			temp=he[r[i]];
			head[temp]=i;
		}
	}
//	for (int i=1;i<=n;i++)cout << i<<"  "<<head[i]<<endl;
//	cout<<"ASasa"<<endl;
	if (m=n-1)dfs1(1);
	else dfs1(1);
	return 0;
}

