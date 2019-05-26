#include<iostream>
#include<cstdio>
#include<cstring>
#define N 120000
using namespace std;
int n,a[N];
long long ans;
void wo(int l,int r,int cnt)
{
	int s[n+1];
	if (l==r)	
	{
		ans+=a[l]-cnt;
		return;
	}
	int minn=12000;	int tot=0;
	for (int i=l;i<=r;i++)
	if (a[i]<minn)
	{
		tot=1;
		s[1]=i;
		minn=a[i];
	}
	else if (a[i]==minn)	s[++tot]=i;
	ans+=minn-cnt;
	if (s[1]!=l)	wo(l,s[1]-1,minn);
	if (s[tot]!=r)	wo(s[tot]+1,r,minn);
	for (int i=1;i<=tot-1;i++)	if ((s[i+1]-s[i])>=2)wo(s[i]+1,s[i+1]-1,minn);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)	scanf("%d",&a[i]);
	wo(1,n,0);
	printf("%lld\n",ans);
	fclose(stdin);	fclose(stdout);
	return 0;
}
