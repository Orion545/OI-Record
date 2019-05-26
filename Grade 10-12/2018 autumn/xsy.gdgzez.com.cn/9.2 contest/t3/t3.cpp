#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,k,first[2010],root[2010],ch[4000010][2],siz[4000010],st[2010][15],dep[2010];
struct edge{
	int to,next,w;
}a[4010];int cnte,cnt;
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
int build(int l,int r,int pos,int pre){
	int cur=++cnt;
	ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];siz[cur]=siz[pre]+1;
	if(l==r) return cur;
	int mid=(l+r)>>1;
	if(mid>=pos) ch[cur][0]=build(l,mid,pos,ch[pre][0]);
	else ch[cur][1]=build(mid+1,r,pos,ch[pre][1]);
	return cur;
}
int query1(int l,int r,int u,int v,int f){
	if(l==r) return l;
	int tmp=siz[ch[u][0]]+siz[ch[v][0]]-(siz[ch[f][0]]<<1),mid=(l+r)>>1;
	if(tmp) return query1(l,mid,ch[u][0],ch[v][0],ch[f][0]);
	else return query1(mid+1,r,ch[u][1],ch[v][1],ch[f][1]);
}
int query2(int l,int r,int u,int v,int f){
	if(l==r) return l;
	int tmp=siz[ch[u][1]]+siz[ch[v][1]]-(siz[ch[f][1]]<<1),mid=(l+r)>>1;
	if(tmp) return query2(mid+1,r,ch[u][1],ch[v][1],ch[f][1]);
	else return query2(l,mid,ch[u][0],ch[v][0],ch[f][0]);
}
void dfs(int u,int f,int w){
	int i,v;
	if(u!=1) root[u]=build(0,1e9,w,root[f]);
	dep[u]=dep[f]+1;st[u][0]=f;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u,a[i].w);
	}
}
void ST(){
	int i,j;
	for(j=1;j<=15;j++){
		for(i=1;i<=n;i++) 
			st[i][j]=st[st[i][j-1]][j-1];
	}
}
int lca(int l,int r){
	int i;
	if(dep[l]>dep[r]) swap(l,r);
	for(i=15;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
	if(l==r) return l;
	for(i=15;i>=0;i--){
		if(st[r][i]!=st[l][i]){
			r=st[r][i];
			l=st[l][i];
		}
	}
	return st[l][0];
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();k=read();int i,t1,t2,t3;
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	dfs(1,0,0);int ans=0;
	for(t1=1;t1<n;t1++){
		for(t2=t1+1;t2<=n;t2++){
			t3=lca(t1,t2);
			ans+=(query2(0,1e9,root[t1],root[t2],root[t3])-query1(0,1e9,root[t1],root[t2],root[t3])<=k);
		}
	}
	printf("%d\n",ans);
}

