#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define fo(i,j,k) for(int i=j;i<=k;++i)
#define fd(i,j,k) for(int i=j;i>=k;--i)
using namespace std;
const int N=25e3+10;
int a[110];
int n;
bool f[N];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int mx=0;
		scanf("%d",&n);
		fo(i,1,n) scanf("%d",&a[i]),mx=max(mx,a[i]);
		sort(a+1,a+n+1);
		int ans=0;
		memset(f,0,sizeof(f));
		f[0]=1;
		fo(i,1,n){
			if(!f[a[i]]){
				ans++;
				fo(j,1,mx) if(j>=a[i]) f[j]|=f[j-a[i]]; 
			}
		}
		printf("%d\n",ans);
	}
}
