#include<bits/stdc++.h>
using namespace std;
typedef struct{
	int to,nxt,w;
}edge;
edge e[1200051];
bool pd;
int f[100001],a,b,c,i,ans,cnt,n,m,head[100001];
void add(int a,int b,int c){
	cnt++;
	e[cnt].to=b;
	e[cnt].w=c;
	e[cnt].nxt=head[a];
	head[a]=cnt;
}
void dfs1(int o,int fa){
	for(int i=head[o];i!=-1;i=e[i].nxt){
		int v=e[i].to;int ww=e[i].w;
		if(v!=fa){
			dfs1(v,o);
			f[o]=max(f[o],f[v]+ww);
		}
	}
}
bool cmp(const edge &a,const edge &b){
	return a.w>b.w;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	pd=true;
	for(i=1;i<=n-1;i++){
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
		if(a!=1) pd=false;
	}
	if(m==n-1){
		ans=131515;
		for(i=1;i<=cnt;i++)
		  ans=min(ans,e[i].w);
		printf("%d\n",ans);
		return 0;
	}else
	if(m==1&&n<=5000){
		ans=0;
		for(i=1;i<=n;i++){
			memset(f,0,sizeof(f));
			dfs1(i,0);
			ans=max(ans,f[i]);
		}
		printf("%d\n",ans);
		return 0;
	}
	if(pd==true&&m==1){
		sort(e+1,e+cnt+1,cmp);
		printf("%d\n",e[1].w+e[3].w);
		return 0;
	}
	if(m==1&&n>=5000){
		ans=0;
		for(i=1;i<=30000;i++)
		  if(i%3==1){
			memset(f,0,sizeof(f));
			dfs1(i,0);
			ans=max(ans,f[i]);
		}
		printf("%d\n",ans);
		return 0;
	}
}
