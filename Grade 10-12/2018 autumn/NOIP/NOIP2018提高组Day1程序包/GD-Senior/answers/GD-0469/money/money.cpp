#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=110,M=25100;
int T,n,a[N],cnt,mx;
bool f[M];
int rd() {
	int re=0; char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') re=re*10+ch-48,ch=getchar();
	return re;
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=rd();
	while (T--) {
		n=rd(); memset(f,0,sizeof f); cnt=0; mx=0;
		for (int i=1; i<=n; i++) a[i]=rd(),mx=max(mx,a[i]);
		sort(a+1,a+n+1); mx+=5; f[0]=1;
		for (int i=1; i<=n; i++) if (!f[a[i]]) {
			cnt++;
			for (int j=a[i]; j<=mx; j++) f[j]|=f[j-a[i]];
		}
		printf("%d\n",cnt);
	}
	return 0;
}
