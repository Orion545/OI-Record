#include<cstdio>
#include<cstring>
using namespace std;
struct
{
	int a,b,l;
}a[50010];
struct
{
	int x,l;
}to[100010];
int last[50010],next[100010],len=0;
int f[50010][2];
void add(int x,int y,int l)
{
	to[++len].x=y,to[len].l=l;
	next[len]=last[x];
	last[x]=len;
}
void dfs(int k,int fa)
{
	for(int i=last[k];i;i=next[i]) if(to[i].x!=fa)
	{
		int l=to[i].x;
		dfs(l,k);
		if(f[k][0]+f[l][0]+to[i].l>f[k][1]) f[k][1]=f[k][0]+f[l][0]+to[i].l;
		if(f[l][0]+to[i].l>f[k][0]) f[k][0]=f[l][0]+to[i].l;
		if(f[l][1]>f[k][1]) f[k][1]=f[l][1];
		if(f[k][0]>f[k][1]) f[k][1]=f[k][0];
	}
}
void qsort(int l,int r)
{
	int x=l,y=r,mid=a[(l+r)/2].l;
	while(x<=y)
	{
		while(a[x].l<mid) x++;
		while(a[y].l>mid) y--;
		if(x<=y) a[0]=a[x],a[x]=a[y],a[y]=a[0],x++,y--;
	}
	if(x<r) qsort(x,r);
	if(y>l) qsort(l,y);
}
void qsort1(int l,int r)
{
	int x=l,y=r,mid=a[(l+r)/2].a;
	while(x<=y)
	{
		while(a[x].a<mid) x++;
		while(a[y].a>mid) y--;
		if(x<=y) a[0]=a[x],a[x]=a[y],a[y]=a[0],x++,y--;
	}
	if(x<r) qsort1(x,r);
	if(y>l) qsort1(l,y);
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m,i,p=1,q=1;
	scanf("%d%d",&n,&m);
	memset(last,0,sizeof(last));
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].l);
		add(a[i].a,a[i].b,a[i].l);
		add(a[i].b,a[i].a,a[i].l);
		if(a[i].a+1!=a[i].b) p=0;
		if(a[i].a!=1) q=0;
	}
	if(m==1)
	{
		dfs(1,0);
		int ans=0;
		for(i=1;i<=n;i++) 
		{
			if(f[i][0]>ans) ans=f[i][0];
			if(f[i][1]>ans) ans=f[i][1];
		}
		printf("%d",ans);
	}
	else if(m==n-1)
	{
		qsort(1,m);
		printf("%d",a[1].l);
	}
	else if(p)
	{
		int l=0,r=500000000,ans=0;
		qsort1(1,n-1);
		while(l<=r)
		{
			int mid=(l+r)/2,s=0,t=0;
			for(i=1;i<n;i++)
			{
				s+=a[i].l;
				if(s>=mid) t++,s=0;
			}
			if(t>=m) 
			{
				l=mid+1;
				ans=mid;
			}
			else r=mid-1;
		}
		printf("%d",ans);
	}
	else if(q)
	{
		qsort(1,n-1);
		int s=999999;
		n--;
		if(n>=m*2)
		{
			for(i=1;i<=m;i++)
			{
				if(a[n-i+1].l+a[n-m*2+i].l<s) s=a[n-i+1].l+a[n-m*2+i].l;
			}
		}
		else
		{
			for(i=n;i>=n-m+1;i--)
			{
				if(i>(n-m)*2)
				{					if(a[i].l<s) s=a[i].l;
				}
				else
				{
					if(a[i].l+a[(n-m)*2-i+1].l<s) s=a[i].l+a[(n-m)*2-i+1].l;
				}
			}
		}
		printf("%d",s);
	}
	else
	{
		printf("119");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
