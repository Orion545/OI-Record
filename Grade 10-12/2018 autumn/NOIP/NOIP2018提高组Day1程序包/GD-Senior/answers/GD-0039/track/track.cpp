#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxm=6000001;

int n,m,jieguo;

struct lu{
	int u,v,w,next;
}e[maxm];
int a[maxm],head[maxm],dis[maxm],pre[maxm];

int cnt;
void add(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=u;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int flag=0;
	int ans=0;
		for(int i=1,x,y;i<=n-1;++i)
		{
			scanf("%d%d%d",&x,&y,&a[i]);
			ans+=a[i];
			if(x!=1) flag=1;
		}
		if(flag)
		{
			int l=1,r=ans,mid;
			while(l<r)
			{
				mid=(l+r)/2;
				int shu=0,s=0;
				for(int i=1;i<=n;++i)
				{
					s+=a[i];
					if(s>=mid) shu+=1,s=0;
				}
				if(shu>=m) r=mid;
				else l=mid+1;
			}
			printf("%d",l);
		}
		else
		{
			sort(a+1,a+n);
			int l=1,r=ans,mid;
			while(l<r)
			{
				mid=(l+r)/2;
				int zuo=1,you=n,shu=0;
				while(zuo<=you||shu<m)
				{
					if(a[you]>=mid) you--,shu++;
					else if(a[zuo]+a[you]>=mid) zuo++,you--,shu++;
					else zuo++;
				}
				if(shu>=m) l=mid+1;
				else r=mid;
			}
			printf("%d",l);
		}
}
