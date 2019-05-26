#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<map>
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
map<int,int>mp;
int n,x[10010],y[10010],val[20010],id[20010],cntv;
void init(){
	int i,p;
	for(i=1;i<=n;i++) val[++cntv]=x[i],val[++cntv]=y[i];
	sort(val+1,val+cntv+1);
	for(i=1;i<=cntv;i++) if(val[i]!=val[i-1]) mp[val[i]]=i;
	for(i=1;i<=n;i++){
		p=x[i];x[i]=mp[x[i]];mp[p]++;
		p=y[i];y[i]=mp[y[i]];mp[p]++;
		id[x[i]]=i;id[y[i]]=n+i;
	}
//	for(i=1;i<=n;i++) cout<<i<<' '<<x[i]<<' '<<y[i]<<'\n';
//	for(i=1;i<=cntv;i++) cout<<i<<' '<<val[i]<<' '<<id[i]<<'\n';
}
int first[100010],cnte;
struct edge{
	int to,next;
}a[4000010];
inline void add(int u,int v){
//	cout<<"		addedge "<<u<<' '<<v<<'\n';
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
}
struct segtree{
	int a[80010],tot,cnt,pid[80010];
	void init(){
		tot=n<<1;cnt=0;
		memset(a,0,sizeof(a));
		memset(pid,0,sizeof(pid));
	}
	void build(int l,int r,int num){
		pid[num]=++cnt;
//		cout<<"build "<<l<<' '<<r<<' '<<num<<' '<<pid[ num]<<'\n'; 
		if(l==r){
			add(tot+pid[num],id[l]);
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,num<<1);build(mid+1,r,num<<1|1);
		add(tot+pid[num],tot+pid[num<<1]);
		add(tot+pid[num],tot+pid[num<<1|1]);
	}
	void link(int l,int r,int ql,int qr,int num,int u){
//		cout<<"		link "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<num<<' '<<u<<'\n';
		if(l>=ql&&r<=qr){
			add(u,tot+pid[num]);return;
		}
		int mid=(l+r)>>1;
		if(mid>=ql) link(l,mid,ql,qr,num<<1,u);
		if(mid<qr) link(mid+1,r,ql,qr,num<<1|1,u);
	}
}T;
int dfn[100010],low[100010],clk,s[100010],top,ins[100010],belong[100010],bcc;
void reset(){
	memset(first,-1,sizeof(first));cnte=bcc=0;
	memset(a,0,sizeof(a));memset(belong,0,sizeof(belong));
	memset(dfn,0,sizeof(dfn));memset(low,0,sizeof(low));
	T.init();
}
void tarjan(int u){
	int i,v;s[++top]=u;ins[u]=1;
	dfn[u]=low[u]=++clk;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		bcc++;
		while(s[top]!=u){
			belong[s[top]]=u;ins[s[top]]=0;
			s[top--]=0;
		}
		belong[s[top]]=u;ins[s[top]]=0;
		s[top--]=0;
	}
}
bool solve(int mid){
//	cout<<"solve "<<mid<<'\n'; 
	reset();T.build(1,cntv,1);
	int i,l,r;
	for(i=1;i<=n;i++){
		l=lower_bound(val+1,val+cntv+1,val[x[i]]-mid+1)-val;
		r=upper_bound(val+1,val+cntv+1,val[x[i]]+mid-1)-val-1;
//		cout<<"	insert "<<i<<' '<<x[i]<<' '<<val[x[i]]<<' '<<l<<' '<<r<<'\n';
		if(l<=r){
			if(l<x[i]) T.link(1,cntv,l,x[i]-1,1,n+i);
			if(r>x[i]) T.link(1,cntv,x[i]+1,r,1,n+i);
		}
		l=lower_bound(val+1,val+cntv+1,val[y[i]]-mid+1)-val;
		r=upper_bound(val+1,val+cntv+1,val[y[i]]+mid-1)-val-1;
//		cout<<"	insert "<<i<<' '<<y[i]<<' '<<val[y[i]]<<' '<<l<<' '<<r<<'\n';
		if(l<=r){
			if(l<y[i]) T.link(1,cntv,l,y[i]-1,1,i);
			if(r>y[i]) T.link(1,cntv,y[i]+1,r,1,i);
		}
	}
	for(i=1;i<=(n<<1);i++) if(!dfn[i]) tarjan(i);
	for(i=1;i<=n;i++) if(belong[i]==belong[i+n]) return 0;
	return 1;
}
int main(){
	n=read();int i,l,r,mid;
	for(i=1;i<=n;i++) x[i]=read(),y[i]=read();
	init();
	l=0;r=1e9;
	while(l<r){
		mid=(l+r)>>1;mid++;
		if(solve(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
}

