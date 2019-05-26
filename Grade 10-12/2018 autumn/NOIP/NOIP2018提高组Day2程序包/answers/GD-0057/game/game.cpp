#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
long long mod=1e9+7;
int f[(1<<8)+1][1000001];
int n,m;
inline int read()
{int w=1,s=0;
char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
return w*s;	
}
int main()
{freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
n=read();m=read();
for(int i=0;i<=((1<<n)-1);i++)f[1][i]=1;
		for(int j=2;j<=m;j++)
			{for(int k=0;k<=(1<<n)-1;k++)
				{for(int i=0;i<=(1<<n)-1;i++)
					{if((i^(k>>1))==0)
						{f[j][k]=(f[j][k]+f[j-1][i])%mod;
						}
					else
						{bool flag=0;
						for(int g=1;g<n;g++)
							{if((i&(1<<(g-1)))>((k>>1)&(1<<(g-1))))flag=1;
							}
						if(!flag)f[j][k]=(f[j][k]+f[j-1][i])%mod;
						}	
					}
				}
			}
		long long ans=0;
	for(int i=0;i<=((1<<n)-1);i++)ans=(ans+f[m][i])%mod;
	printf("%lld",ans);
}
