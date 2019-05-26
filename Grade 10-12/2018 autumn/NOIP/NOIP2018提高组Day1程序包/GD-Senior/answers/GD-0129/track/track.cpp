#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;
struct node{
	int to,val,next;
}e[50005];
int h[50005];
bool vis[50005];
int cnt=0;
void add(int x,int y,int z){
	e[++cnt].next=h[x];
	e[cnt].to=y;
	e[cnt].val=z;
	h[x]=cnt;
}
long long ans;
long long maxx(long long a,long long b){
	return a>b?a:b;
}
void dfs(int x,int fa,long long anss){
	for(int i=h[x];i;i=e[i].next){
		int v=e[i].to;
		if(v!=fa)
		dfs(v,x,anss+e[i].val);
	}
	ans=maxx(anss,ans);
}
int q[1050];
int tot;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<n;++i){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=n;++i){
		ans=0;
		dfs(i,0,0);
		q[++tot]=ans;
	}
	sort(q+1,q+n+1,cmp);
	cout<<q[m];
	return 0;
}
