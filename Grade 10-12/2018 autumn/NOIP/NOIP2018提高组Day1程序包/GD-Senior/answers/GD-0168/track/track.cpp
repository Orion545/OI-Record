#include<algorithm>
#include<cstdio>
#include<cctype>

#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

const int N=5e4+5;
int n,m,k,num,sum,time;
int h[N],f[N][2];
int d[N],cd[N],dis[N],last[N];
struct edge{int to,next,l;}e[2*N];
struct node{int x,y,z;}a[N];

inline void read(int &n)
{
	int x=0,w=0; char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	n=w?-x:x;
}

void link(int x,int y,int z)
{
	e[++num]=(edge){y,last[x],z},last[x]=num;
}

void dfs(int x,int fa)
{
	for(int w=last[x];w;w=e[w].next)
	{
		int y=e[w].to;
		if(y==fa) continue;
		dis[y]=dis[x]+e[w].l;
		cd[++time]=dis[y];
		dfs(y,x);
		if(f[y][1]+e[w].l>=f[x][1]) f[x][0]=f[x][1],f[x][1]=f[y][1]+e[w].l;
			else if(f[y][1]+e[w].l>f[x][0]) f[x][0]=f[y][1]+e[w].l;
		h[x]=max(h[x],h[y]);
		h[x]=max(h[x],f[x][1]+f[x][0]);
	}
}

bool cmp(node x,node y)
{
	return x.z<y.z;
}

bool check(int len)
{
	int lst=m,road=0;
	fo(i,1,m)
	{
		if(a[i].z>len)
		{
			++road;
			if(road>=k) return 1;
			continue;
		}
		while(a[i].z+a[lst].z<len&&lst) --lst;
		if(lst<i) return 0;
		--lst,++road;
		if(road>=k) return 1;
	}
}

bool pd(int len)
{
	int lst=1,road=0;
	fo(i,1,n)
	{
		if(dis[i]-dis[lst]>=len)
			++road,lst=i;
		if(road>=k) return 1;
	}
	return 0;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	read(n),read(k),m=n-1;
	int _1=1,_c=1;
	fo(i,1,n-1)
	{
		read(a[i].x),read(a[i].y),read(a[i].z),sum+=a[i].z;
		link(a[i].x,a[i].y,a[i].z),link(a[i].y,a[i].x,a[i].z);
		_1&=(a[i].x==1);
		_c&=(a[i].y==a[i].x+1);
		++d[a[i].x],++d[a[i].y];
	}
	
	//20
	if(k==1)
	{
		dfs(1,0);
		printf("%d",h[1]);
		return 0;
	}
	
	//20
	if(_1)
	{
		sort(a+1,a+1+m,cmp);
		int l=0,r=sum,ans=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid)) l=mid+1,ans=max(ans,mid);
				else r=mid-1;
		}
		printf("%d",ans);
		return 0;
	}
	
	//20
	if(_c)
	{
		int rt=0;
		fo(i,1,n) if(d[i]==1)
		{
			rt=i;
			break;
		}
		dfs(rt,0);
		int l=0,r=sum,ans=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(pd(mid)) l=mid+1,ans=max(ans,mid);
				else r=mid-1;
		}
		printf("%d",ans);
		return 0;
	}
}

