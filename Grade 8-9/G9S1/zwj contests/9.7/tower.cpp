#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge{
	int to,next;
}a[20010];
int n,first[10010],ans;
bool vis[10010];
void dfs(int k,int fa){
	int i,flag=0;
	for(i=first[k];~i;i=a[i].next){
		if(a[i].to!=fa){
			dfs(a[i].to,k);
			if(vis[a[i].to]) flag=1;
		}
	}
	if(!flag&&!vis[k]&&!vis[fa]){
		vis[fa]=1;ans++;
	}
}
int main(){
	int i,t1,t2;
	memset(first,-1,sizeof(first));
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&t1,&t2);
		a[i].to=t2;a[i].next=first[t1];first[t1]=i;
		a[i+n-1].to=t1;a[i+n-1].next=first[t2];first[t2]=i+n-1;
	}
	dfs(1,0);
	printf("%d",ans);
} 
