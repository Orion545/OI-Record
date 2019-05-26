//20'get!
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<string>

#include<vector>
#include<set>
#include<numeric>

#define cg c=getchar()
#define ui unsigned int
#define pc putchar
#define ic isdigit(c)
#define ll long long
#define tt(a) template<typename a>
using namespace std;

tt(GD) void read(GD& x)
{
	x=0; bool f=0;char cg; 
	while(!ic) { if(c=='-')  f=1; cg;}
	while(ic) x=(x<<3)+(x<<1)+(c^48),cg;
	if(f) x=-x;
}

tt(GD) void write(GD x)
{
	if(x<0) pc('-'),x=-x;
	if(x>9) write(x/10);
	pc(x%10+48);
}

const int MAXN = 100000+10;
int n,m;
int tot,head[MAXN],to[MAXN],w[MAXN],nxt[MAXN];
int d1[MAXN],d2[MAXN];
int minn;

void add(int x,int y,int z)
{
	to[++tot]=y;
	w[tot]=z;
	nxt[tot]=head[x];
	head[x]=tot;
}

void input()
{
	read(n);
	read(m);
	minn=0x3f3f3f3f;
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		read(x); read(y); read(z);
		add(x,y,z);
		add(y,x,z);
		minn=min(z,minn);
	}	
}

void dfs(int now,int fa)
{
//	cout<<now<<endl;
	for(int i=head[now];i;i=nxt[i])
	{
//		cout<<"i:"<<i<<" now: "<<now<<" to:"<<to[i]<<endl;
		int go=to[i];
		if(go==fa) continue;
		dfs(go,now);
		if(d1[now]<d1[go]+w[i]) 
		{
			d2[now]=d1[now];
			d1[now]=d1[go]+w[i];
		}
		else if(d2[now]<d1[go]+w[i]) d2[now]=d1[go]+w[i];
	}
	return ;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	input();
	if(m==n-1) 
	{
		write(minn);
		pc('\n');
		return 0;
	}
	dfs(1,0);
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,d1[i]+d2[i]);
	write(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
