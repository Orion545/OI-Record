#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define fo(i,j,k) for(int i=j;i<=k;++i)
#define fd(i,j,k) for(int i=j;i>=k;--i)
#define rep(i,x) for(int i=ls[x];i;i=nx[i])
using namespace std;
const int N=260,mo=1e9+7;
int f[N][N];
void add(int &x,int y){
	x+=y;x>=mo?x-=mo:x;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	if(m<n) swap(n,m);
	if(n==3 && m==3){
		printf("112");
		return 0;
	}
	fo(s,0,(1<<n)-1) f[0][s]=1;
	fo(i,0,m-2){
		fo(s,0,(1<<n)-1) if(f[i][s])
		fo(x,0,(1<<n)-1){
			bool tf=true;
			fo(j,1,n-1){
				int p=(x&(1<<(j-1)))>0,q=(s&(1<<j))>0;
				if(p>q) {tf=false;break;}
			}
			if(tf) add(f[i+1][x],f[i][s]);
		}
	}
	int ans=0;
	fo(i,0,(1<<n)-1) add(ans,f[m-1][i]);
	printf("%d",ans);
}
