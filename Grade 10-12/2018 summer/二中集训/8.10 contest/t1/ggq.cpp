#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 2200000 
using namespace std;
int h[N],v[N],Next[N],q[N];
int g[2200][2200],a[2200],tot,p[2200],n,du[2200],tail;
int gcd(int x,int y){
	if(x%y==0)return y;
	return gcd(y,x%y);
}
int add(int x,int y){
	tot++;
	Next[tot]=h[x];
	v[tot]=y;
	h[x]=tot;
}
int dfs(int x){
	p[x]=1;
	for(int i=1;i<=n;i++){
		if(p[i]==0&&g[x][i]){
			dfs(i);
			add(x,i);du[i]++;
		//	printf("%d %d\n",x,i); 
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(gcd(a[i],a[j])!=1)g[i][j]++; 
		}
	}
	for(int i=1;i<=n;i++)if(p[i]==0)dfs(i);
	for(int i=1;i<=n;i++)if(du[i]==0)q[++tail]=i;
	for(int i=1;i<=n;i++){
		int o=0;
		for(int j=1;j<=tail;j++)if(a[q[j]]>a[q[o]])o=j;
		for(int j=h[q[o]];j;j=Next[j]){
			du[v[j]]--;
			if(du[v[j]]==0)q[++tail]=v[j];
		}
		printf("%d ",a[q[o]]);
		q[o]=0;
	}
} 

