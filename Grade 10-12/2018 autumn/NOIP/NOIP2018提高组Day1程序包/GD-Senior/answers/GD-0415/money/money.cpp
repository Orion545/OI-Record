#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<string.h>
#include<cstdio>
#include<math.h>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int N=105;
int T,a[N],pi,n,ans;
bool f[25005];
void read();
void work();
int main()
{
	read();
	while(T--)
	  work();
	return 0;
}
void work()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pi=max(pi,a[i]);
	}  
	memset(f,false,sizeof(f));
	f[0]=true;ans=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	if(!f[a[i]])
	{
		ans++;
		for(int j=0;j<=pi;j++)
		  if(j+a[i]<=pi && f[j])
		    f[j+a[i]]=true;
	}
	printf("%d\n",ans);
}
void read()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	return ;
}
