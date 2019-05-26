#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
const int maxn=100+10,mx=25000;
int a[maxn];
bool f[mx+10];
int i,j,k,l,t,n,m,ca;
int main(){
	freopen("money.in","r",stdin);freopen("money.out","w",stdout);
	scanf("%d",&ca);
	while (ca--){
		scanf("%d",&n);
		fo(i,1,n) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		fo(i,1,mx) f[i]=0;
		f[0]=1;
		m=0;
		fo(i,1,n){
			if (!f[a[i]]){
				a[++m]=a[i];
				fo(j,0,mx-a[i]) f[j+a[i]]|=f[j];
			}
		}
		printf("%d\n",m);
	}
	return 0;
}
