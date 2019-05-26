#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define next FUCK_THIS_CONTEST
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
int n,first[5010],cnte,to[10010],next[10010],fa[5010],st[5010][20],dep[5010];
inline void add(int u,int v){
	++cnte;to[cnte]=v;next[cnte]=first[u];first[u]=cnte;
	++cnte;to[cnte]=u;next[cnte]=first[v];first[v]=cnte;
}
void dfs(int u,int f){
	int i,v;fa[u]=f;st[u][0]=f;
//	cout<<"dfs "<<u<<' '<<f<<'\n';
	for(i=first[u];~i;i=next[i]){
		v=to[i];if(v==f) continue;
		dfs(v,u);
	}
} 
void ST(){
	int i,j;
	for(j=1;j<=16;j++){
		for(i=1;i<=n;i++){
			st[i][j]=st[st[i][j-1]][j-1];
		}
	}
}
int lca(int l,int r){
	int i;
	if(dep[l]>dep[r]) swap(l,r);
	for(i=16;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
	if(l==r) return l;
	for(i=16;i>=0;i--){
		if(st[r][i]!=st[l][i]){
			l=st[l][i];
			r=st[r][i];
		}
	}
	return fa[l];
};
int s[5010],top;bool vis[5010];
struct tree{
	int w[5010];
	void c1(int u){
		int i,v;w[u]=0;
		for(i=first[u];~i;i=next[i]){
			v=to[i];if(v==fa[u]) continue;
			c1(v);
		}
	}
	void c2(int u,int p){
		int i,v;if(u==p) return;
		w[u]=0;
		for(i=first[u];~i;i=next[i]){
			v=to[i];if(v==fa[u]||v==p) continue;
			c2(v,p);
		}
	}
	void c3(int u,int v){
		int p=lca(u,v),tmp;
		tmp=u;
		while(tmp!=p) w[tmp]=0,tmp=fa[tmp];
		tmp=v;
		while(tmp!=p) w[tmp]=0,tmp=fa[tmp];
		w[p]=0;
	}
	void cc4(int u){
		int i,v;if(vis[u]) return;
		w[u]=0;
		for(i=first[u];~i;i=next[i]){
			v=to[i];if(vis[v]||v==fa[u]) continue;
			cc4(v);
		}
	}
	void c4(int u,int v){
		int p=lca(u,v),tmp;
		memset(vis,0,sizeof(vis));
		tmp=u;
		while(tmp!=p) vis[tmp]=1,tmp=fa[tmp];
		tmp=v;
		while(tmp!=p) vis[tmp]=1,tmp=fa[tmp];
		vis[p]=1;
		cc4(1);
	}
	void c5(int u,int v){
		int i;
		for(i=u;i<=v;i++) w[i]=0;
	}
	void c6(int u,int v){
		int i;
		for(i=1;i<u;i++) w[i]=0;
		for(i=v+1;i<=n;i++) w[i]=0;
	}
	int query(int k){
		top=0;int i,j;
		for(i=1;i<=n;i++) if(w[i]) s[++top]=i;
		int re=0;
		for(i=1;i<=top;i=j){
			re++;j=i;
			while(s[j]-s[i]<=k) j++;
		}
		return re;
	}
}T[10010];int cnt;
int main(){
	memset(first,-1,sizeof(first));cnt=1;
	int i,t1,t2,t3,t4;n=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	for(i=1;i<=n;i++) T[1].w[i]=1;
	dfs(1,0);ST();
	int q=read();
	while(q--){
		t4=read();
		if(t4==1){
			t1=read();
			cnt++;T[cnt]=T[t1];
		}
		if(t4==2){
			t1=read();t2=read();
			for(i=1;i<=n;i++) T[t1].w[i]|=T[t2].w[i];
		}
		if(t4==3){
			t1=read();t2=read();
			T[t1].c1(t2);
		}
		if(t4==4){
			t1=read();t2=read();
			T[t1].c2(1,t2);
		}
		if(t4==5){
			t1=read();t2=read();t3=read();
			T[t1].c3(t2,t3);
		}
		if(t4==6){
			t1=read();t2=read();t3=read();
			T[t1].c4(t2,t3);
		}
		if(t4==7){
			t1=read();t2=read();t3=read();
			T[t1].c5(t2,t3);
		}
		if(t4==8){
			t1=read();t2=read();t3=read();
			T[t1].c6(t2,t3);
		}
		if(t4==9){
			t1=read();t2=read();
			printf("%d\n",T[t1].query(t2));
		}
	}
}
/*
5
1 3
3 5
1 2
2 4
9
1 1
1 2
5 3 4 5
9 3 0
2 3 2
6 3 4 5
9 3 1
4 2 2
9 2 1

*/
