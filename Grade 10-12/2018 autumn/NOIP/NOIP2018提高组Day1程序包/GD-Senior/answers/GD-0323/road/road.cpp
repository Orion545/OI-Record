#include<cstdio>
#include<cstring>
using namespace std;
int a[100010],ans=0,s,t,n;
struct
{
	int s,id;
}f[500010];
void add(int k,int l,int r,int x,int y)
{
	if(l==r) f[k].s=y,f[k].id=x;
	else
	{
		int mid=(l+r)/2;
		if(x<=mid) add(k*2,l,mid,x,y);
		else add(k*2+1,mid+1,r,x,y);
		if(f[k*2].s<f[k*2+1].s) f[k]=f[k*2]; else f[k]=f[k*2+1];
	}
}
void find(int k,int l,int r,int x,int y)
{
	if(l==r)
	{
		if(f[k].s<t) t=f[k].s,s=f[k].id;
	}
	else
	{
		int mid=(l+r)/2;
		if(y<=mid) find(k*2,l,mid,x,y);
		else if(x>mid) find(k*2+1,mid+1,r,x,y);
		else 
		{
			find(k*2,l,mid,x,mid);
			find(k*2+1,mid+1,r,mid+1,y);
		}
	}
}
void dfs(int l,int r,int p)
{
	if(l==r) 
	{
		ans+=a[l]-p;
	}
	else
	{
		t=999999;
		find(1,1,n,l,r);
		ans+=t-p;
		int ss=s,tt=t;
		if(ss>l) dfs(l,ss-1,tt);
		if(ss<r) dfs(ss+1,r,tt);
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		add(1,1,n,i,a[i]);
	}
	dfs(1,n,0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
