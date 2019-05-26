#include<cstdio>
#define fo(i,x,y) for(int i=x;i<=y;i++)
#define max(a,b) ((a)>(b)) ? (a):(b)
#define ll long long
using namespace std;
const int mo=1e9+7,M=1e6+7;
int n,m,e[M],a[6][6];
ll x,y,ans;
void dg(int x,int y){
	if (x>n) { ans++; return; }
	int xx,yy; xx=x; yy=y;
	if (y==1) xx++,yy=m; else yy--;
//	int k=max(a[x-1][y+1],a[x][y+1]);
	int k=a[x-1][y+1];
	if (x==3 && y==2) {
		a[x][y]=k; dg(xx,yy); return;
	}
	if (k==0) {
		a[x][y]=1; dg(xx,yy); a[x][y]=0; dg(xx,yy);
	} else a[x][y]=1,dg(xx,yy),a[x][y]=0;  
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	if (n==2) {
		e[0]=1; fo(i,1,m) e[i]=(e[i-1]+e[i-1])%mo; ans=1;
		fo(i,1,m-1) {
			ans=(ans+e[m-1-i]*e[m-i]%mo)%mo;
		} ans=(ans*4LL)%mo; printf("%lld\n",ans); return 0;
	}
	if (n<=8 && m<=8) {
		dg(1,m); printf("%lld\n",ans); return 0;
	} 
}
