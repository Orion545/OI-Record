#include<cstdio>
using namespace std;

inline int read() {
	int x=0, f=1; char ch=getchar();
	for(; ch<'0'||ch>'9'; ch=getchar()) if(ch=='-') f=-1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int n=read(), ans=0;
	for(int i=1, pre=0, now; i<=n; i++) {
		now=read();
		if(now>pre) ans+=now-pre;
		pre=now;
	}
	printf("%d", ans);
	
	fclose(stdin); fclose(stdout);
	return 0;
}
