#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define max(a,b)(a>b?a:b)
#define ll long long
using namespace std;
const int N=1e5+5;
int t,n,a[N],ma,ans;
bool f[N];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	f[0]=1;
	for(scanf("%d",&t);t--;){
		scanf("%d",&n);ans=ma=0;
		fo(i,1,n)scanf("%d",&a[i]),ma=max(ma,a[i]);
		sort(a+1,a+n+1);
		fo(i,1,n)if(!f[a[i]]){
			ans++;
			fo(j,a[i],ma)f[j]|=f[j-a[i]];
		}
		printf("%d\n",ans);
		fo(i,1,ma)f[i]=0;
	}
	fclose(stdin);fclose(stdout);return 0;
}
