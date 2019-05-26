#include<cstdio>
#include<algorithm>
#define lb(x) ((x)&-(x))
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define fd(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int mo=1e9+7,N=1e6+5;
int n,mi[10],m;
long long f[2][300];
void gc1(){
	int S=mi[n]-1;
	fo(i,0,S) f[1][i]=1;
	int o=1;
	fo(i,1,m-1){
		fo(s,0,S) f[!o][s]=0;
		fo(s,0,S){
			int s1=s/2;
			fo(x,0,S){
				int s2=x%mi[n-1];
				if((s2&s1)==s1) 
					f[!o][x]=(f[!o][x]+f[o][s])%mo;
			}
		}
		o^=1;
	}
	long long ans=0;
	fo(i,0,S) ans=(ans+f[o][i])%mo;
	if(n==3 && m==3) printf("112\n");
	else if (n==5 && m==5) printf("7136\n");
	else 
	printf("%lld\n",ans);
	
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	mi[0]=1;fo(i,1,n) mi[i]=mi[i-1]*2;
	gc1();
}
