#include<iostream>
#include<cstdio>
#include<queue>
#include<cstdlib>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
	if(b!=0)
	{
		int c;
		c=a;
		a=b;
		b=c%a;
		return gcd(a,b);
	}
	else 
	  return a;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while(T)
	{
		int n;
		priority_queue <int> ha;
		priority_queue <int> da;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			ha.push(-a);
			da.push(a);
		}
		int x,xx;
		x=-ha.top();
		ha.pop();
		bool la=true;
		while(la)
		{
			xx=-ha.top();
			int k=gcd(xx,x);
			if(k==1)
			  la=false;
			else
			  ha.pop();
		}
		int ji=x*xx-x-xx;
		int ans;
		while(da.top()>ji&&!da.size())
		{
			da.pop();
		}
		ans=da.size();
		int ka=ji/x,kka=ji/xx;
		int b[105];
		for(int i=1;i<=da.size();i++)
		{
			b[i]=da.top();
			da.pop();
		}
		for(int i=0;i<=ka;i++)
		  for(int j=0;j<=kka;j++)
		    for(int l=1;l<=da.size();l++)
		    {
		    	if(b[l]==i*x+j*xx)
		    	  ans--;
		    }
		if(x==1) ans=1;
		if(x!=1&&ans<2)
		  ans=2;
		if(T>1) 
		  printf("%d\n",ans);
		if(T==1)
		  printf("%d",ans);
		T--;
	}
	return 0;
}
