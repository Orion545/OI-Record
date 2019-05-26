#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct edge{
	int data,next;
}a[100010];
int n,mm;
int dep[100010],first[100010],tt[100010];
int father[100010][20];
bool vis[100010];
int ft[100010];
void dfs(int k){
	int d=dep[k],p=first[k];vis[k]=1;
	while(p!=-1){
		int v=a[p].data;
		if(!vis[v]){
			dep[v]=d+1;dfs(v);
		}
		p=a[p].next;
	}
}
void add(){
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++){
			father[i][j]=father[father[i][j-1]][j-1];
		}
	}
	for(int i=1;i<=n;i++) father[i][0]=ft[i];
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	int dc=dep[u]-dep[v];
	for(int i=0;i<=20;i++){
		if(dc&(1<<i)) u=father[u][i];
	} 
	if(u==v) return u;
	for(int i=19;i>=0;i--){
		if(father[u][i]!=father[v][i]){
			u=father[u][i];v=father[v][i];
		}
	}
	u=father[u][0];
	return u;
}
int main(){
	memset(father,0,sizeof(father));memset(first,-1,sizeof(first));memset(tt,-1,sizeof(tt));
	cin>>n;
	int xx,t;
	for(int i=1;i<n;i++){
		cin>>xx>>t;
		a[i].data=t;a[i].next=tt[xx];
		first[xx]=tt[xx]=i;
		father[t][0]=ft[t]=xx;
	}
	dep[1]=1;dfs(1);add();cout<<endl;
	while(cout<<"Input data: "&&cin>>xx>>t){
		cout<<lca(xx,t)<<endl<<endl;
	}
}
