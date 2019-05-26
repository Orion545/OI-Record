#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int n,cnte,first[1010];
struct edge{
	int to,next;
}a[2010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int son[1010],siz[1010],sum,root,vis[1010],fa[1010];
void getroot(int u,int f){
	int i,v;siz[u]=1;son[u]=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		getroot(v,u);
		siz[u]+=siz[v];
		son[u]=max(son[u],siz[v]);
	}
	son[u]=max(son[u],sum-siz[u]);
	if(son[u]<son[root]||(son[u]==son[root]&&u<root)) root=u;
}
void dfs(int u,int cursum){
	int i,v;vis[u]=1;
//	cout<<"dfs "<<u<<' '<<fa[u]<<' '<<cursum<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		sum=((siz[v]>siz[u])?cursum-siz[u]:siz[v]);
		root=0;son[0]=sum;
		getroot(v,0);
		fa[root]=u;dfs(root,sum);
	}
}
int ans[2010];
int main(){
	freopen("in.in","w",stdout);
	srand(time(NULL));
	int T=100,i,j,t1,t2;
	n=100;
	printf("%d %d\n",T,n);
	for(j=1;j<=T;j++){
		memset(first,-1,sizeof(first));
		cnte=0;
		memset(vis,0,sizeof(vis));
		memset(fa,0,sizeof(fa));
		memset(a,0,sizeof(a));
		int flag=random(0,1);ans[j]=flag;
		for(i=2;i<=n;i++){
			t1=i;t2=random(1,i-1);
			if(flag==0) printf("%d %d\n",t1,t2);
			add(t1,t2);
		}
		sum=n;son[0]=n;root=0;
		getroot(1,0);int rr=root;
		dfs(root,n);
		if(flag==1){
			for(i=1;i<=n;i++) if(i!=rr) printf("%d %d\n",fa[i],i);
		}
	}
	freopen("std.out","w",stdout);
	for(i=1;i<=T;i++){
		if(ans[i]) puts("Yes");
		else puts("No");
	}
}

