#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=50000+5;
inline int read()
{
	int sum;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	sum=c-'0';
	c=getchar();
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
struct miaow
{
	int f,t,c,l;
	miaow(int f=0,int t=0,int c=0,int l=0):f(f),t(t),c(c),l(l){}
}imap[N*2];
int str[N]={0},imc=1;
int n,m;
inline void jb(int f,int t,int c)
{
	imap[imc]=miaow(f,t,c,str[f]);
	str[f]=imc++;
	imap[imc]=miaow(t,f,c,str[t]);
	str[t]=imc++;
}

int jl[N]={0},jl2[N]={0};
void dfs1(int o,int fa)
{
	for(int i=str[o];i;i=imap[i].l)
	{
		int t=imap[i].t,c=imap[i].c;
		if(t==fa)continue;
		jl[t]=jl[o]+c;
		dfs1(t,o);
	}
}
void dfs2(int o,int fa)
{
	for(int i=str[o];i;i=imap[i].l)
	{
		int t=imap[i].t,c=imap[i].c;
		if(t==fa)continue;
		jl2[t]=jl2[o]+c;
		dfs2(t,o);
	}
}
inline int solve1()
{
	dfs1(1,0);
	int imax=0,imax2=0;
	for(int i=1;i<=n;i++)
	{
		if(jl[i]>imax)
		{
			imax=jl[i];
			imax2=i;
		}
	}
	dfs2(imax2,0);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(jl2[i]>ans)
		{
			ans=jl2[i];
		}
	}
	return ans;
}

int bc[N],bcqzh[N]={0};
inline bool cmp(const int& qwe,const int& asd)
{
	return qwe>asd;
}
inline int solve2()
{
	sort(bc+1,bc+n,cmp);
	bc[n]=0;
	int l=0,r=bc[1]+bc[2],mid;
	int ans=0;
	while(l<=r)
	{
		mid=(l+r)/2;
		int x=1,y=2,gs=0;
		while(bc[x]+bc[y]>=mid&&y<n)++y;
		while(x<y)
		{
			while(bc[x]+bc[y]<mid&&x<=y)--y;
			if(x>=y)break;
			gs+=1;
			++x;
			if(y!=n)--y;
		}
		if(gs>=m)
		{
			ans=max(mid,ans);
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return ans;
}

struct meow
{
	int f,c;
	meow(int f=0,int c=0):f(f),c(c){}
	inline bool operator < (const meow& qwe) const
	{
		return f<qwe.f;
	}
}bc2[N];
inline int solve3()
{
	sort(bc2+1,bc2+n);
	for(int i=1;i<n;i++)
	{
		bcqzh[i]=bcqzh[i-1]+bc2[i].c;
	}
	int l=0,r=bcqzh[n-1],mid;
	int ans=0;
	while(l<=r)
	{
		mid=(l+r)/2;
		int x=1,y=1,gs=0;
		while(1)
		{
			while(bcqzh[y]-bcqzh[x-1]<mid&&y<n)++y;
			if(y>=n)break;
			++gs;
			x=y+1;
			y=x;
		}
		if(gs>=m)
		{
			ans=max(mid,ans);
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return ans;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	cin>>n>>m;
	int ai1=1,biai1=1,zh=0,imin=1e8;
	for(int i=1;i<n;++i)
	{
		int f=read(),t=read(),c=read();
		if(f!=1&&t!=1)ai1=0;
		if(t-f!=1&&f-t!=1)biai1=0;
		bc[i]=c;
		bc2[i]=meow(f,c);
		zh+=c;
		imin=min(c,imin);
		//bcqzh[i]=bcqzh[i-1]+c;
		jb(f,t,c);
	}
	if(m==1)
	{
		cout<<solve1()<<endl;
	}
	else if(m==n-1)
	{
		cout<<imin<<endl;
	}
	else if(ai1==1)
	{
		cout<<solve2()<<endl;
	}
	else if(biai1==1)
	{
		cout<<solve3()<<endl;
	}
	else
	{
		cout<<zh/m<<endl;
	}
	return 0;
}
