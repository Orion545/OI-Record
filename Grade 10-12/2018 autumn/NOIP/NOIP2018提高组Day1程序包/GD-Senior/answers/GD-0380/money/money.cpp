#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-48;
		ch=getchar();
	}
	return s*w;
}
int t,n,ans,maxn,minn,times;
int ai[105],v[25005],hasa[25005];
void dfs(int dep,int sum)
{
	if(v[sum]&&dep!=1) 
	{
		hasa[sum]++;
		return;
	}
	if(sum>maxn) return;
	for(int i=1;i<=n;i++)
		dfs(dep+1,sum+ai[i]);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);	
	t=read();
	while(t--)
	{
		n=read();
		ans=n;
		for(int i=1;i<=25000;++i)
			v[i]=ai[i]=hasa[i]=0;
		for(int i=1;i<=n;++i)
		{
			ai[i]=read();
			v[ai[i]]=1;
		}
		sort(ai+1,ai+n+1);
		maxn=ai[n];
		minn=ai[1];
		if(maxn%minn!=0)
		times=maxn/minn+1;
		else times=maxn/minn;
		dfs(0,0);
		for(int i=1;i<=n;i++)
			if(hasa[ai[i]]) ans--;
		cout<<ans<<endl;
	}
	return 0;
}
