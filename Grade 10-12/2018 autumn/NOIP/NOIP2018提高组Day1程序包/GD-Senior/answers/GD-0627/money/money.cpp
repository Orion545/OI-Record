#include<bits/stdc++.h>
using namespace std;
int prime[30000],num=0,v[30000],b[30000],vis[30000];
void primes(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!v[i])
		{
			prime[++num]=i;
			v[i]=i;
			b[i]=1;
		}
		for(int j=1;j<=num;j++)
		{
			if(prime[j]>v[i]||prime[j]>n/i) break;
			v[i*prime[j]]=prime[j];
		}
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	primes(25000);
	int T,n,a,ans;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
	    memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		ans=0;
		for(int j=1;j<=n;j++)
		{
			
			scanf("%d",&a);
			if(a==1) 
			{
				printf("1\n");
				break;
			}
			else 
			{
				if(b[a]&&!vis[a])
				{
					ans++;
					vis[a]=1;
				}
			}	
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
