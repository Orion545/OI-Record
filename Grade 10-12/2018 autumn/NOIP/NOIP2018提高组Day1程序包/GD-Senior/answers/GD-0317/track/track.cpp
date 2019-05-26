#include<bits/stdc++.h>
#define ll long long
#define now edge[i].v
#define go(x) for(int i=head[x];i;i=edge[i].nxt)
using namespace std;
const int sz=5e4+527;
int n,m;
int c[sz];
int u,v,w,cnt;
bool flag,vis[sz];
int head[sz],l[sz],d[sz];
struct Edge{
	int v,w,nxt;
}edge[sz<<1];
void add(int u,int v,int w){
	edge[++cnt]=(Edge){v,w,head[u]};
	head[u]=cnt;
}
void dfs1(int x){
	vis[x]=1;
	go(x) if(!vis[now]){
		dfs1(now);
		l[x]=max(l[x],l[now]);
		l[x]=max(l[x],edge[i].w+d[now]+d[x]);
		d[x]=max(d[x],d[now]+edge[i].w);
	}
}
bool check(ll sum){
	ll t=0,ret=0;
	for(int i=1;i<n;i++){
		t+=c[i];
		if(t>=sum) t=0,ret++;
	}
	return ret>=m;
}
void work1(){
	dfs1(1);
	printf("%d\n",l[1]);
}
void work2(){
	ll L=1,R=500000000,ans=0;
	while(L<=R){
		ll mid=(L+R)>>1;
		if(check(mid)) ans=L,L=mid+1;
		else R=mid-1;
	}
	printf("%d\n",ans);
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	flag=1;
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
		if(v!=u+1) flag=false;
		else if(flag) c[u]=w;
	}
	if(m==1) work1();
	if(flag) work2();
}
