#include<iostream>
#include<cstdio>
#include<cstring>
const int N=50010;
int n,m,i,j,js,num,z,bj,sum1,mi;
int last[N],next[N],tov[N],len[N],deep[N],le[N],f[N];
long long dis[N],sum[N];
bool bz[N],bz1[N],bz2,one;
int min(int xx,int yy)
{
	if (xx<yy) return xx;
	else
		return yy;
}
int max(int xx,int yy)
{
	if (xx>yy) return xx;
	else
		return yy;
}
void insert(int xx,int yy)
{
	js++;
	tov[js]=yy;
	len[js]=z;
	next[js]=last[xx];
	last[xx]=js;
}
void q(int l,int r)
{
	int z,y,mid;
	z=l;
	y=r;
	mid=sum[(l+r)/2];
	while (l<r)
	{
		while (sum[l]>mid) l++;
		while (sum[r]<mid) r--;
		if (l<=r)
		{
			int jh;
			jh=sum[l];
			sum[l]=sum[r];
			sum[r]=jh;
			l++;
			r--;
		}
	}
	if (l<y) q(l,y);
	if (z<r) q(z,r);
}
void search(int t)
{
	int k=last[t];
	while (k)
	{
		int p=tov[k];
		if (bz[p]==false)
		{
			bz[p]=true;
			deep[p]=deep[t]+1;
			dis[p]=dis[t]+len[k];
			search(p);
		}
		k=next[k];
	}
}
void search1(int t,int xx)
{
	if (t==1) return;
	int k=last[t];
	while (k)
	{
		int p=tov[k];
		if (xx==1)
		{
			if (bz[p]==false)
			{
				bz[p]=true;
				search1(p,1);
				bz[p]=false;
			}
		}
		if (xx==2)
		{
			if (bz1[p]==false)
			{
				bz1[p]=true;
				if (bz[p])
				{
					bj=p;
					bz2=true;
					return;
				}
				search1(p,2);
				if (bz2) return;
			}
		}
		k=next[k];
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	one=true;
	mi=1e5;
	for (i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d%d",&x,&y,&z);
		f[x]++;
		f[y]++;
		insert(x,y);
		insert(y,x);
		if (x!=1) one=false;
		mi=min(mi,z);
	}
	if (m==n-1)
	{
		printf("%d",mi);
		return 0;
	}
	for (i=1;i<=n;i++)
	{
		if (f[i]==1)
		{
			num++;
			le[num]=i;
		}
	}
	memset(bz,false,sizeof(bz));
	memset(deep,0,sizeof(deep));
	memset(dis,0,sizeof(dis));
	bz[1]=true;
	search(1);
	if (m==1)
	{
		long long ans=0;
		for (i=1;i<=num-1;i++)
		{
			for (j=i+1;j<=num;j++)
			{
				memset(bz,false,sizeof(bz));
				bz[le[i]]=true;
				search1(le[i],1);
				memset(bz1,false,sizeof(bz1));
				bz1[le[j]]=true;
				bz2=false;
				bj=0;
				search1(le[j],2);
				int jl=dis[bj];
				ans=max(ans,dis[le[i]]+dis[le[j]]-jl);
			}
		}
		printf("%lld",ans);
		return 0;
	}
	if (one)
	{
		memset(sum,0,sizeof(sum));
		for (i=2;i<=n-1;i++)
		{
			for (j=i+1;j<=n;j++)
			{
				sum1++;
				sum[sum1]=dis[i]+dis[j];
			}
		}
		q(1,sum1);
		long long ans=sum[m];
		printf("%lld",ans);
		return 0;
	}
}
