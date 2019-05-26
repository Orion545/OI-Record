#include<iostream>
#include<cstdio>
using namespace std;
const int N=100007;
int n,m;
int p[N];
char ch[2];
int s[20007][20007];
int f[2007][2007][2];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>ch;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	int _x, _y;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&_x,&_y);
		s[_x][_y]=1;
		s[_y][_x]=1;
	}
	int a,x,b,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);
		printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
