#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=25005;
int s[N],ans,T,n,max0;
bool vis[N];



int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	while (T--)
	{
		cin>>n;
		memset(vis,false,sizeof(vis));
		vis[0]=true;max0=0;
		for (int a=1;a<=n;++a) 
		{
			cin>>s[a];
			max0=max(max0,s[a]);
		}
		sort(s+1,s+n+1);
		ans=0;
		for (int i=1;i<=n;++i)
		{
			if (!vis[s[i]])
			{
				vis[s[i]]=true;ans++;
				for (int a=s[i];a<=max0;a+=s[i])
				{
					for (int b=max0;b>=a;--b) if(!vis[b]&&vis[b-a]) vis[b]=true;
				}
			}
		}
		cout<<ans<<endl;
		
		
		
	}
	
	
	
	
	fclose(stdin);fclose(stdout);return 0;
}
