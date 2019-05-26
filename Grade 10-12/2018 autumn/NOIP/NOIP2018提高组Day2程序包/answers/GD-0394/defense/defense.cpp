#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;

int n,m,u[maxn*2],v[maxn*2],p[maxn];
long long Min;
bool f[maxn],vis[maxn];

inline int read()
{
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	int res=ch-48;
	ch=getchar();
	while (ch<='9'&&ch>='0') res=res*10+ch-48,ch=getchar();
	return res;
}

void print(long long x)
{
	if (x>9) print(x/10);
	putchar(x%10+48);
}

inline void add(int x)
{
	int u1=read(),v1=read();
	if (u1>v1)
	{
		u[x]=v1; v[x]=u1;
	}
	else
	{
		u[x]=u1; v[x]=v1;
	}
}

bool check(int a,int az,int b,int bz)
{
	if (!f[a]&&!f[b]&&az==0&&bz==0) return true;
	if (!f[a]&&f[b]&&az==0&&bz==1) return true;
	if (f[a]&&!f[a]&&az==1&&bz==0) return true;
	if (f[a]&&f[b]&&az==1&&bz==1) return true;
	return false; 
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	char bz,sz;
	
	n=read(); m=read(); scanf("%c%c",&bz,&sz);
	for (int i=1; i<=n; i++)
		p[i]=read();
	for (int i=1; i<=n-1; i++)
		add(i);
	for (int i=1; i<=n-1; i++)	
		if (!f[u[i]]&&!f[v[i]])
			if (p[u[i]]>p[v[i]])
			{
				Min+=p[v[i]]; f[v[i]]=true;
			}
			else
			{
				Min+=p[u[i]]; f[u[i]]=true;
			}

	while (m--)
	{
		int a=read(),az=read(),b=read(),bz=read();
		if (check(a,az,b,bz))
		{
			print(Min); printf("\n");
		}
		else
		{
			for (int i=1; i<=n; i++) vis[i]=f[i];
			int x,y,_min=Min;
			if (az==0&&vis[a])
			{
				_min-=p[a];
				if (a==1&&!vis[a+1])
					_min+=p[a+1],vis[a+1]=true;	
				if (a==n&&!vis[a-1])
					_min+=p[a-1],vis[a-1]=true;;
				if (a>=1&&a<=n)
				{
					if (!vis[a-1]&&!vis[a+1]) _min=_min+p[a-1]+p[a+1],vis[a-1]=vis[a+1]=true;
					if (!vis[a-1]&&vis[a+1]) _min+=p[a-1],vis[a-1]=true;
					if (vis[a-1]&&!vis[a+1]) _min+=p[a+1],vis[a+1]=true;
				}
				vis[a]=false;
			}
			if (bz==0&&vis[b])
			{
				_min-=p[b];
				if (b==1&&!vis[b+1])
					_min+=p[b+1],vis[b+1]=true;	
				if (b==n&&!vis[b-1])
					_min+=p[b-1],vis[b-1]=true;
				if (b>=1&&b<=n)
				{
					if (!vis[b-1]&&!vis[b+1]) _min=_min+p[b-1]+p[b+1],vis[b-1]=vis[b+1]=true;
					if (!vis[b-1]&&vis[b+1]) _min+=p[b-1],vis[b-1]=true;
					if (vis[b-1]&&!vis[b+1]) _min+=p[b+1],vis[b+1]=true;;
				}
				vis[b]=false;
			}
			
			if (az==1&&!vis[a])
			{
				_min+=p[a]; vis[a]=true;
				if (a>=3&&a<=n-2)
				{
					if (vis[a+2]) _min=_min-p[a+1],vis[a+1]=false;
					if (vis[a-2]) _min=_min-p[a-1],vis[a-1]=false;
				}
				else
				if (a>=n-1)
				{
					if (a==n-1&&vis[n]) _min-=p[n],vis[n]=false;
					if (vis[a-2]) _min=_min-p[a-1],vis[a-1]=false;
				}
				else
				if (a<=2)
				{
					if (a==2&&vis[1]) _min-=p[1],vis[1]=false;
					if (vis[a+2]) _min-=p[a+1],vis[a+1]=false;
				}
			}
			if (bz==1&&!vis[b])
			{
				_min+=p[b]; vis[b]=true;
				if (b>=3&&b<=n-2)
				{
					if (vis[b+2]) _min=_min-p[b+1],vis[b+1]=false;
					if (vis[b-2]) _min=_min-p[b-1],vis[b-1]=false;
				}
				else
				if (b>=n-1)
				{
					if (b==n-1&&vis[n]) _min-=p[n],vis[n]=false;
					if (vis[b-2]) _min=_min-p[b-1],vis[b-1]=false;
				}
				else
				if (b<=2)
				{
					if (b==2&&vis[1]) _min-=p[1],vis[1]=false;
					if (vis[b+2]) _min-=p[b+1],vis[b+1]=false;
				}
			}
			print(_min); printf("\n");
		}
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}
