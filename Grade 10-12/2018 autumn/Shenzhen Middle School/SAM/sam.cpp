#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n;char s[1000010];
namespace sam{
	int ch[2000010][26],fa[2000010],cnt,root,last,val[2000010],siz[2000010];
	void init(){
		root=cnt=last=1;
		val[root]=0;
	}
	int newnode(int w){val[++cnt]=w;return cnt;}
	void insert(int c){
		int p=last,np=newnode(val[p]+1);
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
		last=np;siz[np]=1;
	}
	int first[2000010],cnte=-1;ll ans=0;
	struct edge{
		int to,next;
	}a[2000010];
	inline void add(int u,int v){
//		cout<<"add "<<u<<' '<<v<<'\n';
		a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	}
	void dfs(int u){
		int i,v;
//		cout<<"dfs "<<u<<' '<<val[u]<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
			dfs(v);
			siz[u]+=siz[v];
		}
		if(siz[u]>1) ans=max(ans,1ll*siz[u]*val[u]);
	}
	ll solve(){
		memset(first,-1,sizeof(first));
		for(int i=2;i<=cnt;i++) add(fa[i],i);
		dfs(1);
		return ans;
	}
}
int main(){
	scanf("%s",s);n=strlen(s);int i;
	sam::init();
	for(i=0;i<n;i++) sam::insert(s[i]-'a');
	cout<<sam::solve()<<'\n';
}
