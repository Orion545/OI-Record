#include <iostream>
#include <cstdio>
#include <algorithm>
#define re register
#define MAXN 101
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
int n,t,ans;
int a[MAXN]={0};
inline bool check(int x,int num)
{
	if (x==1)	return (num%a[1]==0);
	if (num%a[x]==0)	return true;
	df(i,num/a[x],0)	if (check(x-1,num-a[x]*i))	return true;
	return false;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=read();
	while (t--)
	{
		ans=n=read();	f(i,1,n)	a[i]=read();
		sort(a+1,a+n+1);
		f(i,2,n)	if (check(i-1,a[i]))	ans--;
		printf("%d\n",ans);
	}
	fclose(stdin);	fclose(stdout);	return 0;
}
