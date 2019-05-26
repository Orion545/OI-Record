#include<cstdio> 
#include<algorithm>
#include<string.h>
#define N 110001
using namespace std;
int i,j,k,l,n,m,head,tail,p,q,mid,tot,ans,tov[N],len[N],next[N],last[N],dis[N],bz[N],dl[N];
struct ymq{int x;int y;int z;}a[N];
bool cmp1(ymq p,ymq q){return p.z<q.z;}
int check1(int mid)
{
	int i,j,k,l;
	j=m;
	for(i=n;i>=1;i--)
	{
		if(a[i].z>=mid){j--;continue;}
		k=i;
		break;
	}
	if(j<=0)return 0;
	for(i=1;i<=k-1;i++)if(a[i].z+a[k].z>=mid){l=i+1,j--,k--;break;}
	for(;k>l;k--)
	{
		while(a[l].z+a[k].z<mid&&l<k)l++;
		if(l<k)l++,j--;
	}
	if(j<=0)return 0;
	return 1;
}
bool cmp2(ymq p,ymq q){return p.x<q.x;}
int check2(int mid)
{
	int i,j,k,l;
	j=0,k=m;
	for(i=1;i<=n;i++)
	{
		j+=a[i].z;
		if(j>=mid)j=0,k--;		
	}
	if(k<=0)return 0;
	return 1;
}
void lian(int x,int y,int z){tot++,tov[tot]=y,len[tot]=z,next[tot]=last[x],last[x]=tot;}
void bfs(int x)
{
	memset(dis,0,sizeof dis);
	memset(bz,0,sizeof bz);
	int head=0,tail=1,y,i;
	dl[1]=x,bz[x]=1;
	while(head<tail)
	{
		head++;
		y=dl[head];
		for(i=last[y];i;i=next[i])
		{
			if(bz[tov[i]]==0)
			{
				bz[tov[i]]=1;
				dis[tov[i]]=dis[y]+len[i];
				tail++;
				dl[tail]=tov[i];
			}
		}
	}	
}
int main()
{
	freopen("track.in","r",stdin);freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);	
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		if(a[i].x==1)p++;
		if(a[i].x==a[i].y-1)q++;
		lian(a[i].x,a[i].y,a[i].z),lian(a[i].y,a[i].x,a[i].z);
	}
	if(p==n-1)
	{
		n--;
		sort(a+1,a+n+1,cmp1);
		head=0,tail=500000000;
		while(head<tail)
		{
			mid=(head+tail+1)>>1;
			if(check1(mid)==0)head=mid;else tail=mid-1;
		}
		printf("%d\n",head);
		return 0;
	}
	if(q==n-1)
	{
		n--;
		sort(a+1,a+n+1,cmp2);
		head=0,tail=500000000;
		while(head<tail)
		{
			mid=(head+tail+1)>>1;
			if(check1(mid)==0)head=mid;else tail=mid-1;
		}
		printf("%d\n",head);
		return 0;
	}
	if(m==1)
	{
		bfs(1);
		dis[0]=0;
		for(i=2;i<=n;i++)if(dis[i]>dis[ans])ans=i;
		bfs(ans);
		ans=0;
		for(i=1;i<=n;i++)if(dis[i]>dis[ans])ans=i;
		printf("%d\n",dis[ans]);
		return 0;
	}
}
