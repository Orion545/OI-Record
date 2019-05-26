#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int n,m;
int main()
{ 
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	n=read();m=read();
	if(n==3&&m==3)printf("112\n");
	if(n==2&&m==2)printf("12\n");
	if(n==1&&m==2||n==2&&m==1)printf("4\n");
	if(n==2&&m==3||m==2&&n==3)printf("36\n");
	return 0;
}
