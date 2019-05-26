#include<cstdio>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
inline ll rd(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
	return f*x;
} 
const ll maxn=5e4,maxm=5e4;
ll N,num_edge=0,edge_head[maxn+50],u,v,max_dep,num,Dep[maxn+50];
ll w,M,x,A[maxm+50],l,r,sum=0;
bool flag2;
struct Edge{
	ll to,nx;
	ll dis;
}edge[(maxm<<1)+50];
inline void Add_edge(ll from,ll to,ll dis){
	edge[++num_edge].nx=edge_head[from];
	edge[num_edge].to=to;
	edge[num_edge].dis=dis;
	edge_head[from]=num_edge;
	return;
}

inline void Dfs(int x,int fa){
	if(Dep[x]>max_dep){
		max_dep=Dep[x];
		num=x;
	}
	for(int i=edge_head[x];i;i=edge[i].nx){
		int y=edge[i].to;
		if(y!=fa){
			Dep[y]=Dep[x]+edge[i].dis;
			Dfs(y,x);
		}
	}
	return;
}

inline void Dfs2(int x,int fa){
	for(int i=edge_head[x];i;i=edge[i].nx){
		int y=edge[i].to;
		if(y!=fa){
			A[++num]=edge[i].dis;
			Dfs2(y,x);
		}
	}
	return;
}

inline bool Check2(int x){
	ll tim=0,last=0;
	for(int i=1;i<=num;i++){
		if(last+A[i]<x){
			last+=A[i];
		}
		else{
			last=0;
			tim++;
		}
	}
	if(tim>=M)return 1;
	return 0;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	flag2=1;
	N=rd();M=rd();
	for(int i=1;i<N;i++){
		u=rd();v=rd();w=rd();
		if(v!=u+1&&v+1!=u)flag2=0;
		Add_edge(u,v,w);
		Add_edge(v,u,w);
		sum+=w;
	}
	
	//m==1
	if(M==1){
		max_dep=0;
		Dfs(1,0);
		max_dep=0;
		memset(Dep,0,sizeof(Dep));
		Dfs(num,0);
		cout<<max_dep;
		fclose(stdin);fclose(stdout);
		return 0;
	}
	
	//Á´ 
	if(flag2){
		num=0;
		Dfs2(1,0);
		l=0;r=sum;
		while(l<=r){
			int m=(l+r)>>1;
			if(Check2(m))l=m+1;
			else r=m-1;
		}
		cout<<r;
		fclose(stdin);fclose(stdout);
		return 0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
