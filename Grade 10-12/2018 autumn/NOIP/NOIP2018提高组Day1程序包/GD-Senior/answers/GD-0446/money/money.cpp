#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=110;
int t,n,a[N];

int read()
{
	char c=getchar();int x=0,f=1;
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}

int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}

void gg()
{
	if(n==2)
	{
		int t=gcd(a[1],a[2]);
		if(t==a[1]||t==a[2])printf("1\n");
		else printf("2\n");
		return;
	}
	else
	{
		for(int i=1;i<=n;i++)if(a[i]==1){printf("1\n");return;}
		int tag=0;
		for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]==25010||a[j]==25010)continue;
			int t=gcd(a[i],a[j]);
			if(t==a[i]||t==a[j]){tag++;if(a[i]<a[j])a[j]=25010;else a[i]=25010;}
		}
		sort(a+1,a+n-tag+1);
		int t=n-tag;
		for(int i=1;i<n;i++)
		{
			int te=a[i]*a[i+1]-a[i]-a[i+1];
			if(te<a[t])a[t--]=25010;
		}
		int ans=0;
		for(int i=1;i<=n;i++)if(a[i]!=25010)ans++;
		printf("%d\n",ans);
	}
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=read();
	for(int tt=1;tt<=t;tt++)
	{
		n=read();
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)a[i]=read();
		gg();
	}
	return 0;
}
