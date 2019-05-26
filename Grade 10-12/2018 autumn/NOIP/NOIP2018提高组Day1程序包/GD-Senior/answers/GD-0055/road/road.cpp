#include<cstdio>
#include<cstdlib>
#include<cstring>
#define ll long long

int a[100001],f[400001],d[1000001][3],n,x,y,w;
ll ans;
int build(int l,int r,int t)
{
	if(l==r)f[t]=a[l];
	else
	{
		build(l,(l+r)/2,t*2);
		build((l+r)/2+1,r,t*2+1);
		if(f[t*2]<f[t*2+1])f[t]=f[t*2];
		else f[t]=f[t*2+1];
	}
}
int find(int l,int r,int t)
{
	if(x<=l&&r<=y)
	{
		if(f[t]<w||w==-1)w=f[t];
	}
	else
	{
		if(l==r)return 0;
		if(l<=x&&x<=(l+r)/2||l<=y&&y<=(l+r)/2||x<=l&&(l+r)/2<=y)find(l,(l+r)/2,t*2);
		if((l+r)/2+1<=x&&x<=r||(l+r)/2+1<=y&&y<=r||x<=(l+r)/2+1&&r<=y)find((l+r)/2+1,r,t*2+1);
	}
}
int main()
{
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int i,j,h,t,last,l,r,mid,c,mi;
scanf("%d",&n);
for(i=1;i<=n;i++)scanf("%d",&a[i]);
build(1,n,1);
d[1][0]=1;d[1][1]=n;d[1][2]=0;
h=0;t=1;
while(h<t)
{
	h++;//printf("%d %d %d\n",d[h][0],d[h][1],d[h][2]);
	x=d[h][0];y=d[h][1];w=-1;
	find(1,n,1);
	mi=w;
	ans=ans+(ll)mi-(ll)d[h][2];
	last=d[h][0];
	while(true)
	{
		l=last;r=d[h][1];c=0;
		while(l<=r)
		{
			mid=(l+r)/2;
			x=last;y=mid;w=-1;
			find(1,n,1);
			if(w==mi)c=mid,r=mid-1;
			else l=mid+1;
		}
		if(c==0)break;
		if(last<c){t++;d[t][0]=last;d[t][1]=c-1;d[t][2]=mi;}
		last=c+1;
	}
	if(last<=r){t++;d[t][0]=last;d[t][1]=r;d[t][2]=mi;}
}
printf("%lld",ans);
return 0;
}
