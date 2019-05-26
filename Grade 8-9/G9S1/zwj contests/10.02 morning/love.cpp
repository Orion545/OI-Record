#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
struct ed{
	int k,w,next;
}e[200005];
struct edge{
	int x,y,w;
}E[200005];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int n,m,fa[100005];
int find(int *fa,int k){
	if(fa[k]!=k) fa[k]=find(fa,fa[k]);
	return fa[k];
}
int find1(int *fa,int k){
	while(fa[k]!=k) k=fa[k];
	return k;
}
int R,cnt,pos[100005],val;
void dfs(int k,int w){
	if(k==R){
		if(w==val)cnt++;
		return;
	}
	dfs(k+1,w);
	int x=find(pos,E[k].x);
	int y=find(pos,E[k].y);
	if(find(pos,x)!=find(pos,y)){
		pos[x]=y;
		dfs(k+1,w+1);
		pos[x]=x;
	}
}
int main(){
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&E[i].x,&E[i].y,&E[i].w);
	sort(E+1,E+m+1,cmp);
	ll ans=0,sum=1;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,p;i<=m;i=p){
		val=0;
		for(p=i;p<=m&&E[p].w==E[i].w;p++){
			E[p].x=find(fa,E[p].x),E[p].y=find(fa,E[p].y);
			pos[E[p].x]=find(fa,E[p].x);
			pos[E[p].y]=find(fa,E[p].y);
		}
		for(int j=i;j<p;j++){
			int x=find(fa,E[j].x),y=find(fa,E[j].y);
			if(x!=y){
				ans+=E[j].w;
				val++;
				fa[x]=y;
			}
		}
		R=p;cnt=0;
		dfs(i,0);
		sum=sum*ll(cnt)%mod;
	}
	printf("%lld %lld",ans,sum);
	return 0;
}
