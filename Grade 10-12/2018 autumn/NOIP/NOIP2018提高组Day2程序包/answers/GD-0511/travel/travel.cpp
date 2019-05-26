#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define maxn 5005
#define INF 0x7fffffff
using namespace std;
inline int qread(){
	int x=0;
	char c=getchar();
	while(c<48||c>57){
		c=getchar();
	} 
	while(c>=48&&c<=57){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int n,m;
int from[maxn];
int to[maxn];
vector<int>E[maxn];


int cnt=0;
int seq[maxn];
int ans[maxn];
int du,dv;
int used[maxn];
void dfs(register int x){
	used[x]=1;
	seq[++cnt]=x;
	int p=E[x].size();
	for(register int i=0;i<p;i++){
		register int y=E[x][i];
		if((x==du&&y==dv)||(x==dv&&y==du)) continue;
		if(!used[y]) dfs(y);
	}
}

int is_lower(){
	for(int i=1;i<=n;i++){
		if(seq[i]>ans[i]) return 0;
		else if(seq[i]<ans[i]) return 1;
		else continue;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int u,v;
	n=qread();
	m=qread();
	for(register int i=1;i<=m;i++){
		u=qread();
		v=qread();
		E[u].push_back(v);
		E[v].push_back(u);
		from[i]=u;
		to[i]=v;
	}
	for(register int i=1;i<=n;i++){
		sort(E[i].begin(),E[i].end());
	}
	if(m==n-1){
		du=dv=-1;
		dfs(1);
		for(int i=1;i<=n;i++){
			printf("%d ",seq[i]);
		}
	}else{
		ans[1]=INF;
		for(register int i=1;i<=m;i++){
			du=from[i];
			dv=to[i];
			cnt=0;
			memset(used,0,sizeof(used));
			dfs(1);
			if(cnt<n) continue;
			if(is_lower()){
				for(register int i=1;i<=n;i++) ans[i]=seq[i];
			}
		}
		for(register int i=1;i<=n;i++){
			printf("%d ",ans[i]);
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

