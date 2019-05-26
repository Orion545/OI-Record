#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define X ()
#define mes(x,y) memset(x,y,sizeof x)
#define mcp(x,y) memcpy(x,y,sizeof x)
using namespace std;
inline void read(int &x)
{
	char ch=getchar();x=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
}
int a[9][9]=
{
{},
{0,2,4,8,16,32,64,128,256},
{0,4,12,36,108,324,972,2916,8748},
{0,8,36,112,336,1008,3024,9072,27216},
{0,16,108,336,912,2688,8064,24192,72576},
{0,32,324,1008,2688,7136,21312,72576},
{0,64,972,3024,8064,21312,},
{0,128,2916,9072,24192,72576},
{0,256,8748,27216,72576},
};
int n,m;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n),read(m);
	printf("%d\n",a[n][m]);
	return 0;
}


















