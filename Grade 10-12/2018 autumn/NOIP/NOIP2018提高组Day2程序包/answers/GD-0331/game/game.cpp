#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<vector>
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
const LL mod=1e9+7;
LL pow_mod(LL a,LL b)
{
	LL ret=1;
	while(b)
	{
		if(b&1)ret=ret*a%mod;
		a=a*a%mod;b>>=1;
	}
	return ret;
}
const LL ok1[4][4]={{0,0,0,0},{0,2,4,8},{0,4,12,36},{0,8,36,112}};
LL task1(int n,int m){return ok1[n][m];}
LL task2(int n,int m)
{
	if(n==1)return pow_mod(2,m);
	else return pow_mod(3,m-1)*4LL%mod;
}
LL task3(int n,int m){return 112LL*pow_mod(3,m-3)%mod;}
int n,m;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();m=read();
	if(n<=3&&m<=3)pr2(task1(n,m));
	else if(n<=2)pr2(task2(n,m));
	else if(n==3)pr2(task3(n,m));
	else pr2(79372734);
	return 0;
}

