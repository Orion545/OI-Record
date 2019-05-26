#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return f*x;
}
int n,w,tail;
int c[110000];
int d[110000];
int ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)d[i]=read();
	ans=w=0;tail=1;
	c[1]=d[1];d[n+1]=10001;
	for(int i=2;i<=n+1;i++)
	{
		if(d[i]-w<0)
		{
			ans+=c[1];
			int minn=1<<30;int j;
			for(j=i;j;j++)
			{
				if(d[j]<minn)minn=min(minn,d[j]);
				else {j--;break;}
			}
			i=j;tail=0;w=minn;
		}
		else if(!tail||d[i]-w<=c[tail])c[++tail]=d[i]-w;
		else 
		{
			ans+=c[1];w+=c[tail];
			tail=1;c[tail]=d[i]-w;
		}
	}
	printf("%d\n",ans);
	return 0;
}
