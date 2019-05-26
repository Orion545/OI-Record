#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long t,n,d[300010],maxx,minn,ans,hh[1000010],cnt;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&d[i]);
		if(n==2)
		{
			minn=min(d[1],d[2]);
			maxx=max(d[1],d[2]);
			if(maxx%minn==0) cout<<"1"<<endl;
			else cout<<"2"<<endl;
		}
		if(n==3)
		{
			sort(d+1,d+n+1);
			if(d[2]%d[1]==0&&d[3]%d[1]==0) cout<<"1"<<endl;
			else 
			{
				if(d[2]%d[1]==0||d[3]%d[2]==0||d[3]%d[1]==0) cout<<"2"<<endl;
				else cout<<n<<endl;
			}
		}
		if(n>3) cout<<n<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
