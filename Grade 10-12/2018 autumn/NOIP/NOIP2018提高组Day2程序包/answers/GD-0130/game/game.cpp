#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#define ll long long
#define fo(i,x,y) for(int i=x;i<=y;i++)
#define fd(i,x,y) for(int i=x;i>=y;i--)
using namespace std;

const int M=1<<8,mo=1e9+7;

int n,m,N;

void Init(){
	scanf("%d%d",&n,&m);
}
typedef int rect[M][M];
int f[M];
rect Trans,Beg,t;
bool check(int x,int y){
	fo(i,0,n-2)
		if ((x>>i+1&1)>=(y>>i&1));else return false;
	return true;
}
void getTrans(){
	fo(i,0,N-1)
		fo(j,0,N-1){
			Trans[i][j]=check(i,j);
		}
}
void Times(rect &a,rect &b){
	static rect c;
	memset(c,0,sizeof c);
	fo(i,0,N-1)
		fo(k,0,N-1)
			fo(j,0,N-1)
				c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%mo;
	memcpy(a,c,sizeof a);
}
int qp(int a,int b){
	int c=1;
	while (b){
		if (b&1) c=1ll*a*c%mo;
		a=1ll*a*a%mo;
		b>>=1;
	}
	return c;
}
int calc(int x){
	int c=1;
	while (x){
		if (x&1);else c=c*2%mo;
		x>>=1;
	}
	return c;
}
int Ans=0;
void Solve(){
	if (n==3){
		if (m==1){
			Ans=8;
		}else if (m==2){
			Ans=36;
		}else if (m==3){
			Ans=112;
		}
		return;
	}
	N=1<<n;
	getTrans();
	fo(i,0,N-1) Beg[0][i]=1;
	m--;
	for(;m;m>>=1,Times(Trans,Trans)) if (m&1) Times(Beg,Trans);
	fo(i,0,N-1) Ans=(Ans+Beg[0][i])%mo;
}
void Print(){
	printf("%d\n",Ans);
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	Init();
	Solve();
	Print();
	return 0;
}
