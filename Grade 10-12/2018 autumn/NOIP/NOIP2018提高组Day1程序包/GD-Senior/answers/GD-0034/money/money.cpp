#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int readin()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
const int maxn=25005;
int n,a[maxn],vis[maxn];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=readin(),maxnum,filled1,ans;
	while(T--)
	{
		n=readin();maxnum=0;
		for(int i=1;i<=n;i++) a[i]=readin(),maxnum=maxnum<a[i]?a[i]:maxnum;
		memset(vis,0,sizeof vis);vis[0]=1;
		sort(a+1,a+n+1);
		ans=filled1=0;
		for(int i=1;i<=n;i++)
			if(!vis[a[i]])
			{
				ans++;
				if(filled1<=maxnum/2)
				{
					for(int j=0;j<=maxnum;j++)
						if(vis[j])
							for(int k=1;j+a[i]*k<=maxnum;k++)
								if(!vis[j+a[i]*k])
									filled1++,vis[j+a[i]*k]=true;
				}
				else
					for(int j=0;j<=maxnum;j++)
						if(!vis[j])
						{
							bool flag=false;
							for(int k=1;j-a[i]*k>=0;k++)
								if(vis[j-a[i]*k])
									{flag=true;break;}
							if(flag) filled1++,vis[j]=true;
						}
			}
		printf("%d\n",ans);
	}
}

