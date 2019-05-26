#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int a[110],b[110],c[600010];
int read()
{
	char C;int ret=1;
	C=getchar();
	while(C<'0'||C>'9')
	{
	  if(C=='-') ret=-1;
	  C=getchar();
	}
	int num=0;
	while(C>='0'&&C<='9') num=num*10+C-48,C=getchar();
	return num*ret;
}
int gcd(int x,int y)
{
	int r=x%y;
	while(r>0)
	{
		x=y;
		y=r;
		r=x%y;
	}
	return y;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	while(T)
	{
		T--;
		int n=read();
		for(int i=1; i<=n; i++) a[i]=read();
		sort(a+1,a+n+1);
		if(a[1]==1) {printf("1\n");continue;}
		for(int i=1; i<=n; i++)
		 for(int j=i+1; j<=n; j++)
		  if(a[i]&&a[j]&&gcd(a[i],a[j])>1) a[j]=0;
		int tot=0;
		memset(c,0,sizeof(c));
		for(int i=1; i<=n; i++)
		 if(a[i]) b[++tot]=a[i],c[a[i]]=2;
		for(int i=1; i<=25000; i++)
		 if(c[i]>0)
		 {
		 	for(int j=1; j<=tot; j++)
		 	 if(b[j]!=i) c[i+b[j]]=1;
		 }
		int ans=0;
		for(int i=1; i<=25000; i++) 
		 if(c[i]==2) ans++;
		printf("%d\n",ans);
	}
	return 0;
}

