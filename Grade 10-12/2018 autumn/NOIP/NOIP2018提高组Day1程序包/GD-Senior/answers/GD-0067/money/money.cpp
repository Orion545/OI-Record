#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[200],i,j,k,l,n,t,ans;
bool b[26000];
bool cmp(int x,int y)
{
	return x<y;
}
void dfs(int x,int y)
{
	int l=0;
	if (x>n) return;
	while (l*a[x]+y<=a[n])
	{
		if (a[x]<l*a[x]+y&&b[l*a[x]+y]==true) ans--,b[l*a[x]+y]=false;
		dfs(x+1,y+l*a[x]);
		l++;
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		memset(b,false,sizeof(b));
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		ans=n;
		for (int i=1; i<=n; i++)
		scanf("%d",&a[i]),b[a[i]]=true;
		sort(a+1,a+n+1,cmp);
		if (b[1]==true) printf("1\n");
		else
		{
			dfs(1,0);
			printf("%d\n",ans);
		}
	}
	return 0;
}
