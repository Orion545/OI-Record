#include<iostream>
#include<cstdio>
using namespace std;
int n,d[100001],cnt=99999,anss=0;
void see(int l,int r)
{
	if(l>r)
		return;
	int midd;
	cnt=99999;
	for(int i=l;i<=r;i++)
		if(d[i]<cnt)
		{
			cnt=d[i];
			midd=i;
		}
	anss+=cnt;
	for(int i=l;i<=r;i++)
		d[i]-=cnt;
	see(l,midd-1);
	see(midd+1,r);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int midd;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		if(d[i]<cnt)
		{
			cnt=d[i];
			midd=i;
		}
	}
	for(int i=1;i<=n;i++)
		d[i]-=cnt;
	anss+=cnt;
	see(1,midd-1);
	see(midd+1,n);
	printf("%d\n",anss);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
