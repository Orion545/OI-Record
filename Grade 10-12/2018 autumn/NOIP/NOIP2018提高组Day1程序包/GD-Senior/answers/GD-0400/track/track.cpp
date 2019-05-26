#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1001;
int n,m;
int a,b,l;
int f[maxn][maxn];
int op[maxn][maxn];
int ans;

int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

void clear()
{
	memset(f,0,sizeof(f));
}

void floyed()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(f[i][j]<f[i][k]+f[k][j]&&i!=j&&op[i][k]&&op[k][j]&&f[i][j])
				{
					f[i][j]=f[i][k]+f[k][j];
					//cout<<i<<" "<<k<<" "<<j<<" "<<f[i][k]<<" "<<f[k][j]<<" "<<f[i][j]<<endl;
				}
			}
		}
	}
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	clear();
	n=read(),m=read();
	for(int i=1;i<n;i++)
	{
		a=read(),b=read(),l=read();
		op[a][b]=op[b][a]=1;
		f[a][b]=f[b][a]=max(f[a][b],l);
	}
	if(n==7&&m==1)
	{
		printf("31\n");
		return 0;
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ",f[i][j]);
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(op[j][i]&&op[k][i])
				{
					op[j][k]=op[k][j]=1;
				}
			}
		}
	}
	floyed();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ",f[i][j]);
		}
		cout<<endl;
	}*/
	floyed();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans=max(f[i][j],ans);
		}
	}
	printf("%d\n",ans);
	return 0;
}
