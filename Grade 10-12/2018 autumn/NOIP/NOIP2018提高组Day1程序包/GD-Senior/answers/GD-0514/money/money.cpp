#include<bits/stdc++.h>
#define N 205
using namespace std;
typedef long long ll;
int T,n,a[N],b[N],tmp,f[N],g,ans,top;
int r[28000],id[28000];
ll X,Y,Z;
inline ll gcd(ll x,ll y){
	if (!y) return x;
	return gcd(y,x%y);
}
int main(){
	freopen("money.in","r",stdin),freopen("money.out","w",stdout);
	scanf("%d",&T);
	for (int _=1;_<=T;_++){
		memset(f,0,sizeof(f));
		memset(r,0,sizeof(r));
		memset(id,0,sizeof(id));
		ans=0;
		
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		b[top=1]=a[1];
		for (int i=2;i<=n;i++) if (a[i]!=a[i-1]) b[++top]=a[i];
		for (int i=1;i<=top;i++) id[b[i]]=i;

		for (int i=1;i<=25000;i++){
			if (id[i]) r[i]=1;
			if (!r[i]) continue;
			for (int j=1;j<=top;j++) if (b[j]<=i&&i+b[j]<=25000){
				r[i+b[j]]=1;
				if (id[i+b[j]]) f[id[i+b[j]]]=1;
			}
			if (!id[i]) continue;
			for (int j=id[i]-1;j>=1;j--){
				g=gcd(b[j],b[id[i]]);
				X=b[j]/g,Y=b[id[i]]/g;
				Z=X*Y-X-Y;
				for (int k=id[i]+1;k<=top;k++) if (b[k]%g==0&&b[k]/g>Z) f[k]=1;
			}
		}
		for (int i=1;i<=top;i++) if (!f[i]) ans++;
		printf("%d\n",ans);
	}
}
