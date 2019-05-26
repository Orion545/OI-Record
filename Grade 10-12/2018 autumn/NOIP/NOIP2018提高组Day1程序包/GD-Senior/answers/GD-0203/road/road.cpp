#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <ctime>
using namespace std;
struct CC
{
	int L,R,nd,nd1,id,d;
}a[100010];
struct node
{
	int d,id;
}ri[100010],le[100010],p[100010];
int b[100010],d[100010];
int n,cnt;
long long ans;

bool rmp(CC x,CC y) 
{
	if (x.d==y.d) return x.L<y.L;
	return x.d>y.d;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 	scanf("%d",&d[i]);
	cnt++;
	a[cnt].d=d[1];
	a[cnt].L=1;
	a[cnt].R=1;
	a[cnt].id=cnt;
	for (int i=2;i<=n;i++) 
	{
		if (d[i]==d[i-1]) 
		{
			a[cnt].R=i;
		} else 
		{
			cnt++;
			a[cnt].id=cnt;
			a[cnt].d=d[i];
			a[cnt].L=i;
			a[cnt].R=i;
		}
	}
	int cnt1=0;
	p[++cnt1].d=a[n].d;
	p[cnt1].id=n;
	for (int i=n-1;i>=1;i--) 
	{
		while (a[i].d<=p[cnt1].d && cnt1>=1) cnt1--;
		p[++cnt1].d=a[i].d;
		p[cnt1].id=i;
		ri[i].d=p[cnt1-1].d;
		ri[i].id=p[cnt1-1].id;
	}
	cnt1=0;
	p[++cnt1].d=a[1].d;
	p[cnt1].id=1;
	for (int i=2;i<=n;i++) 
	{
		while (a[i].d<=p[cnt1].d && cnt1>=1) cnt1--;
		p[++cnt1].d=a[i].d;
		p[cnt1].id=i;
		le[i].d=p[cnt1-1].d;
		le[i].id=p[cnt1-1].id;
	}
	for (int i=1;i<=n;i++) 
	{
		if (ri[i].d>=le[i].d )
		{
			a[i].nd=ri[i].d;
			a[i].nd1=ri[i].id;
		} else 
		{
			a[i].nd=le[i].d;
			a[i].nd1=le[i].id;
		}
	}
	sort(a+1,a+cnt+1,rmp);
	for (int i=1;i<=cnt;i++) b[a[i].id]=i;
	int i=1;
	while (i<=cnt) 
	{
		int temp=i;
		while (a[temp+1].L==a[temp].R+1 && a[temp+1].d==a[temp].d) 
		{
			temp++;
			a[i].R=a[temp].R;
		}
		ans+=(a[i].d-a[i].nd);
		int v=b[a[i].nd1];
		if (a[i].R<a[v].L) a[v].L=a[i].L; else a[v].R=a[i].R;
		i=temp+1;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
