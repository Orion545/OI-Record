#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N=5e4+2;
int daan[N],lj[N<<1][2],xiayige[N<<1],diyige[N],f[N],changdu[N],a[N];
int n,m,k,i,j,x,y,z,c,bs=0,xiao=0,da=0,zhong,hs,zl;
void duruyouhua(int &x)
{
	c=getchar();
	while ((c<48)||(c>57)) c=getchar();
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
}
void jiabian(int x,int y,int z)
{
	lj[++bs][0]=y;
	lj[bs][1]=z;
	xiayige[bs]=diyige[x];
	diyige[x]=bs;
	lj[++bs][0]=x;
	lj[bs][1]=z;
	xiayige[bs]=diyige[y];
	diyige[y]=bs;
}
void ycl(int x)
{
	int i;
	for (i=diyige[x];i;i=xiayige[i]) if (lj[i][0]!=f[x])
	{
		f[lj[i][0]]=x;
		ycl(lj[i][0]);
	}
}
void shensou(int x)
{
	daan[x]=changdu[x]=0;
	int i,j;
	for (i=diyige[x];i;i=xiayige[i]) if (lj[i][0]!=f[x])
	{
		shensou(lj[i][0]);
		daan[x]+=daan[lj[i][0]];
	}
	hs=0;
	for (i=diyige[x];i;i=xiayige[i]) if (lj[i][0]!=f[x]) a[++hs]=changdu[lj[i][0]]+lj[i][1];
	if (hs==0) return;
	sort(a+1,a+hs+1);
	while ((hs)&&(a[hs]>=zhong))
	{
		--hs;++daan[x];
	}
	i=1;j=hs;zl=0;
	while (i<j)
	{
		while ((a[i]+a[j]<zhong)&&(i<j)) ++i;
		if (i>=j) break;
		++zl;++i;--j;
	}
	if (zl==0)
	{
		changdu[x]=a[hs];
		return;
	}
	daan[x]+=zl;
	j=zl<<1|1;
	for (i=1;i<=j;i++) a[i]=a[i+hs-j];
	i=1;--j;
	for (k=1;k<=zl;k++)
	{
		if (a[i]+a[j]>=zhong)
		{
			changdu[x]=a[j+1];
			return;
		}
		if (a[i]+a[j+1]<zhong)
		{
			changdu[x]=a[1];
			return;
		}
		++i;--j;
	}
	if (changdu[x]==0) changdu[x]=a[j+1];
}
bool pd()
{
	shensou(1);
	return daan[1]>=m;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	duruyouhua(n);duruyouhua(m);
	xiao=0;
	for (i=1;i<n;i++)
	{
		duruyouhua(x);duruyouhua(y);duruyouhua(z);
		jiabian(x,y,z);
		da+=z;
	}
	ycl(1);
	while (xiao<da)
	{
		zhong=xiao+da+1>>1;
		if (pd()) xiao=zhong; else da=zhong-1;
	}
	printf("%d",xiao);
}