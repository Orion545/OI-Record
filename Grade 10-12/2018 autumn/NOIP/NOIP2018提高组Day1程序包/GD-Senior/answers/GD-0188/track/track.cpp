#include<bits/stdc++.h>

#define imax(a,b) ((a>b)?(a):(b))
#define imin(a,b) ((a<b)?(a):(b))

using namespace std;

typedef long long ll;

const int N=100005;

int n,m;
//int fs[N],vs[N],bk;
int to[N],ne[N],h[N],val[N],tt;
//int to1[N],ne1[N],h1[N],val1[N],tt1;
struct data { int s; ll l; };
ll slen,sk,L,R,Mid;

void addedge(int a,int b,int c) {
	to[++tt]=b; ne[tt]=h[a]; h[a]=tt; val[tt]=c;
	swap(a,b);
	to[++tt]=b; ne[tt]=h[a]; h[a]=tt; val[tt]=c;
}

/*void addedge1(int a,int b,int c) {
	to1[++tt1]=b; ne1[tt1]=h1[a]; h1[a]=tt1; val1[tt1]=c;
	swap(a,b);
	to1[++tt1]=b; ne1[tt1]=h1[a]; h1[a]=tt1; val1[tt1]=c;
}*/

data find(int x,int fa)
{
	data A;
	ll f1=0,f2=0,f3=0;
	int sx=0;
	for(int p=h[x];p;p=ne[p])
	{
		int tp=to[p];
		if(tp==fa) continue;
		//printf("%d -> %d  %d\n",x,tp,val[p]);
		A=find(tp,x); A.l+=val[p];
		sx+=A.s;
		if(A.l>f1) f3=f2,f2=f1,f1=A.l; else
		if(A.l>f2) f3=f2,f2=A.l; else
		if(A.l>f3) f3=A.l;
	}
	A.s=sx;
	if(f2+f3>=sk) ++A.s,A.l=f1; else
	if(f1+f3>=sk) ++A.s,A.l=f2; else
	if(f1+f2>=sk) ++A.s,A.l=f3; else A.l=f1;
	return A;
}

bool pd(ll Mid)
{
	sk=Mid;
	data A=find(1,1);
	return (A.s>=m);
}

/*void change(int x,int fa)
{
	int son=0;
	for(int p=h1[x];p;p=ne1[p])
	{
		int tp=to1[p];
		if(tp==fa) continue;
		fs[++son]=tp;
		vs[tp]=val1[p];
	}
	while(son>3)
	{
		int las=bk;
		for(int i=1;i<=son;i+=3)
		{
			++bk;
			for(int j=0;j<3;++j)
			if(i+j<=son) addedge(fs[i+j],bk,(fs[i+j]<=n)?vs[fs[i+j]]:0);
		}
		for(int i=1;i<=son;++i) fs[i]=0;
		son=bk-las;
		for(int i=1;i<=son;++i) fs[i]=las+i;
	}
	for(int i=1;i<=son;++i) addedge(fs[i],x,(fs[i]<=n)?vs[fs[i]]:0),fs[i]=0;
	for(int p=h1[x];p;p=ne1[p])
	{
		int tp=to1[p];
		if(tp==fa) continue;
		change(tp,x);
	}
}*/

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i)
	{
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		//addedge1(a,b,c);
		addedge(a,b,c);
		slen+=c;
	}
	/*bk=n;
	change(1,1);*/
	ll L=1,R=slen/m,Mid;
	while(L+1<R)
	{
		Mid=(L+R)>>1;
		if(pd(Mid)) L=Mid; else R=Mid;
	}
	if(pd(R)) L=R;
	printf("%lld\n",L);
	return 0;
}
