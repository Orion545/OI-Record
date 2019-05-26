#include<iostream>
#include<cstdio>
#include<cstring>
const int N=5010;
int n,m,i,j,js;
int tov[N],last[N],next[N],f[N];
bool bz[N];
void ins(int xx,int yy)
{
	js++;
	tov[js]=yy;
	next[js]=last[xx];
	last[xx]=js;
}
void q(int l,int r)
{
	int z=l,y=r,mid=f[(l+r)/2];
	while (l<r)
	{
		while (f[l]<mid) l++;
		while (f[r]>mid) r--;
		if (l<=r)
		{
			int jh;
			jh=f[l];
			f[l]=f[r];
			f[r]=jh;
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
	int f1[N];
	int jl=0;
	while (k)
	{
		int p=tov[k];
		if (!bz[p])
		{
			jl++;
			f[jl]=p;
		}
		k=next[k];
	}
	q(1,jl);
	for (k=1;k<=jl;k++)
	{
		f1[k]=f[k];
	}
	for (k=1;k<=jl;k++)
	{
		if (!bz[f1[k]])
		{	
			printf("%d ",f1[k]);
			bz[f1[k]]=true;
			search(f1[k]);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ins(x,y);
		ins(y,x);
	}
	memset(bz,false,sizeof(bz));
	bz[1]=true;
	printf("1 ");
	search(1);
	return 0;
}
