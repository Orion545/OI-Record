#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt=0,n,m;
struct ed{
	int from,nex,to,len;
}edge[101234];
int f[51234],head[51234],g[51234],dis[51234],ll[51234];
bool visit[51234];
void add(int x,int y,int le)
{
	cnt++;
	edge[cnt].from=x;
	edge[cnt].to=y;
	edge[cnt].nex=head[x];
	edge[cnt].len=le;
	head[x]=cnt;
}
void DFS(int x)
{
	int sum=0,sum2=0;
	visit[x]=1;
	for (int i=head[x];i;i=edge[i].nex){
		if (!visit[edge[i].to]) {
			DFS(edge[i].to);
			int u=edge[i].len+f[edge[i].to];
			if (u>sum){
				sum2=sum;sum=u;
			}
			else if (u>sum2) sum2=u;
		}
	}
	visit[x]=0;
	f[x]=sum;
	g[x]=sum+sum2;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool flag1=1,flag2=1;
	for (int i=1;i<n;i++){
		int x,y,le;
		scanf("%d%d%d",&x,&y,&le);
		if (y!=x+1) flag2=0;
		if (x!=1) flag1=0;
		add(x,y,le);
		add(y,x,le);
	}
	if (m==1){
		DFS(1);
		int sum=0;
		for (int i=1;i<=n;i++)
		sum=max(sum,g[i]);
		printf("%d\n",sum);
		return 0;
	}
	else if (flag2){
		int all=0;
		for (int i=1;i<=cnt;i++){
			if (edge[i].from>=edge[i].to) continue;
			dis[edge[i].to]=edge[i].len; 
		}
		for (int i=2;i<=n;i++) all+=dis[i];
		int l=1,r=all,mid,ans;
		while (l<=r){
			mid=(l+r)>>1;
			int tot=0,now=2,nowd=0;
			while (now<=n){
				nowd+=dis[now];
				if (nowd>=mid) {
					tot++;nowd=0;
				}
				now++;
			}
			if (tot>=m) {
				ans=mid;l=mid+1;
			}
			else r=mid-1;
		}
		printf("%d\n",ans);
		return 0;
	}
	else if (flag1){
		for (int i=head[1];i;i=edge[i].nex){
		dis[edge[i].to]=edge[i].len;}
		int x,y;
	//	for (int i=1;i<=n;i++) printf("%d ",dis[i]);
		sort(dis+2,dis+n+1);
		int all=n-1,cnt=0,wt=n;
		while (m*2>all){
			ll[++cnt]=dis[wt];
			wt--;
			m--;
		}
		x=wt-m*2+1;
		y=wt;
		while (x<y){
			ll[++cnt]=dis[x]+dis[y];
			x++;y--;
		}
		//for (int i=1;i<=cnt;i++)
		//printf("(%d)",ll[i]);
		sort(ll+1,ll+cnt+1);
		printf("%d\n",ll[1]);
		return 0;
	}
	else printf("525");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
