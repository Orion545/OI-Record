#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,ans=0,b[maxn],top=0;
void push(int x) {
	for (;top && b[top]>=x;--top) {
		int tmp=max(b[top-1],x);
		ans+=b[top]-tmp;
	}
	b[++top]=x;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(b,0,sizeof b);
	scanf("%d",&n);
	for (int i=1;i<=n;++i) {
		int x;
		scanf("%d",&x);
		push(x);
	}
	push(0);
	printf("%d\n",ans);
	return 0;
}
