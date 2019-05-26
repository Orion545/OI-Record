#include <iostream>
#include <cstdio>
#define re register
#define MAXN 200001
#define INF 10001
#define f(a,b,c)	for (re int a=b;a<=c;a++)
#define df(a,b,c)	for (re int a=b;a>=c;a--)
using namespace std;
inline int read()
{
	int p=0;	char c;
	while ((c=getchar())<'0' || c>'9');	p=c-'0';
	while ((c=getchar())>='0'&&c<='9')	p=(p<<3)+(p<<1)+c-'0';
	return p;
}
int a[19][MAXN]={0};
int p[19][MAXN]={0};
int aq=0,n,ans=0;
inline int mint(int l,int r,int ll,int rr,int aqq)
{
	if (l>rr || r<ll)	return 0;
	l=l>ll?l:ll;	r=r<rr?r:rr;
//	cout<<" : "<<l<<"  "<<r<<"  "<<ll<<"  "<<rr<<"  "<<aqq<<endl;
	if (l==ll && r==rr)	return p[aqq][l/(1<<aqq)+(aqq!=0)];
	int mid=((ll+rr)>>1),m1=mint(l,r,ll,mid,aqq-1),m2=mint(l,r,mid+1,rr,aqq-1);
	return a[0][m1]<a[0][m2]?m1:m2;
}
inline void w(int l,int r,int d)
{
	if (l==r)	{ans+=a[0][l]-d;	return;}
	if (l>r)	return;
	int minp=mint(l,r,1,1<<aq,aq);
//	cout<<l<<"  "<<r<<"  "<<d<<"  "<<minp<<"  "<<a[0][minp]<<endl;	Sleep(1000);
	ans+=a[0][minp]-d;
	w(l,minp-1,a[0][minp]);
	w(minp+1,r,a[0][minp]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();	a[0][0]=INF;
	f(i,1,n)	a[0][i]=read(),p[0][i]=i;
	while ((1<<aq)<n)	aq++;
	f(i,n+1,1<<aq)	a[0][i]=INF,p[0][i]=i;;
	f(i,1,aq)	f(j,1,1<<(aq-i))
	if (a[i-1][(j<<1)-1]<a[i-1][j<<1])
		a[i][j]=a[i-1][(j<<1)-1],p[i][j]=p[i-1][(j<<1)-1];	else
		a[i][j]=a[i-1][j<<1],p[i][j]=p[i-1][j<<1];
//	df(i,aq,0)	{f(j,1,1<<(aq-i))	cout<<a[i][j]<<"  ";	cout<<endl;}
//	df(i,aq,0)	{f(j,1,1<<(aq-i))	cout<<p[i][j]<<"  ";	cout<<endl;}
	w(1,n,0);	printf("%d",ans);
	fclose(stdin);	fclose(stdout);	return 0;
}
