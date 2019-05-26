#include<cstdio>
#include<cstring>
#define fo(i,x,y) for(int i=x;i<=y;i++)
#define min(a,b) ((a)<(b)) ? (a):(b)
using namespace std;
const int N=105,M=25034;
int f[M],a[N],da[M],n,m,t,ans,mm,nn,b[N];
bool bz[M];
void bfs(int x){
	int h=0,t=1; da[1]=0; bz[0]=1; int y; f[0]=0;
	while (h<t) {
		x=da[++h]; bz[x]=0;
		fo(i,1,n) {
//			if (a[i]==m) continue; 
			y=(a[i]+x)%m;
			if (f[y]>f[x]+a[i]) {
				f[y]=f[x]+a[i];
				if (!bz[y]) bz[y]=1,da[++t]=y;
			}
			
		}
	}
	
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while (t) {
		scanf("%d",&n); t--; m=M; ans=0;
		fo(i,1,n) scanf("%d",&a[i]),m=min(m,a[i]);
		while (n) {
			memset(bz,0,sizeof(bz));
			memset(f,50,sizeof(f));
			bfs(0); nn=0; 
			fo(i,1,n) if (f[(a[i])%m]==a[i]) b[++nn]=a[i];
			m=M; 
			fo(i,1,nn) a[i]=b[i],m=min(m,a[i]); n=nn; ans++;
		}
		printf("%d\n",ans);
	}
}
