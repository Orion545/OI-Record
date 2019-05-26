#include<cstdio>
#include<algorithm>
#include<cstring>
#define fo(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)
using namespace std;
const int N=105;
const int M=25000;
int a[N],n,ans,T,mx,cnt;
bool bz[M+255];
bool p;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		memset(bz,0,sizeof(bz));
		bz[0]=1;
		scanf("%d",&n);
		ans=n;
		fo(i,1,n) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		mx=a[n];
		fo(i,1,n){
			p=1;
			if (bz[a[i]]) {
				p=0;
				ans--;
				continue;
			}
			if (p){
				fo(j,0,mx)	
					fo(k,1,mx/a[i])
						if (bz[j]&&j+k*a[i]<=mx)	
						bz[j+k*a[i]]=1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;	
}






