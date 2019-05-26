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
inline void write(LL x)
{
	if(!x){putchar('0');return ;}
	if(x<0)putchar('-'),x=-x;
	int sta[20],top=0;
	while(x)sta[++top]=x%10,x/=10;
	while(top)putchar(sta[top--]+'0');
}
inline void pr1(int x){write(x);putchar(' ');}
inline void pr2(LL x){write(x);putchar('\n');}
int bin[25],a[110000],mn[110000][25],gg[110000],n;
void init()
{
	for(int i=1;bin[i]<=n;i++)
		for(int x=1;x+bin[i]-1<=n;x++)
			mn[x][i]=a[mn[x][i-1]]<a[mn[x+bin[i-1]][i-1]]?mn[x][i-1]:mn[x+bin[i-1]][i-1];
}
int getmin(int l,int r)
{
	int K=gg[r-l+1];
	return a[mn[l][K]]<a[mn[r-bin[K]+1][K]]?mn[l][K]:mn[r-bin[K]+1][K];
}
LL query(int l,int r,int de)
{
	if(l>r)return 0;
	if(l==r)return a[l]-de;
	int u=getmin(l,r);
	return query(l,u-1,a[u])+query(u+1,r,a[u])+a[u]-de;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bin[0]=1;for(int i=1;i<=20;i++)bin[i]=bin[i-1]<<1;
	gg[1]=0;for(int i=2;i<=100005;i++)gg[i]=gg[i>>1]+1;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),mn[i][0]=i;
	init();
	pr2(query(1,n,0));
	return 0;
}
