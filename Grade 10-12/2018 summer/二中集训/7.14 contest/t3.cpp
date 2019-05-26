#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector> 
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

int ch[4000010][2],siz[4000010],rt[100010],cnt;
void update(int pos){
	siz[pos]=siz[ch[pos][0]]+siz[ch[pos][1]]+1;
}
int insert(int l,int r,int pre,int pos){
	int cur=++cnt,mid=(l+r)>>1;
	siz[cur]=siz[pre]+1;ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];
	if(l==r) return cur;
	if(mid>=pos) ch[cur][0]=insert(l,mid,ch[pre][0],pos);
	else ch[cur][1]=insert(mid+1,r,ch[pre][1],pos);
	return cur;
}
int query(int l,int r,int u,int v,int lca,int flca,int k){
	if(l==r) return l;
	int mid=(l+r)>>1,tmp=siz[ch[u][0]]+siz[ch[v][0]]-siz[ch[lca][0]]-siz[ch[flca][0]];
//	cout<<"query "<<l<<' '<<r<<' '<<k<<' '<<tmp<<'\n';
	if(tmp>=k) return query(l,mid,ch[u][0],ch[v][0],ch[lca][0],ch[flca][0],k);
	else return query(mid+1,r,ch[u][1],ch[v][1],ch[lca][1],ch[flca][1],k-tmp);
}

int n,m,first[100010],dep[100010],st[100010][20],cnte;
int val[100010],rk[100010],back[100010];
struct edge{
	int to,next;
}a[200010];
bool cmp(int l,int r){
	return val[l]<val[r];
}
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs1(int u,int f){
	int i,v;dep[u]=dep[f]+1;st[u][0]=f;
//	cout<<"dfs "<<u<<' '<<f<<' '<<dep[u]<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs1(v,u);
	}
}
void ST(){
	for(int j=1;j<=19;j++){
		for(int i=1;i<=n;i++){
			st[i][j]=st[st[i][j-1]][j-1];
		}
	}
}
void dfs2(int u,int f){
	int i,v;rt[u]=insert(1,n,rt[f],rk[u]);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs2(v,u);
	}
}
int lca(int u,int v){
	int i;
	if(dep[u]>dep[v]) swap(u,v);
	for(i=19;i>=0;i--) if(dep[st[v][i]]>=dep[u]) v=st[v][i];
	if(u==v) return u;
	for(i=19;i>=0;i--){
		if(st[u][i]!=st[v][i]){
			u=st[u][i];
			v=st[v][i];
		}
	}
	return st[u][0];
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2,t3,t4,tans=0;
	for(i=1;i<=n;i++) val[i]=read(),back[i]=i;
	sort(back+1,back+n+1,cmp);
	for(i=1;i<=n;i++) rk[back[i]]=i;
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	dfs1(1,0);ST();dfs2(1,0);
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();t1^=tans;
		t4=lca(t1,t2);
		tans=val[back[query(1,n,rt[t1],rt[t2],rt[t4],rt[st[t4][0]],t3)]];
		printf("%d\n",tans);
	}
}
