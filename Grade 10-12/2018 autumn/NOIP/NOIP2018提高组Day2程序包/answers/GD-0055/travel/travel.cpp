#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct map
{
	int x;
	int y;
	int ret;
};
map way[10001];
int first[5001],next[10001],bz[5001],huan[10001],ans[5001],a[5001],d[5001][2],use[10001],n,m,tot,s,t,tf=1;
int dfs(int z)
{
	int i;
	bz[z]=tot;
	s++;a[s]=z;
	i=first[z];
	while(i>=1&&i<=m)
	{
		if(huan[way[i].ret]!=2&&bz[way[i].y]!=tot)dfs(way[i].y);
		i=next[i];
	}
}
int find(int z)
{
	int i;
	if(tf==0)return 0;//printf("%d\n",z);
	bz[z]=tot;
	t++;d[t][0]=z;
	i=first[z];
	while(i>=1&&i<=m)
	{
		if(use[way[i].ret]==0)
		{//printf("*%d*\n",way[i].y);
			use[way[i].ret]=1;
			//if(i<=m/2)way[i+m/2].use=1;
			//else way[i-m/2].use=1;
			if(bz[way[i].y]==tot)
			{
				tf=0;
				huan[way[i].ret]=1;
				//if(i<=m/2)huan[i]=1;
				//else huan[i-m/2]=1;
				while(t>=1&&d[t][0]!=way[i].y)
				{
					huan[way[d[t][1]].ret]=1;
					//if(d[t][1]<=m/2)huan[d[t][1]]=1;
					//else huan[d[t][1]-m/2]=1;
					t--;
				}
				return 0;
			}
			d[t+1][1]=i;
			find(way[i].y);
		}
		i=next[i];
	}
	t--;
}
int small()
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(a[i]<ans[i])return 100;
		if(a[i]>ans[i])return 50;
	}
	return 50;
}
int game(const map &a,const map &b)
{
	if(a.y<b.y)return 1;
	else return 0;
}
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int i,j;
scanf("%d %d",&n,&m);
for(i=1;i<=m;i++)
{
	scanf("%d %d",&way[i].x,&way[i].y);way[i].ret=i;
	way[i+m].x=way[i].y;way[i+m].y=way[i].x;way[i+m].ret=i;
}
m*=2;
sort(way+1,way+m+1,game);
for(i=m;i>=1;i--)next[i]=first[way[i].x],first[way[i].x]=i;
if(m/2==n-1)
{
	tot++;s=0;dfs(1);
	for(i=1;i<=n;i++)ans[i]=a[i];
}
else
{
	tot++;find(1);
	//for(i=1;i<=m;i++)printf("%d %d %d\n",way[i].x,way[i].y,huan[way[i].ret]);
	memset(ans,0x7f,sizeof(ans));
	for(i=1;i<=m;i++)
		if(huan[way[i].ret]==1)
		{
			huan[way[i].ret]=2;//huan[i+m/2]=2;
			tot++;s=0;dfs(1);
			huan[way[i].ret]=0;//huan[i+m/2]=1;
			if(small()==100)
				for(j=1;j<=n;j++)ans[j]=a[j];
		}
}
for(i=1;i<=n;i++)printf("%d ",ans[i]);
return 0;
}
