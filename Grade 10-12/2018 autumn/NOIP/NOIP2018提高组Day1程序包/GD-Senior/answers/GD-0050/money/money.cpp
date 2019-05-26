#include<cstdio>
#include<iostream>
#include<cstring>
#define maxn 110
#define maxm 25010
using namespace std;
const int INF=1e9;
int T,n,ans;
int a[maxn],b[maxn];
struct Moon{
	bool ans,exist;
}f[maxm];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	int i,j,ma,mi;
	while(T--){
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		mi=INF,ma=0,ans=n;
		for (i=1;i<=n;++i){
			scanf("%d",&a[i]);
			ma=max(ma,a[i]),mi=min(mi,a[i]);
			f[a[i]].exist=1;
		}
		for (i=1;i<=ma-mi;++i)
			if(f[i].exist)
				for (j=1;j<=n;++j) f[i+a[j]]={1,1};
		for (i=1;i<=n;++i) if(f[a[i]].ans) ans--;
		printf("%d\n",ans);
	}
}
