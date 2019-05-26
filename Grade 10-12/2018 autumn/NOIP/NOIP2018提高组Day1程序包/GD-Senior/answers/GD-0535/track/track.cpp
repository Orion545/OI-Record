#include<bits\stdc++.h>
using namespace std;
int yy[200000],v[200000],next[200000],h[60002],n,m;
int an2[60002],tot,maxx[60002],maxx1,maxx2,an1[60002],ans1,ans;
void build(int l,int r,int val)
{
	yy[++tot]=r;
	v[tot]=val;
	next[tot]=h[l];
	h[l]=tot;
}
void dfs(int x,int fa,int yuan)
{
	for(int i=h[x];i && yy[i]!=fa;i=next[i])
	{
		int y=yy[i];
		dfs(y,x,yuan);
		maxx[x]=max(maxx[y]+v[i],maxx[x]);
		if (x==yuan) 
		{
			if (maxx[y]+v[i]>maxx2) maxx2=maxx[y]+v[i];
			if (maxx2>maxx1) 
			{
				int tmp=maxx1;
				maxx1=maxx2;
				maxx2=tmp;
			}
		}
	}
}
bool cmp(int l,int r)
{
	return l<r;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool p=0;
	int tmp1=0;
	for(int i=1;i<=n-1;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if (y-x!=1) p=1;
		an1[x]=z;
		an2[i]=z;
		build(x,y,z);
		build(y,x,z);
		ans1+=z;
		if (x==1) tmp1++;
	}
	if (tmp1==n-1)
	{
		sort(an2+1,an2+n,cmp);
		int l=0,r=ans1+2;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			int i1=0;
			bool p1=0;
			for(int j=n-1;j;j--) 
			{
				while (an2[i1]+an2[j]<mid) i1++;
				if (i1>=j) 
				{
					p1=1;
					break;
				}
				if (n-j>=m) 
				{
					p1=0;
					break;
				}
			}
			if (p1) r=mid;
			else l=mid;
		}
		printf("%d",l);
		return 0;
	}
	if (!p) 
	{
		int l=0,r=ans1+2;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			int tmp=0,ma=0;
			for(int i=1;i<=n-1;i++)
			{
				tmp+=an1[i];
				if (tmp>=mid) ma++,tmp=0;
				if (ma>=m) break;
			}
			if (ma>=m) l=mid;
			else r=mid;
		}
		printf("%d",l);
		return 0;
	}
	int ansi=0;
	for(int i=1;i<=n;i++) 
	{
		memset(maxx,0,sizeof(maxx));
		maxx1=0;
		maxx2=0;
		if (i==3) 
		{
			double tyy=12.19;
		}
		dfs(i,0,i);
		if (maxx1+maxx2>ans) ansi=i;
		ans=max(maxx1+maxx2,ans);
	}
	printf("%d",ans);
}
