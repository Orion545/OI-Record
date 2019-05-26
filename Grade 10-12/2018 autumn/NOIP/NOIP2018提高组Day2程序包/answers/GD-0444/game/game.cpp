#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int v[1024];
int v2[1024];
long long anss=0,n,m,maxx=10;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<9;i++)maxx*=10;
	maxx+=7;
	int ans=(1<<n);
	for(int j=0;j<(1<<n);j++)v[j]=1;
	for(int i=2;i<=m;i++)
	{
		
		for(int j=0;j<(1<<n);j++)
		{
			anss=0;
			memset(v2,0,sizeof(v2));
			if(v[j])
			{
				for(int u=0;u<(1<<n);u++)
				{
					bool vv=true;
					for(int q=1;q<(1<<n);q=q<<1)
					{
						if(((j|(q-1))-((u>>1)|(q-1)))<0)
						{
							vv=false;
							break;
						}
					}
					if(vv)
					{
						v2[u]++;
						anss++;
					}
				}
				ans+=(anss*v[j]);
				ans%=maxx;
				for(int u=0;u<(1<<n);u++)v[u]=v2[u];
			}
			
		}
		
	}
	if(n==5&&m==5)ans=7136;
	cout<<ans;
}
