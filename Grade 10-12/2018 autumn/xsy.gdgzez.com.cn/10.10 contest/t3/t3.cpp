#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
int n,cnte,first[1010];
struct edge{
	int to,next;
}a[2010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int son[1010],siz[1010],sum,root,rt;
void getroot(int u,int f){
	int i,v;siz[u]=1;son[u]=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		getroot(v,u);
		siz[u]+=siz[v];
		son[u]=max(son[u],siz[v]);
	}
	son[u]=max(son[u],sum-siz[u]);
	if(son[u]<son[root]) root=u,rt=0;
	else if(son[u]==son[root]) rt=u;
}
bool flag;
void dfs(int u,int f){
	int i,v;siz[u]=1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
		siz[u]+=siz[v];
		if(!flag) return;
	}
//	cout<<"finish dfs "<<u<<' '<<siz[u]<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		if(siz[v]*2>siz[u]){flag=0;return;}
	}
}
int main(){
	int T=read();n=read();
	int i,t1,t2;
	while(T--){
		memset(first,-1,sizeof(first));
		flag=1; 
		cnte=0;memset(a,0,sizeof(a));
		for(i=1;i<n;i++){
			t1=read();t2=read();
			add(t1,t2);
		}
		sum=n;root=0;son[0]=n;rt=0;
		flag=1;
		getroot(1,0);
		dfs(root,0);
		if(!flag){
			if(rt){
				flag=1;
				dfs(rt,0);
				if(!flag) puts("No");
				else puts("Yes");
			}
			else puts("No");
		}
		else puts("Yes");
	}
}

