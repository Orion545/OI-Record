#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
inline int read()
{
	int x=0,w=0;char ch=getchar();
	while(ch<'0'||ch>'9')w|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
int dia,ans,ma[51000],last[51000],len,l[51000],ll[51000],n,m;
double sum;
struct node{int x,y,c,ne;}a[110000];
inline void ins(int x,int y,int c)
{
	a[++len].x=x,a[len].y=y,a[len].c=c;
	a[len].ne=last[x],last[x]=len;
}
void find_dia(int x,int fa)
{
	for(int i=last[x];i;i=a[i].ne)
	{
		int y=a[i].y;
		if(y!=fa)
		{
			find_dia(y,x);
			dia=max(dia,ma[x]+ma[y]+a[i].c);
			ma[x]=max(ma[x],ma[y]+a[i].c);
		}
	}
}
void dfs(int x,int s,int mi,int sl)
{
	if(sl>m){ans=max(ans,mi);return;}
	if(x==n)return;
	if(mi<=ans)return;
	if(s+l[x]>=sum||x==n-1){dfs(x+1,0,min(mi,s+l[x]),sl+1);return;}
	if(s+l[x]+l[x+1]>sum)dfs(x+1,0,min(mi,s+l[x]),sl+1);
	dfs(x+1,s+l[x],mi,sl);
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	bool v1=1,v2=1;
	for(int i=1;i<n;++i)
	{
		int x=read(),y=read(),c=read();
		l[x]=c,ll[y-1]=c,sum+=c;
		if(x!=1)v1=0;
		if(y!=x+1)v2=0;
		ins(x,y,c),ins(y,x,c);
	}sum=sum*1.0/m;
	if(m==1)
	{
		find_dia(1,0);
		printf("%d\n",dia);
	}
	else if(v1)
	{
		int k=n-1,minn=sum;
		for(int i=n;i<=2*m;++i)ll[++k]=0;
		sort(ll+1,ll+k+1);
		for(int i=1;i<=m;++i)minn=min(minn,ll[k-i+1]+ll[k-2*m+i]);
		printf("%d\n",minn);
	}
	else if(v2)
	{
		dfs(1,0,sum,1);
		printf("%d\n",ans);
	}else printf("%d\n",(int)sum);
	return 0;
}
