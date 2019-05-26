#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,k,first[100010],cnte,siz[100010],son[100010],root,sum;
int vis[100010];
struct BIT{
	int a[100010],len;
	void clear(){
		memset(a,0,sizeof(a));len=100000;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int x,int val){
		cout<<"	add "<<x<<' '<<val<<'\n';
		for(;x<=len;x+=lowbit(x)) a[x]+=val;
	}
	int sum(int x){
		int re=0;
//		cout<<"	sum "<<x<<' ';
		for(;x>0;x-=lowbit(x)) re+=a[x];
//		cout<<re<<'\n';
		return re;
	}
}T;
unordered_map<int,int>pos;
struct edge{
	int to,next,w;
}a[200010];
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
void getroot(int u,int f){
	int i,v;siz[u]=1;son[u]=0;
	cout<<"getroot "<<u<<' '<<f<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]||v==f) continue;
		getroot(v,u);
		siz[u]+=siz[v];
		son[u]=max(son[u],siz[v]);
	}
	son[u]=max(son[u],sum-siz[u]);
	cout<<"finish dfs "<<u<<' '<<siz[u]<<' '<<son[u]<<'\n';
	if(son[u]<son[root]) root=u;
}
struct node{
	int maxn,minn;
}x[100010];int cntn;
ll ans=0;
bool cmp(node l,node r){
	return l.maxn<r.maxn;
}
void get(int u,int f,int fa,int w){
	int i,v,cur;
	if(~w){
		cur=++cntn;
		x[cur].maxn=max(x[f].maxn,w);
		x[cur].minn=min(x[f].minn,w);
	}
	else cur=cntn;
	cout<<"	get "<<u<<' '<<f<<' '<<w<<' '<<cur<<' '<<x[cur].maxn<<' '<<x[cur].minn<<'\n';
	if(x[cur].maxn-x[cur].minn>k){cntn--;return;}
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==fa||vis[v]) continue;
		get(v,cur,u,a[i].w);
	}
//	cout<<"finish get "<<u<<'\n';
}
int calc(int u,int st){
	int re=0,i;cntn=1;
	if(~st) x[1].maxn=x[1].minn=st;
	else x[1].maxn=0,x[1].minn=2e9;
	get(u,0,0,-1);
	sort(x+2,x+cntn+1,cmp);
	if(st==-1) ans+=cntn-1;
	cout<<"****************** finish get "<<u<<' '<<st<<' '<<cntn<<' '<<ans<<'\n';
	T.clear();
	for(i=2;i<=cntn;i++){
		re+=T.sum(pos[x[i].maxn])-T.sum(pos[x[i].maxn-k]-1);
		T.add(pos[x[i].minn],1);
		cout<<i<<' '<<re<<'\n';
	}
	cout<<"****************** finish calc "<<u<<' '<<st<<' '<<re<<' '<<ans<<'\n';
	return re;
}
int sz[100010];
void getsz(int u,int f){
	int i,v;sz[u]=1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		getsz(v,u);
		sz[u]+=sz[v];
	}
}
void dfs(int u){
	int i,v;vis[u]=1;
	cout<<"dfs "<<u<<'\n';
	cntn=1;
	x[1].maxn=0,x[1].minn=2e9;
	ans+=calc(u,-1);
	getsz(u,0);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		ans-=calc(v,a[i].w);
		sum=sz[v];son[0]=sum;root=0;
		getroot(v,0);
		dfs(root);
	}
}
struct nd{
	int val,rk,num;
}e[200010];int cntl;
bool cmp1(nd l,nd r){
	return l.val<r.val;
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();k=read();int i,t1,t2,t3;
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
		e[++cntl]=(nd){t3,0,cntl};
		e[++cntl]=(nd){max(t3-k,0),0,cntl};
	}
	sort(e+1,e+cntl+1,cmp1);t2=0;
	for(i=1;i<=cntl;i++){
		t2++;
		while(e[i].val==e[i+1].val) i++;
		pos[e[i].val]=t2;
	}
	sum=n;son[0]=n;root=0;
	getroot(1,0);
	dfs(root);
	printf("%lld\n",ans);
}
