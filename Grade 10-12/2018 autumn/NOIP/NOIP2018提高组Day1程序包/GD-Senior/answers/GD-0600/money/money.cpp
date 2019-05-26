#include <cstdio>
#include <cstring>
#include <iostream>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
const int maxN=110,maxn=25010;
bool bz[maxn];
int n,i,j,t,a[maxN],mx,ans,t1;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	mx=25000;
	for(scanf("%d",&t1);t1;t1--){
		scanf("%d",&n);
		fo(i,1,n) scanf("%d",&a[i]);
		fo(i,1,n){
			fo(j,i+1,n){
				if (a[j]<a[i])
					t=a[i],a[i]=a[j],a[j]=t;
			}
		}
		memset(bz,false,sizeof(bz));
		ans=0;
		bz[0]=true;	
		fo(i,1,n){
			if (bz[a[i]]) continue;
			fo(j,a[i],mx)
				bz[j]|=bz[j-a[i]];
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
