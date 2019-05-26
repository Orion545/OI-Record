#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=5e4;
const int INF=1e9;
int n,m;
int dis[60][60];
struct edge
{
	int u,v,w;
}g[N+10];
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
bool judge(int len)
{
	int ans=0,sum=0;
	for(int i=1;i<n;i++)
	{
		if(sum+g[i].w>=len) ans++,sum=0;
		else sum+=g[i].w;
	}
	if(ans<m) return 0;
	return 1;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=50&&m==1)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j) dis[i][j]=INF;
		for(int i=1,a,b,l;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&l);
			dis[a][b]=dis[b][a]=l;
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++) ans=max(ans,dis[i][j]);
		printf("%d",ans);
		return 0;
	}
	bool flag=1,flag2=1;int minx=INF;
	for(int i=1,a,b,l;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&l);
		g[i].u=a,g[i].v=b,g[i].w=l;
		if(a!=1) flag=0;
		minx=min(minx,l);
		if(b!=a+1) flag2=0;
	}
	if(m==n-1){printf("%d",minx); return 0;}
	if(flag)
	{
		sort(g+1,g+n,cmp);
		int ans=INF;n--;
		m<<=1;
		while(m>n) ans=min(ans,g[n--].w),m-=2;
		for(int i=n-m+1;i<=n;i++) ans=min(ans,g[i].w+g[(n<<1)-m-i+1].w);
		printf("%d",ans);
		return 0;
	}
	if(flag2)
	{
		int left=minx,right=INF;
		while(right-left>1)
		{
			int mid=(left+right)>>1;
			if(judge(mid)) left=mid;
			else right=mid-1;
		}
		int m1=max(right,left),m2=min(right,left);
		if(judge(m1)) printf("%d",m1);
		else printf("%d",m2);
		return 0;
	}
	return 0;
}
