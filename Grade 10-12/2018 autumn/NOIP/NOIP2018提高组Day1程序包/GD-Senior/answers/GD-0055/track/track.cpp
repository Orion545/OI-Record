#include<cstdio>
#include<cstdlib>
#include<cstring>
#define ll long long

struct map
{
	int x;
	int y;
	int l;
};
map way[1000001];
int first[500001],next[1000001],ma[500001],bz[500001],v[500001],f[40001],n,m,s,x,y,maxl,suml;
ll ans;
int dfs(int z)
{
	int i,ma1=0,ma2=0;
	bz[z]=1;
	i=first[z];
	while(i>=1&&i<=s)
	{
		if(bz[way[i].y]==0)
		{
			dfs(way[i].y);
			if(ma[way[i].y]+way[i].l>ma1)ma2=ma1,ma1=ma[way[i].y]+way[i].l;
			else if(ma[way[i].y]+way[i].l>ma2)ma2=ma[way[i].y]+way[i].l;
			if(ma[way[i].y]+way[i].l>ma[z])ma[z]=ma[way[i].y]+way[i].l;
		}
		i=next[i];
	}
	//printf("%d %d %d %d\n",z,ma1,ma2,ma[z]);
	if(ma1+ma2>ans)ans=ma1+ma2;
}
int find(int l,int r,int t)
{
	//printf("%d %d %d\n",l,r,f[t]);
	if(l==r)
	{
		if(y+f[t]>=m)ans=l;
	}
	else
	{
		if(y+f[t*2+1]>=m)find((l+r)/2+1,r,t*2+1);
		else {y=y+f[t*2+1];find(l,(l+r)/2,t*2);}
	}
}
int change(int l,int r,int t)
{
	if(l==r&&l==x)f[t]++;
	else
	{
		if(l==r)return 0;
		if(l<=x&&x<=(l+r)/2)change(l,(l+r)/2,t*2);
		if((l+r)/2+1<=x&&x<=r)change((l+r)/2+1,r,t*2+1);
		f[t]=f[t*2]+f[t*2+1];
	}
}
int main()
{
freopen("track.in","r",stdin);
freopen("track.out","w",stdout);
int i,j,tf1=1,tf2=1,l,r,mid,num,w;
scanf("%d %d",&n,&m);
s=n-1;
for(i=1;i<=s;i++)
{
	scanf("%d %d %d",&way[i].x,&way[i].y,&way[i].l);
	way[i+s].x=way[i].y;way[i+s].y=way[i].x;way[i+s].l=way[i].l;
	if(way[i].x!=1)tf1=0;
	if(way[i].x+1!=way[i].y)tf2=0;
	if(way[i].l>maxl)maxl=way[i].l;
	suml+=way[i].l;
	v[way[i].x]=way[i].l;
}
s*=2;
for(i=s;i>=1;i--)next[i]=first[way[i].x],first[way[i].x]=i;
if(m==1){dfs(1);printf("%lld",ans);return 0;}
if(tf1==1)
{
	for(i=1;i<=s/2;i++)
	{
		x=way[i].l;
		change(1,maxl,1);
	}
	find(1,maxl,1);
	printf("%lld",ans);
	return 0;
}
if(tf2==1)
{
	//for(i=1;i<n;i++)printf("%d ",v[i]);printf("\n");
	l=1;r=suml;
	while(l<=r)
	{
		mid=(l+r)/2;
		w=0;num=0;
		for(i=1;i<n;i++)
		{
			w=w+v[i];
			if(w>=mid)num++,w=0;
		}
		if(num>=m)ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
}
}
