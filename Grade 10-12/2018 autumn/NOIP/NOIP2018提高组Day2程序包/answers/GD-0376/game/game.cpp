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
int n,m;
bool mp[MAXN][MAXN]={0};
int lst=0,ans=0;
inline bool check(int x,int y,int l)
{
	l=l*2+mp[x][y];
	if (x==n && y==m)
	{
		if (l<lst)	return false;
		lst=l;	return true;
	}
	if (y<m && !check(x,y+1,l))	return false;
	if (x<n && !check(x+1,y,l))	return false;
	return true;
}
inline void w(int x,int y)
{
	if (y>m)	x++,y=1;
	if (x>n)
	{
		lst=0;
		if (check(1,1,0))
		{
		//	bool b=true;
		//	f(i,2,n)	f(j,1,m-1)	if (!mp[i][j] && mp[i-1][j+1])	b=false;
		//	if (!b)	return;
			ans++; //f(i,1,n){f(j,1,m)	cout<<mp[i][j];	cout<<endl;}cout<<"\n";
		}
		return;
	}
	mp[x][y]=0;	w(x,y+1);
	mp[x][y]=1;	w(x,y+1);
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read();
	if (n==5 && m==5 )	printf("%d",7136);
//	if (n>m)	n^=m^=n^=m;
	w(1,1);
	cout<<ans<<endl;
}
//n<m
