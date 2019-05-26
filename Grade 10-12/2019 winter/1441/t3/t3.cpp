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
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,first[6000010],cnte=-1;
struct edge{
	int to,next,from;
}a[20000010];
inline void add(int u,int v){
//	cout<<"add "<<u<<' '<<v<<'\n';
	a[++cnte]=(edge){v,first[u],u};first[u]=cnte;
}
int dfn[6000010],low[6000010],s[6000010],ins[6000010],clk,top;
vector<int>bcc[6000010];int belong[6000010],cntb;
void tarjan(int u){
	int i,v;
	dfn[u]=low[u]=++clk;
	s[++top]=u;ins[u]=1;
//	cout<<"tarjan "<<u<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		cntb++;
//		cout<<"find bcc "<<cntb<<'\n';
		do{
			v=s[top--];
			bcc[cntb].push_back(v);
			belong[v]=cntb;
			ins[v]=0;
//			cout<<"	ele "<<v<<'\n';
		}while(v!=u);
	}
}
int cntn,r1[100010],r2[100010],r3[100010];
struct seg{
	int ch[2000010][2];
	void insert(int &cur,int pre,int l,int r,int pos,int node){
		cur=++cntn;
		ch[cur][0]=ch[pre][0],ch[cur][1]=ch[pre][1];
//		cout<<"insert "<<cur<<' '<<pre<<' '<<l<<' '<<r<<' '<<pos<<' '<<node<<'\n';
		if(l==r){add(cur,node);return;}
		int mid=(l+r)>>1;
		if(mid>=pos) insert(ch[cur][0],ch[pre][0],l,mid,pos,node);
		else insert(ch[cur][1],ch[pre][1],mid+1,r,pos,node);
		if(ch[cur][0]) add(cur,ch[cur][0]);
		if(ch[cur][1]) add(cur,ch[cur][1]);
	}
	void query(int cur,int l,int r,int ql,int qr,int node){
//		cout<<"query "<<cur<<' '<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<node<<'\n';
		if(l>=ql&&r<=qr){
			if(cur)add(node,cur);
			return;
		}
		int mid=(l+r)>>1;
		if(mid>=ql) query(ch[cur][0],l,mid,ql,qr,node);
		if(mid<qr) query(ch[cur][1],mid+1,r,ql,qr,node);
	}
}s1,s2,s3;
struct node{
	int x,y,z,num;
	inline void input(int ii){
		x=read();y=read();z=read();num=ii;
	}
}x[100010];
inline bool cmp1(node l,node r){return l.x<r.x;}
inline bool cmp2(node l,node r){return l.y<r.y;}
inline bool cmp3(node l,node r){return l.z<r.z;}
int in[6000010],ans[100010];
int main(){
	memset(first,-1,sizeof(first));
	n=read();int i,j;
	cntn=n;
	for(i=1;i<=n;i++) x[i].input(i);
//	cout<<"***************************do s1\n";
	sort(x+1,x+n+1,cmp1);
	for(i=1;i<=n;i++){
		s1.query(r1[i-1],1,n,1,x[i].y,x[i].num);
		s1.insert(r1[i],r1[i-1],1,n,x[i].y,x[i].num);
	}
//	cout<<"***************************do s2\n";
	sort(x+1,x+n+1,cmp2);
	for(i=1;i<=n;i++){
		s2.query(r2[i-1],1,n,1,x[i].z,x[i].num);
		s2.insert(r2[i],r2[i-1],1,n,x[i].z,x[i].num);
	}
//	cout<<"***************************do s3\n";
	sort(x+1,x+n+1,cmp3);
	for(i=1;i<=n;i++){
		s3.query(r3[i-1],1,n,1,x[i].x,x[i].num);
		s3.insert(r3[i],r3[i-1],1,n,x[i].x,x[i].num);
	}
	for(i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(i=0;i<=cnte;i++){
		if(belong[a[i].from]&&belong[a[i].to]&&belong[a[i].from]!=belong[a[i].to]) in[belong[a[i].to]]++;
	}
	for(i=1;i<=cntb;i++){
//		cout<<"bcc No. "<<i<<' '<<bcc[i].size()<<' '<<in[i]<<'\n';
		if(in[i]) continue;
		for(j=0;j<bcc[i].size();j++) if(bcc[i][j]<=n) ans[bcc[i][j]]=1;
	}
	for(i=1;i<=n;i++) printf("%d\n",ans[i]);
}
