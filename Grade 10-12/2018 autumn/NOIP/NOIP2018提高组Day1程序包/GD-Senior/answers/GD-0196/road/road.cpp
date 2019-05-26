#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,d[100005],ans;

void solve(int x,int y)
{
	if (x>y) return;
	int min1=10001,cs=0,a[1005];
	memset(a,0,sizeof(a));
	for (int i=x;i<=y;++i)
	 if (d[i]!=0) min1=min(min1,d[i]);
	if (min1==10001) return;
	 	
	for (int i=x;i<=y;++i)
	 if (d[i]==min1)
	  {
	  	++cs;
	  	a[cs]=i;
	  }

	for (int i=x;i<=y;++i)
	 if (d[i]!=0) d[i]-=min1;
	
	ans+=min1;
	a[0]=x;
	a[cs+1]=y;
	
	for (int i=1;i<=cs;++i)
	 {
	 	solve(a[i-1],a[i]);
	    solve(a[i],a[i+1]);
	 }
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	 scanf("%d",&d[i]);

	solve(1,n);

	printf("%d\n",ans);
	return 0;
}
