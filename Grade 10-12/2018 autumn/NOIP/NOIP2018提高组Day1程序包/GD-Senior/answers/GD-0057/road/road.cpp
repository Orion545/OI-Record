#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,a[101000],maxx=-1,minn=0x7fffffff;
inline int read()
	{int w=1,s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return w*s;
	}
int main()
	{freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	maxx=a[1];minn=a[1];
	int min1=0,ans1=0,ans2=0;
		for(int i=2;i<=n;i++)
			{if(a[i]<=a[i-1]){maxx=max(a[i-1],maxx);minn=min(a[i],minn);}
			if(a[i]>a[i-1])
				{min1=min(min1,minn);
				ans1=ans1+maxx-min1;
				min1=minn;
				maxx=a[i];
				minn=a[i];
				}
			}
		min1=min(min1,minn);
		ans1=ans1+maxx-min1;
	maxx=-1;minn=0x7fffffff;
	min1=0,ans2=0;
		for(int i=n;i>=2;i--)
			{if(a[i]>=a[i-1]){maxx=max(a[i],maxx);minn=min(a[i-1],minn);}
			if(a[i]<a[i-1])
				{min1=min(min1,minn);
				ans2=ans2+maxx-min1;
				min1=minn;
				maxx=a[i-1];
				minn=a[i-1];
				}
			}
		min1=min(min1,minn);
			ans2=ans2+maxx-min1;	
		printf("%d",min(ans1,ans2));	
		return 0;
	}
