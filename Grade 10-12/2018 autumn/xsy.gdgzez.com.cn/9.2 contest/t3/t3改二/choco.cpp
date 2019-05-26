#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,K,first[100010],cnte,siz[100010],sum,root,son[100010];
struct edge{
	int to,next,w;
}a[200010];
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
int vis[100010];
void getroot(int u,int f){
	int i,v;siz[u]=1;son[u]=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		getroot(v,u);
		siz[u]+=siz[v];
		son[u]=max(son[u],siz[v]);
	}
	son[u]=max(son[u],sum-siz[u]);
	if(son[u]<son[root]) root=u;
}
struct node{
	int u,sub,minn,maxn;
}x[100010];int cntx;
inline bool cmp(node l,node r){
	return l.maxn<r.maxn;
}
void getinfo(int u,int f,int maxn,int minn,int sub){
	int i,v;
//	cout<<"	getinfo "<<u<<' '<<f<<' '<<maxn<<' '<<minn<<' '<<sub<<'\n';
	if((~maxn)&&(~minn)){
		if(maxn-minn<=K){
			cntx++;
			x[cntx]=(node){u,sub,minn,maxn};
		}
		else return;
	}
	else maxn=-2e9,minn=2e9;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		getinfo(v,u,max(maxn,a[i].w),min(minn,a[i].w),(f==0)?v:sub);
	}
}
int d[200010],cntd;
void lisan(){
	int i;
	cntd=0;
	for(i=1;i<=cntx;i++){
		d[++cntd]=x[i].minn;
		d[++cntd]=x[i].maxn;
	}
	sort(d+1,d+cntd+1);
	cntd=unique(d+1,d+cntd+1)-d-1;
	for(i=1;i<=cntx;i++){
		x[i].maxn=lower_bound(d+1,d+cntd+1,x[i].maxn)-d;
		x[i].minn=lower_bound(d+1,d+cntd+1,x[i].minn)-d;
	}
	sort(x+1,x+cntx+1,cmp);
//	for(i=1;i<=cntx;i++) cout<<i<<' '<<x[i].u<<' '<<x[i].maxn<<' '<<x[i].minn<<'\n';
}
struct BIT{
	int a[200010],len;
	void clear(int llen){
		for(int i=1;i<=len;i++) a[i]=0;
		len=llen;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int x,int val){
//		cout<<"		add "<<x<<' '<<val<<'\n';
		for(;x<=len;x+=lowbit(x)) a[x]+=val;
	}
	int sum(int x){
		int re=0;
//		cout<<"		getsum "<<x<<' ';
		for(;x>0;x-=lowbit(x)) re+=a[x];
//		cout<<re<<'\n';
		return re;
	}
}T;
int getpos(int pos){
//	cout<<"		getpos "<<pos<<' '<<lower_bound(d+1,d+cntd+1,pos)-d<<'\n';
	return lower_bound(d+1,d+cntd+1,pos)-d;
}
ll calc(int u){
	int i,pos;ll re=0,sum=0;
	T.clear(cntd);
//	cout<<"	calc "<<u<<'\n';
	for(i=1;i<=cntx;i++){
		if(u&&x[i].sub!=u) continue;
		sum++;
//		cout<<"		do "<<i<<' '<<x[i].maxn<<' '<<x[i].minn<<'\n';
		pos=getpos(d[x[i].maxn]-K);
		re+=T.sum(x[i].maxn)-T.sum(pos-1);
		T.add(x[i].minn,1);
	}
//	cout<<"	finish "<<re<<' '<<sum<<'\n';
	return re+(u?0:sum);
}
ll ans=0;
void dfs(int u,int sz){
	int i,v;vis[u]=1;cntx=0;
//	cout<<"dfs "<<u<<' '<<sz<<'\n';
	getinfo(u,0,-1,-1,-1);
	lisan();
	ans+=calc(0);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		ans-=calc(v);
	}
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		sum=((siz[v]>siz[u])?(sz-siz[u]):siz[v]);
		root=0;son[0]=sum;
		getroot(v,0);
		dfs(root,sum);
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();K=read();int i,t1,t2,t3;
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	sum=n;root=0;son[0]=n;
	getroot(1,0);
	dfs(root,n);
	printf("%lld\n",ans);
}
