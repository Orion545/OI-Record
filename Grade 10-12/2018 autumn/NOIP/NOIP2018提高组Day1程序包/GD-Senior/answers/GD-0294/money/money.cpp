//provided by hsfz_konjac
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define rua int
#define rint register int
#define INF 2147483647
inline void read(ll&x)
{
	static char c;while(!isdigit(c=getchar()));
	for(x=0;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
}
inline void read(int&x){static ll lc;read(lc);x=lc;}
const int maxn=100+5,maxm=25000+5;
int n,v[maxm],t,m,ans,nx[maxm],pr[maxm],p[maxn];
inline bool sm(int i,int j){return i<=j;}
inline void q(int s,int t)
{
	int h=t,l=s,m=s+t>>1;
	p[0]=p[m];p[m]=p[l];
	while(h>l)
	{
		while(h>l&&sm(p[0],p[h]))--h;
		if(h>l)p[l++]=p[h];
		while(h>l&&sm(p[l],p[0]))++l;
		if(h>l)p[h--]=p[l];
	}
	p[l]=p[0];
	if(h+1<t)q(h+1,t);if(s<l-1)q(s,l-1);
}
inline bool able(int a,int b)
{
	int c=a/b,i=1;
	while(i<=c&&!v[a-b*i])++i;
	return i<=c;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	read(t);
	while(t--)
	{
		read(n);memset(v,0,sizeof(v));
		m=0;v[0]=1;ans=0;
		for(rint i=1;i<=n;++i)read(p[i]);
		q(1,n);
		for(rint i=1;i<=p[n];++i)
		{
			pr[i]=i-1;
			nx[i-1]=i;
		}
		nx[p[n]]=0;pr[0]=0;
		for(rint i=1;i<=n;++i)if(!v[p[i]])
		{
			++ans;
			for(rint j=nx[0];j;j=nx[j])if(able(j,p[i]))
			{
				v[j]=1;
				nx[pr[j]]=nx[j];
				pr[nx[j]]=pr[j];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

