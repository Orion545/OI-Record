#include<iostream>
#include<cstdio>
const int N=50005;
int head[N],a,b,c,n,m,cnt,maxn,maxv,cntt;
long long ans;
struct edge{
	int to,nxt,w;
}e[N<<1];
void add(int a,int b,int c){
	e[++cnt].to=b;
	e[cnt].nxt=head[a];
	e[cnt].w=c;
	head[a]=cnt;
}
long long dfs(int u,int f){
	maxn=maxv=cntt=0;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v!=f){
			for(int j=head[u];j;j=e[j].nxt){
				int vv=e[j].to;
				if(vv==f||vv==v)continue;
				if(maxn<dfs(v,u)+dfs(vv,u)+e[j].w+e[i].w){
					maxn=dfs(v,u)+dfs(vv,u)+e[j].w+e[i].w;
				}
			}
		}
	}
	return maxn;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	e[0].w=0;
	ans=dfs(1,0);
	printf("%lld",ans);
	return 0;
}
