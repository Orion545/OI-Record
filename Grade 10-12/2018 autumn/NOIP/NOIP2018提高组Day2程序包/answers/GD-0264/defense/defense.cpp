#include <cstdio>
#include <iostream>
using namespace std;
inline long long read()
{
	long long x=0,w=0;char ch=getchar();
	while(ch<'0'||ch>'9')w|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
char s[10];
long long p[100100],v[100100],f[100100];
long long last[100100],len,n,m;
struct node{long long x,y,ne;}a[200100];
inline void ins(long long x,long long y)
{
	a[++len].x=x,a[len].y=y;
	a[len].ne=last[x],last[x]=len;
}
long long dfs(long long x)
{
	if(x>=n)return 0;
	if(f[x])return f[x];
	if(v[x+2]==1||v[x+1]==0)return f[x]=dfs(x+2)+p[x+2];
	if(v[x+1]==1||v[x+2]==0)return f[x]=dfs(x+1)+p[x+1];
	return f[x]=min(dfs(x+1)+p[x+1],dfs(x+2)+p[x+2]);
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	register long long i,j;n=read(),m=read();
	scanf("%s",s);
	for(i=1;i<=n;++i)p[i]=read();
	for(i=1;i<n;++i)
	{
		long long x=read(),y=read();
		ins(x,y),ins(y,x);
	}
	for(i=1;i<=m;++i)
	{
		for(j=0;j<=n+2;++j)v[j]=-1,f[j]=0;
		long long a=read(),x=read(),b=read(),y=read();
		v[a]=x,v[b]=y;
		if((a==b-1||b==a-1)&&!x&&!y){printf("-1\n");continue;}
		if(x==0)v[a-1]=1,v[a+1]=1;if(y==0)v[b-1]=1,v[b+1]=1;
		printf("%lld\n",dfs(0));
	}
	return 0;
}

