#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct zd
{
	int x;
	int y;
}a[5050];
int i,j,k,l,n,m,q,p,bi,e,dis,f[50050],ans[5050],v[5050],s[5050];
bool cmp1(zd x,zd y)
{
	return x.x<y.x;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	j=0;
	for(i=1;i<=m;i++) 
	{
		j++;	
		scanf("%d%d",&a[j].x,&a[j].y);
		j++;
		a[j].x=a[j-1].y; a[j].y=a[j-1].x;
	}
	sort(a+1,a+j+1,cmp1);
	for(i=1;i<=j;i++)
	if(a[i].x!=a[i-1].x) s[a[i].x]=i;
	q=1;
	ans[1]=1;
	e=1;
	while(e<n)
	{
		bi=9999999; dis=0;
		for(i=s[q];i<=j;i++)
		{
			if(a[i].x!=q) break;
			if(!v[a[i].y]&&a[i].y<bi)
			{
				bi=a[i].y;
				dis=i;
			}
		}
		v[q]=1;
		if(dis==0)
		{
			l--;
			q=ans[l];
		}
		else
		{
			e++;
			ans[e]=a[dis].y;
			q=a[dis].y;
			l=e;
		}
	}
	for(i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}

