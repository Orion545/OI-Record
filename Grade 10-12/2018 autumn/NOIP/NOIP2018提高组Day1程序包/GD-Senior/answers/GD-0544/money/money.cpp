#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

int a[110];
bool v[31000];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		memset(v,false,sizeof(v));v[0]=true;
		for(int i=1;i<=n;i++)
		{
			if(v[a[i]]==false)ans++;
			else continue;
			for(int j=a[i];j<=30000;j++)
				if(v[j-a[i]]==true)v[j]=true;
		}
		printf("%d\n",ans);
	}
	return 0;
}
