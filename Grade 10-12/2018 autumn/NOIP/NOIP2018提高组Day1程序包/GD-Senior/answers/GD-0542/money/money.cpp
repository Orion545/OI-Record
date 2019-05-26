#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x=0,f=1;
	char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int maxn=105;
const int maxw=25005;
int n,a[maxn],mx;
bool f[maxw];
int work() {
	int ret=0;
	mx=INT_MIN;
	n=read();
	for (int i=1;i<=n;++i) mx=max(mx,a[i]=read());
	fill(f,f+mx+1,false),f[0]=true;
	sort(a+1,a+n+1);
	for (int i=1;i<=n;++i) if (!f[a[i]]) {
		++ret;
		int x=a[i];
		for (int j=x;j<=mx;++j) f[j]|=f[j-x];
	}
	return ret;
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	for (int T=read();T--;) printf("%d\n",work());
	return 0;
}
