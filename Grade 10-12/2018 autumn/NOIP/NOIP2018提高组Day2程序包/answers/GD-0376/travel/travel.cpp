#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#define MAXN 5001
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
int nxt[MAXN]={0},lst[MAXN]={0},srt[MAXN]={0};
int n,m,ln=0;
inline void add(int u,int v)
{ln++;	nxt[ln]=v;	lst[ln]=srt[u];	srt[u]=ln;	return;}
int ftr[MAXN]={0};
bool cir[MAXN]={0},fin=0,bb[MAXN]={0};
inline void CIR(int x)
{
	if (bb[x])	return;	bb[x]=1;
	lnf(i,x)	if (nxt[i]!=ftr[x])
	{	if (bb[nxt[i]])
		{	re int k=x;	cir[x]=1;
			while (k!=nxt[i])	k=ftr[k],cir[k]=1;
			fin=1;	return;
		}
		ftr[nxt[i]]=x;	CIR(nxt[i]);
		if (fin)	return;
}	}
bool b[MAXN]={0};
inline void DFS(int x)
{	
	if (b[x])	return;	b[x]=1;	int minn=0;
	printf("%d ",x);
	priority_queue <int> q;
	lnf(i,x)	if (!b[nxt[i]])	q.push(-nxt[i]);
	while (!q.empty())	{DFS(-q.top());	q.pop();}
}
int lsp=0;
bool ul=0,us=0;
inline void DFS2(int x)
{	
	if (b[x])	return;	b[x]=1;
	printf("%d ",x);
	priority_queue <int> q;
	lnf(i,x)	
	{
		if (!b[nxt[i]])	q.push(-nxt[i]);
		if (!ul && cir[x] && cir[nxt[i]])	lsp=lsp>nxt[i]?lsp:nxt[i];
	}	if (lsp)	ul=1;
	while (!q.empty())
	{
		if (!us && ul && cir[-q.top()] && -q.top()>lsp)	{us=1;	return;}
		DFS2(-q.top());	q.pop();
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();	nxt[0]=n;
	f(i,1,m)	{re int u=read(),v=read();	add(u,v);	add(v,u);}
	if (m<n)	DFS(1);	else
	if (m==n)	CIR(1),DFS2(1);
	fclose(stdin);	fclose(stdout);	return 0;
}
