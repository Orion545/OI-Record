#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL read()
{
	LL num=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		num=num*10+ch-'0';
		ch=getchar();
	}
	return num*f;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),lst=read(),minn=0X3f3f3f3f;
	LL ans=0,p=0;
	for(int i=1;i<n;i++)
	{
		int a=read(); minn=min(minn,a);
		int t=a-lst;
		if(p+t<0)
		{
			ans+=abs(t);
			p=0;
		}
		else
		{
			if(t<0) ans+=abs(t);
			p+=t;
		}
		lst=a;
	}
	printf("%lld",ans+minn+p);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
