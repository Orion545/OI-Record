#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
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
namespace sam{
	int ch[4000010][10],fa[4000010],val[4000010],book[4000010],lis[4000010],root,cnt=1,last;
	void init(){root=cnt=1;val[1]=0;}
	inline int newnode(int w){val[++cnt]=w;return cnt;}
	int insert(int c,int last){
		int p=last,np=newnode(val[p]+1);
//		cout<<"insert "<<c<<' '<<p<<' '<<np<<' '<<val[np]<<'\n';
		for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
		if(!p) fa[np]=root;
		else{
			int q=ch[p][c];
			if(val[q]==val[p]+1) fa[np]=q;
			else{
				int nq=newnode(val[p]+1);
				memcpy(ch[nq],ch[q],sizeof(ch[q]));
				fa[nq]=fa[q];
				fa[q]=fa[np]=nq;
				for(;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
			}
		}
		return np;
	}
	ll getans(){
		ll re=0,i;
		for(i=2;i<=cnt;i++) re+=val[i]-val[fa[i]];
		return re;
	}
}
namespace graph{
	int n,m,first[100010],cnte=-1,c[100010],vis[100010],in[100010];
	struct edge{
		int to,next;
	}a[200010];
	inline void add(int u,int v){
		a[++cnte]=(edge){u,first[v]};first[v]=cnte;
		a[++cnte]=(edge){v,first[u]};first[u]=cnte;
		in[u]++;in[v]++;
	}
	queue<int>q;
	void bfs(int s){
		int i,u,v;
		memset(vis,0,sizeof(vis));
		q.push(s);
		vis[0]=1;
		vis[s]=sam::insert(c[s],1);
		while(!q.empty()){
			u=q.front();q.pop();
			for(i=first[u];~i;i=a[i].next){
				v=a[i].to;if(vis[v]) continue;
				vis[v]=sam::insert(c[v],vis[u]);
				q.push(v);
			}
		}
	}
}
using namespace sam;
using namespace graph;
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2;
	init();
	for(i=1;i<=n;i++) c[i]=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	for(i=1;i<=n;i++){
		if(in[i]==1) bfs(i);
	}
	printf("%lld\n",getans());
}
