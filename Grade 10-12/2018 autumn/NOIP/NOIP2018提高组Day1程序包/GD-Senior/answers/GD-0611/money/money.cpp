#include<cstring>
#include<cstdio>
#define fo(i,a,b) for(int i=a,_E_=b;i<=_E_;++i)
#define REP(i,a,b) for(int i=a,_E_=b;i<_E_;++i)
#define min(a,b) (a<b?a:b)
using namespace std;

int n,ans,a[110],t,c[30000];
void swap(int &a,int &b){int t=a;a=b;b=t;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;scanf("%d",&n);
		fo(i,1,n)scanf("%d",a+i);
		fo(i,1,n)fo(j,i+1,n)if(a[i]>a[j])swap(a[i],a[j]);
		REP(i,0,a[1])c[i]=1e9;c[0]=0;
		fo(i,2,n){
			if(c[a[i]%a[1]]<=a[i])continue;
			++ans;
			int k=gcd(a[i],a[1]);
			REP(j,0,k){
				int p=j;
				REP(l,1,a[1]/k)if(c[l*k%a[1]+j]<c[p])p=l*k%a[1]+j;
				fo(l,1,a[1]/k){
					int x=(p+(l-1)*a[i])%a[1],y=(p+l*a[i])%a[1];
					c[y]=min(c[y],c[x]+a[i]);
				}
			}
		}
		printf("%d\n",ans+1);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
