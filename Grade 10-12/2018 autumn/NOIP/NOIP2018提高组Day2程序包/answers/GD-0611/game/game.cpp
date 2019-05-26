#include<cstring>
#include<cstdio>
#define mo 1000000007
#define N 1001000
#define fo(i,a,b) for(int i=a,_E_=b;i<=_E_;++i)
#define REP(i,a,b) for(int i=a,_E_=b;i<_E_;++i)
#define max(a,b) (a>b?a:b)
using namespace std;
int n,m,f[N][3];
void swap(int &a,int &b){int t=a;a=b;b=t;}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(n>m)swap(n,m);
	int ans=1;
	if(n==1){
		fo(i,1,m)ans=2ll*ans%mo;printf("%d",ans);
	}else{
		ans=0;
		int a=4;
		fo(i,3,n)a=4ll*a%mo;
		fo(i,n+1,m)a=3ll*a%mo;
		fo(i,m+1,n+m-1)a=2ll*a%mo;
		ans=(ans+a)%mo;
		if(n>=3){
			if(n>3){
				a=20;
				fo(i,5,n)a=4ll*a%mo;
			}else a=12;
			fo(i,max(5,n+1),m)a=3ll*a%mo;
			fo(i,max(5,m+1),n+m-1)a=2ll*a%mo;
			ans=(ans+a)%mo;
			f[3][0]=1;
			fo(i,4,n){
				f[i][2]=(4ll*f[i-1][2]+5ll*f[i-1][1])%mo;
				f[i][1]=4ll*f[i-1][0]%mo;
				f[i][0]=f[i-1][0];
			}
			if(n==m){
				a=2ll*(3ll*(f[n][0]+f[n][1])+2ll*f[n][2])%mo;
			}else{
				a=2ll*(4ll*(f[n][0]+f[n][1])+3ll*f[n][2])%mo;
			}
			fo(i,n+2,m)a=3ll*a%mo;
			fo(i,max(n+2,m+1),n+m-1)a=2ll*a%mo;	
			ans=(ans+a)%mo;
			memset(f,0,sizeof f);
			f[3][0]=1;
			fo(i,4,n){
				f[i][2]=(4ll*f[i-1][2]+5ll*f[i-1][1])%mo;
				f[i][1]=4ll*f[i-1][0]%mo;
				f[i][0]=f[i-1][0];
			}
			fo(i,n+1,m){
				f[i][2]=(3ll*f[i-1][2]+4ll*f[i-1][1])%mo;
				f[i][1]=3ll*f[i-1][0]%mo;
				f[i][0]=f[i-1][0];
			}
			a=2ll*(3ll*(f[m][0]+f[m][1])+2ll*f[m][2])%mo;
			fo(i,m+2,n+m-1)a=2ll*a%mo;
			ans=(ans+a)%mo;
		}else{
			a=4;
			fo(i,3,m)a=3ll*a%mo;
			ans=(ans+a)%mo;
		}
		printf("%d",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
