#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#define LL long long
#define mp(x,y) make_pair(x,y)
using namespace std;
inline int read()
{
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(int x)
{
	if(!x){putchar('0');return ;}
	if(x<0)putchar('-'),x=-x;
	int sta[20],top=0;
	while(x)sta[++top]=x%10,x/=10;
	while(top)putchar(sta[top--]+'0');
}
inline void pr1(int x){write(x);putchar(' ');}
inline void pr2(int x){write(x);putchar('\n');}
int vis[55005],n,a[110],mx;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+1+n);
		n=unique(a+1,a+1+n)-(a+1);
		mx=a[n];
		memset(vis,0,sizeof(vis));vis[0]=1;
		for(int i=1;i<=n;i++)
			for(int j=a[i];j<=mx;j++)
			{
				vis[j]+=vis[j-a[i]];
				if(vis[j]>2)vis[j]=2;
			}
		int ans=0;
		for(int i=1;i<=n;i++)if(vis[a[i]]==1)ans++;
		pr2(ans);
	}
	return 0;
}

