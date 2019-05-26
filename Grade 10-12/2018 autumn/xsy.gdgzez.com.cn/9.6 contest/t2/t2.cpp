#include<iostream>
#include<cassert>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define id(i,j,k) num[i][j][k]
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
int n,m,d[110][110],r[110][110],num[110][110][10],first[50010],cnte=-1;
struct edge{
	int to,next,w;
}a[200010];
inline void add(int u,int v,int w){
	if(w<=10) w=10-w;
//	cout<<"	add "<<u<<' '<<v<<' '<<w<<'\n';	
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],0};first[v]=cnte;
}
int dep[50010],cur[50010],q[50010],head,tail;
bool bfs(int s,int t){
	int i,u,v;head=0,tail=1;
	for(i=s;i<=t;i++) dep[i]=-1,cur[i]=first[i];
	dep[s]=0;q[0]=s;
	while(head<tail){
		u=q[head++];
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(~dep[v]||!a[i].w) continue;
			dep[v]=dep[u]+1;q[tail++]=v;
		}
	}
	return ~dep[t];
}
int dfs(int u,int t,int lim){
//	cout<<"dfs "<<u<<' '<<t<<' '<<lim<<'\n';
	if(u==t||!lim) return lim;
	int i,v,f,flow=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
//		cout<<"	trying "<<v<<" from "<<u<<'\n';
		if(dep[v]==dep[u]+1&&(f=dfs(v,t,min(lim,a[i].w)))){
			a[i].w-=f;a[i^1].w+=f;
			flow+=f;lim-=f;
			if(!lim) return flow;
		}
	}
	return flow;
}
int dinic(int s,int t){
	int re=0;
	while(bfs(s,t)) re+=dfs(s,t,1e9);
	return re;
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,j,k,s=0,t=n*m*10+1;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) for(k=0;k<=9;k++) num[i][j][k]=k*n*m+((i-1)*m+j);
	for(i=1;i<n;i++) 
		for(j=1;j<=m;j++) 
			d[i][j]=read();
	for(i=1;i<=n;i++)
		for(j=1;j<m;j++)
			r[i][j]=read();
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
//			cout<<"ADDEDGE "<<i<<' '<<j<<'\n';
			if((i+j)%2){
				//9->0
				add(s,id(i,j,0),1e9);add(id(i,j,0),id(i,j,9),9);
				for(k=8;k>=1;k--) add(id(i,j,k+1),id(i,j,k),k);
				add(id(i,j,1),t,1e9);
				for(k=9;k>=1;k--){
					//limit from former nodes
					if((i>1)&&(d[i-1][j]-k<=9)) add(id(i-1,j,max(0,d[i-1][j]-k)),id(i,j,k),1e9);
					if((j>1)&&(r[i][j-1]-k<=9)) add(id(i,j-1,max(0,r[i][j-1]-k)),id(i,j,k),1e9);
					//limit to latter nodes
					if((i<n)&&(d[i][j]-k<=9)) add(id(i+1,j,max(0,d[i][j]-k)),id(i,j,k),1e9);
					if((j<m)&&(r[i][j]-k<=9)) add(id(i,j+1,max(0,r[i][j]-k)),id(i,j,k),1e9);
				}
			}
			else{
				add(s,id(i,j,0),1e9);
				for(k=1;k<=9;k++) add(id(i,j,k-1),id(i,j,k),k);
				add(id(i,j,9),t,1e9);
			}
		}
	}
	printf("%d\n",n*m*10-dinic(s,t));
 }
