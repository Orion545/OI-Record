#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

inline void read(int &x)
{
	char c; while(!((c=getchar())>='0'&&c<='9'));
	x=c-'0';
	while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
}
const int maxn = 210000;

int n,m;
int sum;
struct edge
{
	int y,c,nex;
}a[maxn]; int len,fir[maxn];
inline void ins(const int x,const int y,const int c){a[++len]=(edge){y,c,fir[x]};fir[x]=len;}

int u,f[maxn][2];
int t[maxn],tp;
int fa[maxn];
int findfa(const int x){ return fa[x]==x?x:fa[x]=findfa(fa[x]); }
void dp(const int x,const int ff)
{
	f[x][0]=f[x][1]=0;
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=ff)
		dp(y,x);
	
	int now=0; tp=0;
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=ff)
	{
		if(f[y][0]+a[k].c>=u) now+=f[y][1]+1;
		else t[++tp]=f[y][0]+a[k].c,now+=f[y][1];
	}
	f[x][1]=now;
	if(tp)
	{
		sort(t+1,t+tp+1);
		for(int i=0;i<=tp+1;i++) fa[i]=i;
		
		int l=1,r=tp;
		for(;l<=tp&&t[l]+t[r]<u;l++);
		for(;l<tp;l=findfa(l+1))
		{
			if(r<=l) r=l+1;
			while(r-1>l&&t[r-1]+t[l]>=u) r--;
			int k=findfa(r);
			if(k<=tp)
			{
				now++;
				fa[l]=l+1;
				fa[k]=k+1;
			}
		}
		
		f[x][1]=now;
		for(int i=tp;i>=1;i--) if(fa[i]==i)
		{
			f[x][0]=t[i];
			break;
		}
	}
}
bool judge(int mid)
{
	u=mid; dp(1,0);
	return f[1][1]>=m;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	len=0; memset(fir,0,sizeof fir);
	
	read(n); read(m);
	for(int i=1;i<n;i++)
	{
		int x,y,c; read(x); read(y); read(c);
		ins(x,y,c),ins(y,x,c);
		sum+=c;
	}
	int l=1,r=sum;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(judge(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",l-1);
	
	return 0;
}

