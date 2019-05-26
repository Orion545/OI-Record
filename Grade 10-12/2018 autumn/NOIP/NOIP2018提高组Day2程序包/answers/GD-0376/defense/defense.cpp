#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#define INF 1000000000
#define MAXN 100001
#define re register
#define f(a,b,c)	for (re int a=b;a<=c;a++)
#define lnf(a,b)	for (re int a=srt[b];a;a=lst[a])
using namespace std;
inline int read()
{
	int p=0;	char c;
	while ((c=getchar())<'0' || c>'9');	p=(p<<3)+(p<<1)+c-'0';
	while ((c=getchar())>='0'&&c<='9')	p=(p<<3)+(p<<1)+c-'0';
	return p;
}
int mny[MAXN]={0},nxt[MAXN]={0},lst[MAXN]={0},srt[MAXN]={0};
int n,m,ln=0,ans;
inline void add(int u,int v)
{ln++;	nxt[ln]=v;	lst[ln]=srt[u];	srt[u]=ln;	return;}
int ftr[MAXN]={0},f[2][MAXN]={0},dep[MAXN]={0};
bool cse[MAXN]={0};
inline void DFS(int x)
{
	f[1][x]=mny[x];
	lnf(i,x)	if (nxt[i]!=1 && ftr[nxt[i]]==0)
	{	ftr[nxt[i]]=x,dep[nxt[i]]=dep[x]+1,DFS(nxt[i]);
		f[0][x]+=f[1][nxt[i]];
		f[1][x]+=f[0][nxt[i]]<f[1][nxt[i]]?f[0][nxt[i]]:f[1][nxt[i]];
}	}
inline void DFS2(int x)
{
	lnf(i,x)	if (nxt[i]!=ftr[x])	
	{
		if (!cse[x])	cse[nxt[i]]=1;	else
		cse[nxt[i]]=(f[1][nxt[i]]<f[0][nxt[i]]);
		DFS2(nxt[i]);
}	}
int aa=0,xx=0,bb=0,yy=0;
inline int DFS3(int x,bool t)
{
	if (x==aa && t!=xx)	return INF;
	if (x==bb && t!=yy)	return INF;
	if (dep[x]>=dep[aa])	return f[t][x];
	int anss=0;	if (t)	anss=mny[x];
	lnf(i,x)	if (nxt[i]!=ftr[x])
	{	if (t)	
		{	re int x0=DFS3(nxt[i],0),x1=DFS3(nxt[i],1);
			anss+=x0<x1?x0:x1;
		}	else	anss+=DFS3(nxt[i],1);}
	return anss;
}	
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(),m=read();read();
	f(i,1,n)	mny[i]=read();
	f(i,1,n-1)	{re int u=read(),v=read();	add(u,v);	add(v,u);}
	dep[1]=1;	DFS(1);	cse[1]=(f[0][1]>f[1][1]);	DFS2(1);
	
/*	f(i,1,n)	
	cout<<i<<" : "
		<<mny[i]<<"	"
		<<ftr[i]<<"	"
		<<cse[i]<<"	"
		<<f[0][i]<<"	"
		<<f[1][i]<<endl;*/
	
	while (m--)
	{
		ans=f[cse[1]][1];
		re int a=read(),x=read(),b=read(),y=read();	
		if (cse[a]==x && cse[b]==y)	printf("%d\n",ans);	else
		if (!x && !y && (ftr[a]==b || ftr[b]==a))	printf("-1\n");	else
		{
			if (dep[a]<dep[b])	a^=b^=a^=b,x^=y^=x^=y;
			aa=a,bb=b,xx=x,yy=y;
			re int x0=DFS3(1,0),x1=DFS3(1,1);
			printf("%d\n",x0<x1?x0:x1);
		};
	}	fclose(stdin);	fclose(stdout);	return 0;
}
