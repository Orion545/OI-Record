#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
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
int ch[4000010][2],seg[4000010],cnt;
void insert(int &cur,int pre,int l,int r,int pos){
	cur=++cnt;
//	cout<<"insert "<<cur<<' '<<pre<<' '<<l<<' '<<r<<' '<<pos<<'\n';
	seg[cur]=seg[pre]+1;ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];
	if(l==r) return;
	int mid=(l+r)>>1;
	if(mid>=pos) insert(ch[cur][0],ch[pre][0],l,mid,pos);
	if(mid<pos) insert(ch[cur][1],ch[pre][1],mid+1,r,pos);
}
int ql,qr;
int query(int l,int r,int u,int v,int f,int ff){
//	cout<<"query "<<l<<' '<<r<<' '<<u<<' '<<v<<' '<<f<<' '<<ff<<' '<<seg[u]+seg[v]-seg[f]-seg[ff]<<'\n';
	if(l>=ql&&r<=qr) return (seg[u]+seg[v]-seg[f]-seg[ff]);
	int mid=(l+r)>>1,re=0;
	if(mid>=ql) re+=query(l,mid,ch[u][0],ch[v][0],ch[f][0],ch[ff][0]);
	if(mid<qr) re+=query(mid+1,r,ch[u][1],ch[v][1],ch[f][1],ch[ff][1]);
	return re;
}
int n,m,first[200010],cnte,dep[200010],st[20][200010],root[200010],work[200010];
struct edge{
	int to,next;
}a[400010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs(int u,int f){
	int i,v;
	dep[u]=dep[f]+1;st[0][u]=f;
//	cout<<"dfs "<<u<<' '<<f<<' '<<dep[u]<<' '<<work[u]<<'\n';
	if(work[u]) insert(root[u],root[f],1,m,work[u]);
	else root[u]=root[f];
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
	}
}
void ST(){
	int i,j;
	for(j=1;j<=18;j++){
		for(i=1;i<=n;i++){
			st[j][i]=st[j-1][st[j-1][i]];
		}
	}
}
int lca(int l,int r){
	int i;
	if(dep[l]>dep[r]) swap(l,r);
	for(i=18;i>=0;i--) if(dep[st[i][r]]>=dep[l]) r=st[i][r];
	if(l==r) return l;
	for(i=18;i>=0;i--){
		if(st[i][l]!=st[i][r]){
			l=st[i][l];
			r=st[i][r];
		}
	}
	return st[0][l];
}
int cntq,qu[200010],qv[200010],qc[200010],qt[200010];
int main(){
	memset(first,-1,sizeof(first));
	n=read();int i,t1,t4,rt=0;
	for(i=1;i<=n;i++){
		t1=read();
		if(t1) add(t1,i);
		else rt=i;
	}
	m=read();
	for(i=1;i<=m;i++){
		t4=read();
		if(t4==2){
			t1=read();
			work[t1]=i;
		}
		else{
			cntq++;
			qu[cntq]=read();qv[cntq]=read();qc[cntq]=read();qt[cntq]=i;
		}
	}
	dfs(rt,0);ST();
	for(i=1;i<=cntq;i++){
		ql=1;qr=qt[i]-qc[i]-1;
		t1=lca(qu[i],qv[i]);
//		cout<<"checkq "<<ql<<' '<<qr<<' '<<qu[i]<<' '<<qv[i]<<' '<<t1<<' '<<st[0][t1]<<'\n';
		if(ql>qr) printf("%d 0\n",dep[qu[i]]+dep[qv[i]]-dep[t1]-dep[st[0][t1]]);
		else printf("%d %d\n",dep[qu[i]]+dep[qv[i]]-dep[t1]-dep[st[0][t1]],query(1,m,root[qu[i]],root[qv[i]],root[t1],root[st[0][t1]]));
	}
}
