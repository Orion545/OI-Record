#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian
{
	int nex;
	int s;
	int t;
	int v;
}e[110000];
int n,m,a[110000],x,y,z,tot=0,maxx;
bool bj1=true,bj2=true;
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	bj1=true;
	bj2=true;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		scanf("%d%d%d",&x,&y,&a[i]);
	}
	sort(a+1,a+n);
	maxx=0;
	if(m==1) printf("%d",a[n-1]);
	else
	{
		for(int i=1; i<=n; i++)
		if(a[n+m-1-i]+a[i]>maxx) maxx=a[i]+a[n+m-1-i];
		cout<<maxx;
	}
}
