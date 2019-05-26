#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=100005;
LL n,m;
char ss[5];
struct qq
{
	LL x,y,last;
}e[N*2];LL num,last[N];
LL p[N];
void init (LL x,LL y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
LL A,X,B,Y;
LL f[N][2];//自己放了  自己没放 
//-1:不合法   否则，最小代价 
LL _min (LL x,LL y)
{
	if (x==-1) return y;
	if (y==-1) return x;
	return x<y?x:y;
}
void dfs (LL x,LL fa)
{
	bool ok=false,ok1=false;
	LL cnt1=0,cnt2=0;
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		if (y==fa) continue;
		dfs(y,x);
		LL t;
		t=_min(f[y][0],f[y][1]);
		if (t==-1) ok=true;
		cnt1=cnt1+t;
		t=f[y][0];
		if (t==-1) ok1=true;
		cnt2=cnt2+t;
	}
	if (ok) f[x][0]=-1;
	else f[x][0]=cnt1+p[x];
	if (ok1) f[x][1]=-1;
	else f[x][1]=cnt2; 
	if (A==x)
	{
		if (X==0) f[x][0]=-1;
		else f[x][1]=-1;
	}
	if (B==x)
	{
		if (Y==0) f[x][0]=-1;
		else f[x][1]=-1;
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	num=0;memset(last,-1,sizeof(last));
	scanf("%lld%lld%s",&n,&m,ss+1);
	for (LL u=1;u<=n;u++) scanf("%lld",&p[u]);
	for (LL u=1;u<n;u++)
	{
		LL x,y;
		scanf("%lld%lld",&x,&y);
		init(x,y);init(y,x);
	}
	for (LL u=1;u<=m;u++)
	{
		scanf("%lld%lld%lld%lld",&A,&X,&B,&Y);
		dfs(1,0);
		printf("%lld\n",_min(f[1][0],f[1][1]));
	}
	return 0;
}
