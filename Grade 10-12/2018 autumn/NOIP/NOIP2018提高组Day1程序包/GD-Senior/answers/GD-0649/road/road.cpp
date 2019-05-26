#include<bits/stdc++.h>

using namespace std ;

int n,a,now,ans;

int read()
{
	int x=0;char c=getchar();
	for (;!isdigit(c);c=getchar());
	for (; isdigit(c);c=getchar())x=x*10+(c^48);
	return x;
}

int main()
{
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read(),now=ans=0;
	for (int i=1;i<=n;i++)
	{
		a=read();
		if (a>now) 
			ans+=a-now;
		now=a;
	}
	printf("%d\n",ans);
	
	return 0;
}
