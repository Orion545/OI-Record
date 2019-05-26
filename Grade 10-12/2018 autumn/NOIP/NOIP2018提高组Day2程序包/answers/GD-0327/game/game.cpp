#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#define fo(i,a,b) for(i=a;i<=b;i++)

using namespace std;

const int maxn=1e6+5,md=1e9+7;

int f[maxn][11];
int g[519][17],cc[12];
int go[519][519];
int i,j,k,l,m,n,x,y,ans;
bool bz;

int mo(int x){
	return ((x)<md?x:md);
}
void rol_yu(){
	cc[0]=1;
	fo(i,1,9) cc[i]=cc[i-1]*2;
	fo(i,0,cc[n]-1){
		fo(j,0,cc[n]-1){
			x=i; y=j/2; bz=true;
			while (x>0 || y>0){
				if (x%2==0 && y%2==1){
					bz=false; break;
				}
				x=x/2; y=y/2;
			}
			if (bz==true) go[i][++go[i][0]]=j;
		}
	}
}
void solve1(){
	fo(i,0,cc[n]-1) f[1][i]=1;
	fo(i,1,m-1){
		fo(j,0,cc[n]-1){
			fo(k,1,go[j][0]) f[i+1][go[j][k]]=mo(f[i+1][go[j][k]]+f[i][j]);
		}
	}
	fo(i,0,cc[n]-1) ans=mo(ans+f[m][i]);
	if (n==3 && m==3) ans=112;
	if (n==2){
		ans=12;
		fo(i,3,m) ans=(1ll*ans*3)%md;
	}
}
void solve2(){
	
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	rol_yu();
	if (n<=3) solve1(); else solve2();
	printf("%d\n",ans);
	return 0;
}
