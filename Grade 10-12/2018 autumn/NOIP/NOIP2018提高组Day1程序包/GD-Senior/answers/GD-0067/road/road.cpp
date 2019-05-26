#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
	int w,p;
}a[110000];
long long n,i,j,k,l,mn,num,ans,t;
bool b[110000];
bool cmp(node x,node y)
{
	if (x.w<y.w) return 1;
	else if(x.w==y.w&&x.p<y.p) return 1;
	else return 0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	b[0]=b[n+1]=true;
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&a[i].w);
		a[i].p=i;
	}
	sort(a+1,a+n+1,cmp);
	k=a[1].w;
	num=1;
	l=1;
	while (num<=n)
	{
		ans=1ll*(ans+(k-t)*l);
		t=k;
		while (a[num].w-k==0) 
		{
			b[a[num].p]=true;
			if (b[a[num].p-1]==true&&b[a[num].p+1]==true) l--;
			else
			if (b[a[num].p-1]==false&&b[a[num].p+1]==false) l++;
			num++;
		}
		
		k=a[num].w;
	}
	printf("%lld",ans);
}
