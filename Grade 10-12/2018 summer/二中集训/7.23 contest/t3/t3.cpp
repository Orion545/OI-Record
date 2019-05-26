#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<ctime>
#define ll long long
#define log lg2
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
int n,q,first[100010],cnte,son[100010],siz[100010],fa[100010],dep[100010],app[100010],sum;
int rt,log[500010],euler[500010],cntu=0,st[500010][20],back[500010];
struct edge{
	int to,next;
}a[200010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void getdep(int u,int f){
	int i,v;dep[u]=dep[f]+1;euler[++cntu]=dep[u];app[u]=cntu;back[cntu]=u;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		getdep(v,u);
		euler[++cntu]=dep[u];back[cntu]=u;
	}
}
void ST(){
	log[1]=0;
	int i,j,l,r;
	for(i=2;i<=cntu;i++) log[i]=log[i>>1]+1;
	for(i=1;i<=cntu;i++) st[i][0]=i;
	for(j=1;j<=19;j++){
//		cout<<j<<' '<<log[1<<j]<<'\n';
		for(i=1;i+(1<<j)<=cntu;i++){
//			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
			l=st[i][j-1];r=st[i+(1<<(j-1))][j-1];
			st[i][j]=(euler[l]<euler[r])?l:r;
		}
	}
}
int lca(int l,int r){
//	cout<<"lca "<<l<<' '<<r<<' ';
	l=app[l];r=app[r];
	if(l>r) swap(l,r);
	int k=log[r-l+1],x,y,re;
	x=st[l][k];y=st[r-(1<<k)+1][k];
	re=((euler[x]<euler[y])?x:y); 
//	cout<<l<<' '<<r<<' '<<re<<' '<<'\n';
	return back[re];
}
int getdis(int l,int r){
	return dep[l]+dep[r]-2*dep[lca(l,r)];
}

bool vis[100010]={0};
void getroot(int u,int f){
//	cout<<"getroot "<<u<<' '<<f<<'\n';
	int i,v;siz[u]=1;son[u]=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]||v==f) continue;
		getroot(v,u);
		siz[u]+=siz[v];son[u]=max(son[u],siz[v]);
	}
	son[u]=max(son[u],sum-siz[u]);
	if(son[rt]>son[u]) rt=u;
}
void build(int u){
	int i,v;vis[u]=1;
//	cout<<"build "<<u<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		rt=0;son[rt]=1e9;sum=siz[v];
		getroot(v,0);fa[rt]=u;build(rt);
	}
}

int root[100010][2],lazy[20000010],cnt,ch[20000010][2];
void insert(int &cur,int l,int r,int ql,int qr,int val){
	if(!cur) cur=++cnt;
	if(l==ql&&r==qr){lazy[cur]+=val;return;}
	int mid=(l+r)>>1;
	if(qr<=mid) insert(ch[cur][0],l,mid,ql,qr,val);
	else{
		if(ql>mid) insert(ch[cur][1],mid+1,r,ql,qr,val);
		else{
			insert(ch[cur][0],l,mid,ql,mid,val);
			insert(ch[cur][1],mid+1,r,mid+1,qr,val);
		}
	}
}
void update(int u,int d,int val){
//	cout<<"update "<<u<<' '<<d<<' '<<val<<'\n'; 
	int tmp=u,dis;
	insert(root[u][0],0,n,0,d,val);
	for(;fa[u];u=fa[u]){
		dis=d-getdis(tmp,fa[u]);
		if(dis<0) continue;
		insert(root[fa[u]][0],0,n,0,dis,val);
		insert(root[u][1],0,n,0,dis,val);
	}
}
int query(int cur,int l,int r,int pos){
	if(!cur) return 0;
	if(l==r) return lazy[cur];
	int mid=(l+r)>>1;
	if(pos<=mid) return lazy[cur]+query(ch[cur][0],l,mid,pos);
	else return lazy[cur]+query(ch[cur][1],mid+1,r,pos);
}
int getans(int u){
//	cout<<"getans "<<u<<'\n';
	int re=query(root[u][0],0,n,0),tmp=u;
	for(;fa[u];u=fa[u]){
		re+=query(root[fa[u]][0],0,n,getdis(tmp,fa[u]))-query(root[u][1],0,n,getdis(tmp,fa[u]));
	}
	return re;
}
int main(){
//	freopen("10.in","r",stdin);
//	freopen("my.out","w",stdout);
	memset(first,-1,sizeof(first));
	n=read();q=read();int i,t1,t2,t3;char s[10];
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	getdep(1,0);ST();
	son[rt]=1e9;rt=0;sum=n;
	getroot(1,0);build(rt);
	
	for(i=1;i<=q;i++){
		scanf("%s",s);
		if(s[0]=='Q'){
			t1=read();
			printf("%d\n",getans(t1));
		}
		else{
			t1=read();t2=read();t3=read();
			update(t1,t2,t3);
		}
	}
}
/*
10 0
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10

*/
