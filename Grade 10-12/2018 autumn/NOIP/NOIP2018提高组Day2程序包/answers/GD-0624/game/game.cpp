#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
#define rep(a,b,c) for (int a=b;a<=c;a++)
#define per(a,b,c) for (int a=b;a>=c;a--)
const int P=1000000007;
int n,m;
void work1(){
	LL ans=1;
	rep(i,1,m) ans=(ans*2)%P;
	int k=ans;
	printf("%d\n",k);
}
void work2(){
	LL ans=4;
	rep(i,2,m) ans=(ans*3)%P;
	int k=ans;
	printf("%d\n",k);
}
void work3(){
	LL ans=112;
	rep(i,1,n-3) ans=ans*3%P;
	int k=ans;
	printf("%d\n",k);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n>m) swap(n,m);
	if (n>3) return 0;
	if (n==1) work1(); else
	if (n==2) work2(); else
	work3();
	return 0;
}

