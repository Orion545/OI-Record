#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define ll long long
#define maxn 5010
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
struct edge{
	int to,nxt;
}e[2*maxn];
struct data{
	int x,y;
}a[2*maxn];
int fir[maxn],vis[maxn],inc[maxn];
int ans[maxn],anss[maxn][maxn],mark[maxn];
int n,m,tot,rt;
bool cmp(data a,data b){return a.x==b.x?a.y>b.y:a.x<b.x;}
void add_edge(int x,int y){e[tot].to=y; e[tot].nxt=fir[x]; fir[x]=tot++;}
void dfs1(int now)
{
	vis[now]=1; ans[++tot]=now;
	for(int i=fir[now];~i;i=e[i].nxt)
		if(!vis[e[i].to])dfs1(e[i].to);
}
void dfs2(int now,int fa)
{
	vis[now]=1; inc[now]=0;
	for(int i=fir[now];~i;i=e[i].nxt)
		if(e[i].to!=fa){
			if(!vis[e[i].to])dfs2(e[i].to,now);
			else if(!rt)rt=e[i].to,inc[now]=1;
			if(e[i].to!=rt)inc[now]|=inc[e[i].to];
		}
//	printf("**** %d %d %d\n",now,fa,rt);
}
void dfs3(int now,int fa,int x,int y,int id)
{
//	system("pause");
//	printf("%d %d %d %d\n",now,x,y,id,fa);
	anss[id][++tot]=now;
	for(int i=fir[now];~i;i=e[i].nxt)
		if(e[i].to!=fa&&((now!=x||e[i].to!=y)&&(now!=y||e[i].to!=x)))dfs3(e[i].to,now,x,y,id);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=m;i++){
		a[i].x=read(); a[i].y=read();
		a[i+m].x=a[i].y; a[i+m].y=a[i].x;
	}
	std::sort(a+1,a+2*m+1,cmp);
//	for(int i=1;i<=2*m;i++)
//		printf("**** %d %d %d\n",i,a[i].x,a[i].y);
	memset(fir,255,sizeof(fir)); tot=0;
	for(int i=1;i<=2*m;i++)
		add_edge(a[i].x,a[i].y);
	if(m==n-1){
		memset(vis,0,sizeof(vis));
		tot=0; dfs1(1);
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	else{
		memset(vis,0,sizeof(vis));
		rt=0; dfs2(1,-1);
//		for(int i=1;i<=n;i++)
//			printf("%d %d\n",i,inc[i]);
//		printf("%d\n",rt);
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(inc[i]){
				for(int j=fir[i];~j;j=e[j].nxt)
					if(e[j].to>i&&inc[e[j].to])tot=0,dfs3(1,-1,i,e[j].to,++cnt);
			}
//		for(int i=1;i<=cnt;i++){
//			for(int j=1;j<=n;j++)
//				printf("%d ",anss[i][j]);
//			printf("\n");
//		}
		memset(mark,0,sizeof(mark));
		for(int i=1;i<=n;i++){
			int mn=0x3f3f3f3f;
			for(int j=1;j<=cnt;j++)
				if(!mark[j])mn=std::min(mn,anss[j][i]);
			for(int j=1;j<=cnt;j++)
				if(anss[j][i]>mn)mark[j]=1;
		}
		for(int i=1;i<=cnt;i++)
			if(!mark[i]){
				for(int j=1;j<=n;j++)
					printf("%d ",anss[i][j]);
				printf("\n");
				break;
			}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
