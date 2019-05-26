#include<iostream>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxN=5010;
struct bian{
	int po,next;
}edge[maxN*2];
int head[maxN],tot;
int n,m,num=1;
int ans[maxN],nans[maxN];
int pre[maxN][maxN],p[maxN];
bool book[maxN];

void insert(int x,int y)
{
	edge[++tot].po=y;
	edge[tot].next=head[x];
	head[x]=tot;
}

inline void work()
{
	for(int i=1;i<=n;++i){
		if(ans[i]==nans[i])
			continue;
		else if(ans[i]>nans[i])
			break;
		else{
			swap(ans,nans);
			break;
		}
	}
}

inline void qsort(int l,int r,int x)
{
	if(l>=r)
		return;
	int t=pre[x][rand()%(r-l+1)+l];
	int i=l,j=r;
	while(i<=j){
		while(pre[x][i]<t)i++;
		while(pre[x][j]>t)j--;
		if(i<=j){
			swap(pre[x][i],pre[x][j]);
			i++;
			j--;
		}
	}
	qsort(l,j,x);
	qsort(i,r,x);
}

inline void dfs(int x,int fa)
{
	int t=head[x];
	p[x]=0;
	while(t!=0){
		int y=edge[t].po;
		if(y!=fa&&book[y]==false){
			pre[x][++p[x]]=y;
		}
		t=edge[t].next;
	}
	if(p!=0){
		srand(1000000);
		qsort(1,p[x],x);
		for(int i=1;i<=p[x];++i){
			ans[++num]=pre[x][i];
			book[pre[x][i]]=true;
			dfs(pre[x][i],x);
		}
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		insert(u,v);
		insert(v,u);
	}
	ans[1]=1;
	dfs(1,0);
	for(int i=1;i<=n;++i)
		cout<<ans[i]<<" ";
	return 0;
}
