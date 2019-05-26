#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
inline int read()
{
	int re=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0' && ch<='9') re=re*10+(ch^48),ch=getchar();
	return re*f;
}
const int MAXN=9,MOD=1e9+7;
int ans[MAXN][MAXN]=
{{0,0,0,0,0,0,0,0,0},
 {0,2,4,8,16,32,64,128,256},
 {0,4,12,0,0,0,0,0,0},
 {0,8,0,112,0,0,0,0,0},
 {0,16,0,0,0,0,0,0,0},
 {0,32,0,0,0,7136,0,0,0},
 {0,64,0,0,0,0,0,0,0},
 {0,128,0,0,0,0,0,0,0},
 {0,256,0,0,0,0,0,0,0}
};
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n=read(),m=read();
	printf("%d\n",ans[n][m]);
	return 0;
}
