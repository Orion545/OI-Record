#include<stdio.h>
#include<string.h>
#include<algorithm>
#define M 1000000007
using namespace std;
int n,m,f[2][10][1<<10];
int p[9][1000010],v[9][1000010];
inline void ad(int& x,int y){
	x=(x+y)%M;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	swap(n,m);
	f[0][0][0]=1;
	f[0][1][0]=1;
	int t=n+m;
	for(int i=2;i<t;++i){
		for(int j=0;j<=m;++j)
			for(int S=0;S<(1<<m);++S)
				if(f[0][j][S]){
					int st=max(1,i-n),len=min(i,m)-st+1,c=0;
					for(int k=max(1,i-n);k<=i && k<=m;++k){
						p[k][i-k]=(S>>c)&1;
						v[k][i-k]=(k-st+1)>(len-j); ++c;
					}
					int st2=max(1,i+1-n),l=min(i+1,m)-st2+1,T=0;c=0;
					for(int k=st2;k<i+1 && k<=m;++k){
						p[k][i+1-k]=p[k-1][i+1-k]|p[k][i-k];
						if(k>1 && (i-k)>0) p[k][i+1-k]|=(v[k-1][i+1-k]==v[k][i-k]);
						T|=(p[k][i+1-k])<<c; ++c;
					}
					ad(f[1][l-1][T],f[0][j][S]); c=0;
					for(int k=st2;k<i+1 && k<=m;++k){
						if(!p[k-1][i+1-k]||c==0) ad(f[1][c][T],f[0][j][S]);
						++c;
					}
				}
		for(int j=0;j<=m;++j)
			for(int S=0;S<(1<<m);++S){ f[0][j][S]=f[1][j][S]; f[1][j][S]=0; }
	}
	printf("%lld\n",((long long)f[0][1][1]+f[0][1][0]+f[0][0][1]+f[0][0][0])%M);
}
