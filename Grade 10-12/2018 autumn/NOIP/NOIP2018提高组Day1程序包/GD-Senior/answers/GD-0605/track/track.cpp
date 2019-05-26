#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#define N 500005
using namespace std;
int tov[N*2],last[N],nextt[N*2],len[N*2],n,m,x,y,z,tot,bz1,bz2,ma,w,c[N],zz;
int ins(int x,int y,int z){tov[++tot]=y,len[tot]=z,nextt[tot]=last[x],last[x]=tot;}
bool cmp(int x,int y){return x>y;}
int dg(int x,int l,int g)
{
	if (g>ma)
		ma=g,w=x;
	for (int i=last[x];i;i=nextt[i])
	{
		int y=tov[i],z=len[i];
		if (y==l)
			continue;
		dg(y,x,g+z);
	}
}
int pd(int x)
{
	int tt=0,j=1;
	for (int i=1;i<=n;i++)
	{
		tt+=c[i];
		if (tt>=x)
			j++,tt=0;
	}
	if (j>m)
		return 1;
	else
		return 0;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)
		scanf("%d%d%d",&x,&y,&z),ins(x,y,z),ins(y,x,z),bz1+=(x!=1),bz2+=(y!=x+1),zz+=z;
	if (m==1)
	{
		dg(1,0,0),ma=0,dg(w,0,0);
		printf("%d",ma);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if (!bz1)
	{
		for (int i=last[1];i;i=nextt[i])
			c[++c[0]]=len[i];
		sort(c+1,c+1+c[0],cmp),ma=100000000;
		for (int i=1;i<=m;i++)
			ma=min(ma,c[i]+c[2*m-i+1]);
		printf("%d",ma);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if (!bz2)
	{
		for (int i=1;i<=n;i++)
			c[i]=len[last[i]];
		int l=0,r=1000000000;
		while (l<r)
		{
			int mid=(l+r)/2;
			if (pd(mid))
				l=mid+1;
			else
				r=mid;
		}
		if (!pd(l))
			l--;
		printf("%d",l);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	printf("%d",zz/m);
}
