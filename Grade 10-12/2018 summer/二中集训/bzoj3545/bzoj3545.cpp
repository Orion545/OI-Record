#include<iostream>
#include<cstdio>
#include<cstring>
#include<cassert>
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

struct edge{int from,to,w;}e[500010];
bool cmpe(edge l,edge r){return l.w<r.w;}

struct ques{int st,lim,k,ans,num;}q[500010];
bool cmp1(ques l,ques r){return l.lim<r.lim;}
bool cmp2(ques l,ques r){return l.num<r.num;}

int ufs[1000010],v[1000010];
int find(int x){
	return ((ufs[x]==x)?x:ufs[x]=find(ufs[x]));
}
int fa[1000010],ch[1000010][2],siz[1000010],w[1000010],root[1000010],cnt;
void update(int x){
	siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;
}
bool get(int x){
	return ch[fa[x]][1]==x;
}
void rotate(int x){
	int f=fa[x],ff=fa[f],son=get(x);
	ch[f][son]=ch[x][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	fa[f]=x;ch[x][son^1]=f;
	fa[x]=ff;
	if(ff) ch[ff][ch[ff][1]==f]=x;
	update(f);update(x);
}
void splay(int x,int to){
	if(x==to||fa[x]==to) return;
	for(int f;(f=fa[x])!=to;rotate(x))
		if(fa[f]!=to)
			rotate((get(f)==get(x))?f:x);
}
int getrank(int x,int val){
//	cout<<"   getrank "<<x<<' '<<val<<' '<<siz[ch[x][0]]<<' '<<siz[ch[x][1]]<<'\n';
	assert(x);
	if(siz[ch[x][1]]+1==val) return v[w[x]];
	if(siz[ch[x][1]]+1<val) return getrank(ch[x][0],val-siz[ch[x][1]]-1);
	else return getrank(ch[x][1],val);
}
void insert(int &x,int k,int f,int rt){
//	cout<<"		insert "<<x<<' '<<k<<' '<<f<<' '<<rt<<' '<<ch[x][0]<<' '<<ch[x][1]<<'\n';
	assert(x!=k);
	if(!x){
		x=++cnt;
		siz[x]=1;ch[x][0]=ch[x][1]=0;w[x]=k;
		fa[x]=f;splay(x,root[rt]);return;
	}
	siz[x]++;
	if(v[w[x]]>=v[k]) insert(ch[x][0],k,x,rt);
	else insert(ch[x][1],k,x,rt);
//	cout<<"		finish insert "<<x<<' '<<siz[x]<<'\n';
}
void dfs(int x,int f){
	int lc=ch[x][0],rc=ch[x][1];
// 	cout<<"   dfs "<<x<<' '<<f<<' '<<lc<<' '<<rc<<'\n';
	if(lc) dfs(lc,f);
	if(rc) dfs(rc,f);
	insert(root[f],w[x],0,f);
}
void merge(int x,int y){
//	cout<<"merge "<<x<<' '<<y<<' '<<root[x]<<' '<<root[y]<<' '<<siz[root[x]]<<' '<<siz[root[y]]<<'\n';
	if(siz[root[x]]<siz[root[y]]) swap(x,y);
	ufs[y]=x;
	dfs(root[y],x);
}
int ask(int x,int val){
	int f=root[x];
//	cout<<"ask "<<x<<' '<<f<<' '<<siz[f]<<'\n';
	if(siz[f]<val) return -1;
	else return getrank(f,val);
}
int n,m,Q;
int main(){
//	freopen("2.in","r",stdin);
//	freopen("bzoj3545.out","w",stdout);
	n=read();m=read();int i,j,t1,t2,t3,fx,fy;
	Q=read();
	for(i=1;i<=n;i++) v[i]=read(),siz[i]=1,ufs[i]=root[i]=w[i]=i;
	cnt=n;
//	cout<<"finish mountain\n";
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		e[i].from=t1,e[i].to=t2,e[i].w=t3;
	}
	sort(e+1,e+m+1,cmpe);
//	cout<<"finish edge\n";
	for(i=1;i<=Q;i++){
		t1=read();t2=read();t3=read();
		q[i].st=t1;q[i].lim=t2;q[i].k=t3;q[i].num=i;
	}
	sort(q+1,q+Q+1,cmp1);j=0;
//	cout<<"finish query\n";
	
	for(i=1;i<=Q;i++){
		while(e[j+1].w<=q[i].lim&&j<m){
			fx=find(e[j+1].from);fy=find(e[j+1].to);
			if(fx==fy) goto jump;
			merge(fx,fy);
			jump:
			j++;
//			if(j%1000==0) cout<<j<<'\n';
		}
//		cout<<"do "<<i<<' '<<j<<'\n';
		q[i].ans=ask(root[find(q[i].st)],q[i].k);
	}
	sort(q+1,q+Q+1,cmp2);
	
	for(i=1;i<=Q;i++){
		if(q[i].ans==-1) puts("-1");
		else printf("%d\n",q[i].ans);
	}
}
