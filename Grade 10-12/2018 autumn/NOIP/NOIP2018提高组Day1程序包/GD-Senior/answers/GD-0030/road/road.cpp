#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define N 100005
using namespace std;

typedef long long ll;
ll cnt=0ll;
int i,j,k;
ll n,a[N],dou[21],dui[N],f[N][21];

ll gi()
{
	ll res,w=1ll;
	char ch;
	while(ch=getchar(),ch<'0'||ch>'9')if(ch=='-')w=-1ll;
	res=ch-48ll;
	while(ch=getchar(),ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+ch-48ll;
	return res*w;
}
void dfs(ll l,ll r,ll alr)
{
	if(l>r)return;
	if(l==r){
		cnt+=a[l];
		return;
	}
	ll t=dui[r-l+1ll],minn=min(f[l][t],f[r-dou[t]+1ll][t])-alr,j=l,lc=l;
	cnt+=minn;
	while(j<=r){
		a[j]-=minn;
		if(a[j]==0ll){
			dfs(lc,j-1ll,minn+alr);
			lc=j+1ll;
		}
		j++;
	}
	if(lc<=r)dfs(lc,r,minn+alr);
	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=gi();
	dui[0]=-1ll;
	for(i=1;i<=n;i++){
		a[i]=gi();
		dui[i]=dui[(i>>1)]+1ll;
		f[i][0]=a[i];
	}
	dou[0]=1ll;
	for(i=1;i<=20;i++)dou[i]=dou[i-1]<<1;
	for(j=1;j<=20;j++){
		for(i=1;i<=n;i++){
			if(i+(1<<j)-1>n)break;
			f[i][j]=min(f[i][j-1],f[i+dou[j-1]][j-1]);
		}
	}
	dfs(1ll,n,0);
	printf("%lld",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
