#include<iostream>
#include<sstream>
#include<cstdlib>
#include<cstdio>
#include<math.h>
#include<string>
#include<cstring>
#include<algorithm>
int n,t,a[101],bj[100],ans;
using namespace std;
inline int gcd(int a,int b)
{//cout<<a<<" "<<b<<endl;
	if(a<b)
	    swap(a,b);
	return (a%b)?gcd(b,a%b):b;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);//cout<<gcd(19,6);
	scanf("%d",&t);
	for(int x=1;x<=t;++x)
	{
		memset(bj,0,sizeof bj);
		ans=0;
		scanf("%d",&n);
		for(int y=1;y<=n;++y)
		    scanf("%d",a+y);
		for(int y=1;y<=n;++y)
		    for(int z=y;z<=n;++z)
		    {
		    	if(gcd(a[y],a[z])==1)
		        	for(int x1=1;x1<=n;++x1)
		        		if(a[x1]>a[y]*a[z]-a[y]-a[z])
		                    bj[x1]=1;
		        else
		            for(int x2=0;x2*a[y]<=a[x1]&&!bj[x1];++x2)
		                for(int x3=0;x3*a[z]+x2*a[y]<=a[x1]&&!bj[x1];++x3)
		                    if(x3*a[z]+x2*a[y]==a[x1]&&x3*a[z]+x2*a[y]!=a[z]&&x3*a[z]+x2*a[y]!=a[y])
		                        bj[x1]=1;//cout<<x3<<" "<<a[z]<<" "<<x2<<" "<<a[y]<<endl;
		    }
		for(int y=1;y<=n;++y)
		    if(!bj[y])
		        ++ans;
		printf("%d\n",ans);
	}
	return 0;
}
