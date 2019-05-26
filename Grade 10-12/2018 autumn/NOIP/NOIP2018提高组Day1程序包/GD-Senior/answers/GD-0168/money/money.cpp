#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>

#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

const int N=105,M=5e4+5;
int T,n,mx;
int a[N],bz[M],f[M],g[M];

inline void read(int &n)
{
	int x=0,w=0; char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	n=w?-x:x;
}

int solve()
{
	memset(bz,0,sizeof(0));
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	fo(i,1,n) f[a[i]]=1,g[a[i]]=1,bz[a[i]]=1;
	fo(j,0,mx) if(f[j])
	{
		fo(i,1,n)
		{
			if(j+a[i]>mx) break;
			f[j+a[i]]=1,g[j+a[i]]=max(g[j+a[i]],g[j]+1);
			if(g[j+a[i]]>1) bz[j+a[i]]=0;
		}
	}
	int ans=0;
	fo(i,1,n) if(a[i]!=a[i-1]&&bz[a[i]]) ++ans;
	return ans;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	read(T);
	while(T--)
	{
		read(n),mx=0;
		fo(i,1,n) read(a[i]),mx=max(mx,a[i]);
		sort(a+1,a+1+n);
		printf("%d\n",solve());
	}
}

