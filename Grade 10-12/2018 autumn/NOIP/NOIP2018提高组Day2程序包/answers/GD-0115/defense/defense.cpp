#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define fup(i,a,b) for(int i=a;i<=b;i++)
#define fow(i,a,b) for(int i=a;i>=b;i--)
const int N = 1e5+7;
int f[N][2],n,m,a[N],zt[N]; char o[3];
int len,dq[N],la[N],d[N];
void add(int x,int y){ d[++len] = y; la[len] = dq[x]; dq[x] = len; }
void dfs(int x,int fa)
{
	int al = 0;
	for(int jz=dq[x];jz;jz=la[jz])
	{
		if(d[jz]==fa) continue;
		dfs(d[jz],x);
	}
	if(zt[x]!=-1)
	{
	
	for(int jz=dq[x];jz;jz=la[jz])
	{
		if(d[jz]==fa) continue;
		if(zt[d[jz]]==1) al += f[d[jz]][1]; else
		if(zt[d[jz]]==-1) al += f[d[jz]][0]; else
		al += min(f[d[jz]][0],f[d[jz]][1]);
	} f[x][1] = a[x]+al; 
	}
	if(zt[x]!=1)
	{
	al = 0; bool bs = false; int b2 = 0;
	for(int jz=dq[x];jz;jz=la[jz])
	{
		if(d[jz]==fa) continue;
		if(zt[d[jz]]==1) bs = true,al += f[d[jz]][1],b2++;
		if(zt[d[jz]]==-1) al += f[d[jz]][0];else 
		{
			if(f[d[jz]][1]<=f[d[jz]][0]) b2++;
			al += min(f[d[jz]][0],f[d[jz]][1]);
		}
	} if(b2>0){ f[x][0] = al; return; }
	int cb = 2147483647;
	for(int jz=dq[x];jz;jz=la[jz])
	{
		if(d[jz]==fa) continue;
		if(zt[d[jz]]==-1) continue;
		cb = min(cb,f[d[jz]][1]-f[d[jz]][0]); b2++;
	} if(b2<=0) return;
	f[x][0] = al+cb;
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",o); int x = 0,y = 0;
	fup(i,1,n) scanf("%d",&a[i]);
	fup(i,1,n-1)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	while(m--)
	{
		zt[x] = zt[y] = 0;
		int d1,d2;
		scanf("%d%d",&x,&d1);
		scanf("%d%d",&y,&d2);
		if(d1) zt[x] = 1; else zt[x] = -1;
		if(d2) zt[y] = 1; else zt[y] = -1;
		memset(f,0,sizeof(f)); dfs(1,0);
		int ans;
		if(f[1][0]>0&&f[1][0]<f[1][1]||f[1][1]==0) ans = f[1][0];
			else ans = f[1][1];
		if(ans==0) ans = -1;
		printf("%d\n",ans);
	}
	return 0;
}

