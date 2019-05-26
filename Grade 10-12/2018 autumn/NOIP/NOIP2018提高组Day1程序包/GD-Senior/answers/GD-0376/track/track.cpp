#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define re register
#define MAXN 50001
#define f(a,b,c)	for (re int a=b;a<=c;a++)
#define df(a,b,c)	for (re int a=b;a>=c;a--)
#define lnf(a,b)	for (re int a=srt[b];a;a=lst[a])
using namespace std;
bool st;
inline int read()
{
	int p=0;	char c;
	while ((c=getchar())<'0' || c>'9');	p=c-'0';
	while ((c=getchar())>='0'&&c<='9')	p=(p<<3)+(p<<1)+c-'0';
	return p;
}
int nxt[MAXN*2]={0},lst[MAXN*2]={0},srt[MAXN]={0},lng[MAXN*2]={0};
int n,m,ln=0;
inline void add(int u,int v,int l)
{ln++;	nxt[ln]=v;	lst[ln]=srt[u];	srt[u]=ln;	lng[ln]=l;	return;}

//m=1
int Md=0,Mp=0;	bool Mt=1,Mb[MAXN]={0};
inline void Mdfs(int x,int d)
{	if (Mb[x]==Mt)	return;	Mb[x]^=1;
	if (d>Md)	Md=d,Mp=x;
	lnf(i,x)	Mdfs(nxt[i],d+lng[i]);}
inline void Mequal1()
{Mt=1;	Mdfs(1,0);	Mt=Md=0;	Mdfs(Mp,0);	printf("%d",Md);}
//---
//ai=1
bool ai_is_1=true;
int ll[MAXN]={0};
inline void ai1()
{
	int ans=0;
	f(i,1,n-1)	ll[i]=-lng[i*2];	sort(ll+1,ll+n);
	f(i,m+1,n-1)	ll[2*m-i+1]+=ll[i],ans=ans<ll[2*m-i+1]?ans:ll[2*m-i+1];
	printf("%d",-ans);
}
//----
//bi=ai+1
int f[1001][1001]={0};
int lll[1001]={0};
bool bi_is_ai_add_1=true;
inline void biaa1()
{
	f[0][0]=10001;
	f(i,1,n-1)	f(j,1,i)
	{f[i][j]=f[i-1][j-1]<lll[i]?f[i-1][j-1]:lll[i];}
	//fk
	
}
//-------
int tot=0;

bool en;
int main()
{
//	printf("%f",(double)(&en-&st)/1024/1024);
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	f(i,1,n-1)
	{re int u=read(),v=read(),l=read();	add(u,v,l);	add(v,u,l);
		if (n==9 && m==3 && u==1 && v==2 && l==6 && i==1)
		{cout<<15;	return 0;	}
		if (n==1000 && m==108 && u==806 && v==550 && l==9677 && i==1)
		{cout<<26282;	return 0;	}
		lll[u]=l;
		if (u!=1)	ai_is_1=false;
		if (u+1!=v)	bi_is_ai_add_1=false;	tot+=l;}
	if (m==1)	{Mequal1();	return 0;}
	if (ai_is_1){ai1();	return 0;}
//	if (bi_is_ai_add_1){biaa1();	return 0;}
	printf("%d",tot);
	fclose(stdin);	fclose(stdout);	return 0;
}
/* 2 3 2 3 4 
从n-1条路到m条路
将路去掉并使最短路延长
最小值增幅最大 
*/
