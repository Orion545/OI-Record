#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define of(i,l,r) for(int i=l;i>=r;--i)
#define fe(i,u) for(int i=head[u];i;i=e[i].next)
#define fin(str) freopen(str,"r",stdin)
#define fou(str) freopen(str,"w",stdout)
using namespace std;
typedef long long ll;
inline int rd()
{static int x,f;static char ch;
	x=0;f=1;ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return f>0?x:-x;
}
const int N=110;
int n,a[N],b[N],tt=0;
bool can[250010];

bool dfs(int x,int p)
{
	if(can[x])return 1;
	if(!p)return can[x]=0;
	if(dfs(x,p-1))return can[x]=1;
	of(i,p,1)
		of(j,x/b[i],1)
			if(dfs(x-j*b[i],p-1))return can[x]=1;
	return can[x]=0;
}

inline void gao()
{
	tt=0;memset(can,0,sizeof can);
	n=rd();fo(i,1,n)a[i]=rd();
	sort(a+1,a+n+1);
	int mx=a[n];
	can[0]=1;
	fo(i,1,n){
		if(can[a[i]])continue;
		++tt;
		fo(j,0,mx-a[i])if(can[j])can[j+a[i]]=1;
	}
	printf("%d\n",tt);
}

int main()
{
	fin("money.in");fou("money.out");
	for(int T=rd();T--;gao());
	return 0;
}

