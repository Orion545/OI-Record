#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

inline int read() {
	int x=0, f=1; char ch=getchar();
	for(; ch<'0'||ch>'9'; ch=getchar()) if(ch=='-') f=-1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

const int A=25000+5;
const int N=100+5;

int a[N], f[A];

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);

	int TTT=read();
	for(int n, ans; TTT--; ) {
		n=read();
		for(int i=1; i<=n; i++) a[i]=read();
		sort(a+1, a+n+1);
		memset(f, 0, sizeof(f));
		f[0]=1;
		ans=0;
		for(int i=1; i<=n; i++) {
			if(!f[a[i]]) ans++;
			for(int j=0; j+a[i]<=a[n]; j++) f[j+a[i]]|=f[j];
		}
		printf("%d\n", ans);
	}

	fclose(stdin); fclose(stdout);
	return 0;
}

