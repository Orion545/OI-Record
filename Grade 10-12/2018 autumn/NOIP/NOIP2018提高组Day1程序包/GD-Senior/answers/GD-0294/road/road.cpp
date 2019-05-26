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
inline void read(ll&x)
{
	static char c;while(!isdigit(c=getchar()));
	for(x=0;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
}
inline void read(int&x){static ll lc;read(lc);x=lc;}
const int maxn=100000+5,maxt=400000+5,inf=100000;
int d[maxn],n,ans,s,p[maxn];
int l[maxt],r[maxt],a[maxt],z[maxt],y[maxt],t[maxn];
inline bool sm(int i,int j){return d[i]<d[j]||(d[i]==d[j]&&i<j);}
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
inline void build(int i,int tl,int tr)
{
	l[i]=tl;r[i]=tr;
	z[i]=1;y[i]=n;a[i]=0;
	if(tl==tr)
	{
		t[tl]=i;
		return;
	}
	build(i<<1,tl,tl+tr>>1);
	build((i<<1)+1,(tl+tr>>1)+1,tr);
}
inline void nw(int i,int j)
{//printf("nw %d %d\n",i,j);
	z[j]=z[i]?z[i]:z[j];
	y[j]=y[i]?y[i]:y[j];
	a[j]+=a[i];
}
inline void rf(int i,int p)
{//printf("rf %d %d\n",i,p);
	if(l[i]==r[i])return;
	int m=l[i]+r[i]>>1;
	nw(i,(i<<1)+1);
	nw(i,i<<1);
	a[i]=0;
	if(p>m)rf((i<<1)+1,p);
      else rf(i<<1,p);
}
inline void ad(int i,int al,int ar,int as)
{//printf("ad %d %d %d %d %d %d\n",i,al,ar,as,l[i],r[i]);
	if(al>r[i]||ar<l[i])return;
	if(l[i]>=al&&r[i]<=ar)
	{
		a[i]+=as;
		return;
	}
	int m=l[i]+r[i]>>1;
	a[i<<1]+=a[i];
	a[(i<<1)+1]+=a[i];
	a[i]=0;
	if(al<=m)ad(i<<1,al,ar,as);
	if(ar>m)ad((i<<1)+1,al,ar,as);
}	
inline void pz(int i,int pl,int pr,int p)
{//printf("pz %d %d %d %d %d %d\n",i,pl,pr,p,l[i],r[i]);
	if(pl>pr||pl>r[i]||pr<l[i])return;
	if(l[i]>=pl&&r[i]<=pr)
	{
		z[i]=p;
		return;
	}
	int m=l[i]+r[i]>>1;
	if(z[i])
	{
		z[i<<1]=z[i];
		z[(i<<1)+1]=z[i];
	}
	z[i]=0;
	if(pl<=m)pz(i<<1,pl,pr,p);
	if(pr>m)pz((i<<1)+1,pl,pr,p);
}
inline void py(int i,int pl,int pr,int p)
{//printf("py %d %d %d %d %d %d\n",i,pl,pr,p,l[i],r[i]);
    if(pl>pr||pl>r[i]||pr<l[i])return;
	if(l[i]>=pl&&r[i]<=pr)
	{
		y[i]=p;
		return;
	}
	int m=l[i]+r[i]>>1;
	if(y[i])
	{
		y[i<<1]=y[i];
		y[(i<<1)+1]=y[i];
	}
	y[i]=0;
	if(pl<=m)py(i<<1,pl,pr,p);
	if(pr>m)py((i<<1)+1,pl,pr,p);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	for(rint i=1;i<=n;++i)
	{
		read(d[i]);
		p[i]=i;
	}
	build(1,1,n);
	q(1,n);
	for(rint i=1;i<=n;++i)
	{
		s=t[p[i]];
		rf(1,p[i]);
		ans+=d[p[i]]-a[s];
		//printf("%d %d\n",p[i],d[p[i]]-a[s]);
		ad(1,z[s],y[s],d[p[i]]-a[s]);
		py(1,z[s],p[i]-1,p[i]);
		pz(1,p[i]+1,y[s],p[i]);
	}
	printf("%d",ans);
	return 0;
}

