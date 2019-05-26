#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define mp make_pair
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m;
int first[100010],cnte=-1;
struct edge{
	int to,next,w;
}a[200010];
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
int dep[100010],dis[100010],st[100010][20],jt[100010][20];
void dfs(int u,int f,int w){
	int i,v;
	st[u][0]=f;
	dep[u]=dep[f]+1;
	dis[u]=dis[f]+w;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u,a[i].w);
	}
}
void ST(){
	for(int j=1;j<=18;j++){
		for(int i=1;i<=n;i++){
			st[i][j]=st[st[i][j-1]][j-1];
		}
	}
}
inline int getlca(int l,int r){
	if(dep[l]>dep[r]) swap(l,r);
	int i;
	for(i=18;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
	if(l==r) return l;
	for(i=18;i>=0;i--){
		if(st[l][i]!=st[r][i]){
			l=st[l][i];
			r=st[r][i];
		}
	}
	return st[l][0];
}
inline pair<int,int> jump(int u,int d){
	int i;
	for(i=18;i>=0;i--){
		if(dis[u]-dis[st[u][i]]<=d){
			d-=dis[u]-dis[st[u][i]];
			u=st[u][i];
		}
	}
	return mp(u,d);
}
inline pair<int,int> big(int l,int lca,int d){
	int tl=l,re=0,rem=0;pair<int,int>tmp;
	while(dep[tl]>dep[lca]){
		tmp=jump(tl,d);
		if(dep[tmp.first]>dep[lca]){
			tl=tmp.first;re++;continue;
		}
		else{
			rem=(dis[tl]-dis[lca]);break;
		}
	}
	return mp(re,rem);
}
inline pair<int,int> small(int l,int lca,int d){
	int i,tl=l,re=0,rem=0;pair<int,int>tmp;
	for(i=18;i>=0;i--) if(dep[jt[tl][i]]>dep[lca]) tl=jt[tl][i],re+=(1<<i);
	rem=(dis[tl]-dis[lca]);
//	cout<<"small "<<l<<' '<<lca<<' '<<d<<' '<<re<<' '<<rem<<'\n';
	return mp(re,rem);
}
int ans[100010],blk;
inline void solve(int l,int r,int d,int num){
	if(l==r){ans[num]=0;return;}
	int lca=getlca(l,r);pair<int,int>tl,tr;
	tl=(d>blk)?big(l,lca,d):small(l,lca,d);
	tr=(d>blk)?big(r,lca,d):small(r,lca,d);
	int tmp=tl.second+tr.second;
	ans[num]=tl.first+tr.first+(tmp>d)+1;
}
struct query{
	int l,r,d,num;
}q1[100010],q2[100010];int cnt1,cnt2;
inline bool cmp(query l,query r){
	return l.d<r.d;
}
inline void solve1(){
	for(int i=1;i<=cnt2;i++) solve(q2[i].l,q2[i].r,q2[i].d,q2[i].num);
}
inline void init(int d){
	int i,j;
	for(i=1;i<=n;i++) jt[i][0]=jump(i,d).first;
	for(j=1;j<=18;j++){
		for(i=1;i<=n;i++) jt[i][j]=jt[jt[i][j-1]][j-1];
	}
}
inline void solve2(){
	for(int i=1;i<=cnt1;i++){
		if(q1[i].d!=q1[i-1].d) init(q1[i].d);
		solve(q1[i].l,q1[i].r,q1[i].d,q1[i].num);
	}
}
int main(){
	n=read();int i,t1,t2,t3;
	blk=sqrt(n);
	memset(first,-1,sizeof(first));
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	dfs(1,0,0);ST();
	m=read();
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		if(t3>blk) q2[++cnt2]=(query){t1,t2,t3,i};
		else q1[++cnt1]=(query){t1,t2,t3,i};
	}
	sort(q1+1,q1+cnt1+1,cmp);
	solve1();solve2();
	for(i=1;i<=m;i++) printf("%d\n",ans[i]);
}
