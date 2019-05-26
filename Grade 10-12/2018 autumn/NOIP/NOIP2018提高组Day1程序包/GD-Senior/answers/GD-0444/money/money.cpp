#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int t,n,a[110],maxx,b[110],b_size=3;
bool v;
bool check(int x,int k)
{
	if(!(x%b[k]))v=true;
	if(v)return v;
	if(k==b_size)return false;
	int q=x/b[k],i=0;
	while(i<=q)
	{
		v=check(x-i*b[k],k+1);
		i++;
	}
	return v;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		b_size=2;
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		b[1]=a[1];
		int u=2;
		while(!(a[u]%a[1]))u++;
		b[2]=a[u];
		maxx=b[1]*b[2]-b[1]-b[2];
		for(int i=u+1;i<=n;i++)
		{
			if(a[i]>maxx)break;	
			v=false;		
			if(!check(a[i],1))b[++b_size]=a[i];
		}
		n=min(n,b_size);
		printf("%d\n",n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
