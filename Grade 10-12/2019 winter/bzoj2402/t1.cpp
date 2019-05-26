#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
#define S s[cur].size()
#define ll long long
#define ld long double
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
namespace seg1{
	ld x[30010],y[30010];
	vector<int>s[120010];
	inline void insert(int cur,int num){
		while((S>1)&&(((x[s[cur][S-1]]-x[num])*(y[s[cur][S-2]]-y[s[cur][S-1]])-(x[s[cur][S-2]]-x[s[cur][S-1]])*(y[s[cur][S-1]]-y[num]))<1e-10)) s[cur].pop_back();
		s[cur].push_back(num);
	}
	inline void build(int l,int r,int num){
		if(l==r){s[num].push_back(l);return;}
		int mid=(l+r)>>1;
		build(l,mid,num<<1);build(mid+1,r,num<<1|1);
		int sizl=s[num<<1].size(),sizr=s[num<<1|1].size(),pl=0,pr=0;
		while(pl<sizl||pr<sizr){
			if(pr==sizr||(pl<sizl&&x[s[num<<1][pl]]<x[s[num<<1|1][pr]])) insert(num,s[num<<1][pl]),pl++;
			else insert(num,s[num<<1|1][pr]),pr++;
		}
	}
	inline ld query(int l,int r,int ql,int qr,int num,ld k){
//		cout<<"seg1 query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<k<<'\n';
		if(l>=ql&&r<=qr){
			int bl=1,br=s[num].size()-1,bmid,ans=0;
			while(bl<=br){
				bmid=(bl+br)>>1;
				if(y[s[num][bmid]]-x[s[num][bmid]]*k-1e-10>y[s[num][bmid-1]]-k*x[s[num][bmid-1]]) bl=bmid+1,ans=bmid;
				else br=bmid-1;
			}
//			cout<<"	reach query end "<<ans<<' '<<y[s[num][bl]]-k*x[s[num][bl]]<<'\n';
			return y[s[num][ans]]-k*x[s[num][ans]];
		}
		int mid=(l+r)>>1;ld re=-1e16;
		if(mid>=ql) re=max(re,query(l,mid,ql,qr,num<<1,k));
		if(mid<qr) re=max(re,query(mid+1,r,ql,qr,num<<1|1,k));
		return re;
	}
}
namespace seg2{
	ld x[30010],y[30010];
	vector<int>s[120010];
	inline void insert(int cur,int num){
		while((S>1)&&(((x[s[cur][S-1]]-x[num])*(y[s[cur][S-2]]-y[s[cur][S-1]])-(x[s[cur][S-2]]-x[s[cur][S-1]])*(y[s[cur][S-1]]-y[num]))<1e-10)) s[cur].pop_back();
		s[cur].push_back(num);
	}
	inline void build(int l,int r,int num){
		if(l==r){s[num].push_back(l);return;}
		int mid=(l+r)>>1;
		build(l,mid,num<<1);build(mid+1,r,num<<1|1);
		int sizl=s[num<<1].size(),sizr=s[num<<1|1].size(),pl=0,pr=0;
		while(pl<sizl||pr<sizr){
			if(pr==sizr||(pl<sizl&&x[s[num<<1][pl]]<x[s[num<<1|1][pr]])) insert(num,s[num<<1][pl]),pl++;
			else insert(num,s[num<<1|1][pr]),pr++;
		}
	}
	inline ld query(int l,int r,int ql,int qr,int num,ld k){
//		cout<<"seg2 query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<k<<'\n';
		if(l>=ql&&r<=qr){
			int bl=1,br=s[num].size()-1,bmid,ans=0;
			while(bl<=br){
				bmid=(bl+br)>>1;
				if(y[s[num][bmid]]-x[s[num][bmid]]*k-1e-10>y[s[num][bmid-1]]-k*x[s[num][bmid-1]]) bl=bmid+1,ans=bmid;
				else br=bmid-1;
			}
//			cout<<"	reach query end "<<ans<<' '<<y[s[num][bl]]-k*x[s[num][bl]]<<'\n';
			return y[s[num][ans]]-k*x[s[num][ans]];
		}
		int mid=(l+r)>>1;ld re=-1e16;
		if(mid>=ql) re=max(re,query(l,mid,ql,qr,num<<1,k));
		if(mid<qr) re=max(re,query(mid+1,r,ql,qr,num<<1|1,k));
		return re;
	}
}
int n,m,first[30010],cnte=-1;ld x[30010],y[30010],p[30010],q[30010];
struct edge{
	int to,next;
}a[60010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int dep[30010],siz[30010],son[30010],top[30010],dfn[30010],back[30010],fa[30010],clk=0;;
void dfs1(int u,int f){
	int i,v;
	fa[u]=f;dep[u]=dep[f]+1;
	siz[u]=1;son[u]=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int f,int t){
	int i,v;
	top[u]=t;
	dfn[u]=++clk;
	back[clk]=u;
	seg1::x[clk]=x[u];seg1::y[clk]=y[u];
	seg2::x[clk]=p[u];seg2::y[clk]=q[u];
//	cout<<"dfs2 "<<u<<' '<<f<<' '<<top[u]<<' '<<dep[u]<<' '<<dfn[u]<<'\n';
	if(son[u]) dfs2(son[u],u,t);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||v==son[u]) continue;
		dfs2(v,u,v);
	}
}
ld check(int u,int v,ld mid){
	ld ans1=-1e16,ans2=-1e16;
	while(top[u]!=top[v]){
		if(dep[top[u]]>dep[top[v]]) swap(u,v);
		ans1=max(ans1,seg1::query(1,n,dfn[top[v]],dfn[v],1,mid));
		ans2=max(ans2,seg2::query(1,n,dfn[top[v]],dfn[v],1,mid));
		v=fa[top[v]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	ans1=max(ans1,seg1::query(1,n,dfn[u],dfn[v],1,mid));
	ans2=max(ans2,seg2::query(1,n,dfn[u],dfn[v],1,mid));
//	cout<<"check "<<mid<<' '<<ans1<<' '<<ans2<<'\n';
	return ans1+ans2;
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();int i,t1,t2;ld l,mid,r;
	for(i=1;i<=n;i++) scanf("%Lf",&x[i]);
	for(i=1;i<=n;i++) scanf("%Lf",&y[i]);
	for(i=1;i<=n;i++) scanf("%Lf",&p[i]);
	for(i=1;i<=n;i++) scanf("%Lf",&q[i]);
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	dfs1(1,0);dfs2(1,0,1);
	seg1::build(1,n,1);
	seg2::build(1,n,1);
	m=read();
	while(m--){
		t1=read();t2=read();
		l=0,r=1e8;i=50;
		while(i--){
			mid=(l+r)*0.5;
			if(check(t1,t2,mid)>1e-18) l=mid;
			else r=mid;
		}
		printf("%.4lf\n",(double)l);
	}
}
