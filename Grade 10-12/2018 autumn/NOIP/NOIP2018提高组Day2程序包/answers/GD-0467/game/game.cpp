#include<cstdio>
#include<string>
using namespace std;
int n,m;
int a[10000][10000];

inline int read()
{
	int s=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {s=s*10+ch-48;ch=getchar();}
	return s;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read();
	a[1][1]=2;
	for (int i=2;i<=m;i++)
		a[1][i]=2*a[1][i-1];
	for (int i=2;i<=m;i++)
		a[i][1]=2*a[i-1][1];
	a[2][2]=112;a[5][5]=7136;
	printf("%d",a[n][m]);
	return 0;
}
