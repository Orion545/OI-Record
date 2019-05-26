#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 2147483646
using namespace std;
struct data{
	int a,b,id;
}w[5005];
bool cmp(data x,data y){
	if(x.a!=y.a) return x.a<y.a;
	return x.b<y.b;
}
int n,m,a,b,vis[5005],nod,x[5005],v[5005],ans[5005];
vector<int>edge[5005],id[5005];
void dfs(int o,int t){
	v[++nod]=o;
	int sz=edge[o].size(),p=0;
	for(int i=0;i<sz;i++)
		if(vis[edge[o][i]]!=t&&id[o][i]!=t){
			x[p++]=edge[o][i],vis[edge[o][i]]=t;
			dfs(edge[o][i],t);
		}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&w[i].a,&w[i].b);
		w[i].id=i;
		if(w[i].a>w[i].b) swap(w[i].a,w[i].b);
	}
	sort(w+1,w+1+m,cmp);
	for(int i=1;i<=m;i++){
		edge[w[i].a].push_back(w[i].b);
		edge[w[i].b].push_back(w[i].a);
		id[w[i].a].push_back(w[i].id);
		id[w[i].b].push_back(w[i].id);
	}
	for(int i=1;i<=n;i++) ans[i]=INF;
	if(m==n-1){
		vis[1]=m+2;
		dfs(1,m+2);
		for(int i=1;i<=n;i++){
			printf("%d ",v[i]);
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		vis[1]=i;nod=0;
		dfs(1,i);
		if(nod==n)
			for(int j=1;j<=n;j++){
				if(ans[j]>v[j]){
					for(int k=1;k<=n;k++)
						ans[k]=v[k];
					break;			
				}
				if(ans[j]<v[j]) break;
			}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}
