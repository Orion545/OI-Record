#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge{
	int to,next;
}a[200100];
int n,m,q,first[30010],ans=0;
bool clo[30010];
void dfs(int k){
	int i,v;
	clo[k]=1;ans++;
	for(i=first[k];~i;i=a[i].next){
		v=a[i].to;
		if(!clo[v]){
			dfs(v);
		}
	}
}
int main(){
	freopen("damage.in","r",stdin);
	freopen("damage.out","w",stdout);
	memset(first,-1,sizeof(first));
	int i,j,t1,t2;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=m;i++){
		scanf("%d%d",&t1,&t2);
		a[i*2-1].to=t2;a[i*2-1].next=first[t1];first[t1]=i*2-1;
		a[i*2].to=t1;a[i*2].next=first[t2];first[t2]=i*2;
	}
	for(i=1;i<=q;i++){
		scanf("%d",&t1);
		for(j=first[t1];~j;j=a[j].next){
			t2=a[j].to;clo[t2]=1;
		}
	}
	dfs(1);
	printf("%d",n-ans);
} 
