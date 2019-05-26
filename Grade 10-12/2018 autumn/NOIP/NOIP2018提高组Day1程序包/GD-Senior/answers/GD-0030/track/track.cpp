#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define ri register int
#define N 50005
#define M 100005
using namespace std;

int i,j,k,n,m,l,r,h,hd[N],p=1,md,tot,maxx=500000,maxn,dp[N];
struct node{
	int t,nxt,w;
}e[M];

int gi()
{
	int res,w=1;
	char ch;
	while(ch=getchar(),ch<'0'||ch>'9')if(ch=='-')w=-1;
	res=ch-48;
	while(ch=getchar(),ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+ch-48;
	return res*w;
}
void ad(int x,int y,int w){
	e[++tot].t=y;
	e[tot].nxt=hd[x];
	e[tot].w=w;
	hd[x]=tot;
}
void dfs(int x,int fa){
	int arr;
	for(ri i=hd[x];i;i=e[i].nxt){
		arr=e[i].t;
		if(arr==fa)continue;
		dp[arr]=dp[x]+e[i].w;
		dfs(arr,x);
	}
}
int ok(int x){
	int cnt=0,j,tmp=0;
	for(ri i=1;i<=n;i++){
		j=hd[i];
		tmp+=e[i].w;
		if(tmp>=x){
			cnt++;
			tmp=0;
		}
		if(cnt>=m)return 1;
	}
	return 0;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=gi(),m=gi();
	for(ri i=1;i<n;i++){
		j=gi(),k=gi(),l=gi();
		if(k-j!=1)p=0;
		maxx=min(maxx,l);
		ad(j,k,l);
		ad(k,j,l);
	}
	if(n-m==1){
		printf("%d",maxx);
		return 0;
	}
	dp[0]=0;
	dfs(1,0);
	maxx=h=0;
	for(ri i=1;i<=n;i++){
		if(dp[i]>maxx){
			maxx=dp[i];
			maxn=i;
		}
	}
	memset(dp,0,sizeof(dp));
	dfs(maxn,0);
	for(ri i=1;i<=n;i++){
		h=max(h,dp[i]);
	}
	if(m==1){
		printf("%d",h);
	}
	else{
		if(p){
			while(l<r){
			
			l=1;r=10010;
			md=(l+r)>>1;
			if(ok(md)){
				r=md;
			}
			else l=md+1;
		}
			printf("%d\n",r);
		}
		printf("%d",h-maxx);
	}
	return 0;
}
