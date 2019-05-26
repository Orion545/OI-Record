#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,now,lst,ans;
inline int read() {
	int tmp=0, fh=1; char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') fh=-1; c=getchar();}
	while (c>='0'&&c<='9') tmp=tmp*10+c-48, c=getchar();
	return tmp*fh;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) {
		now=read(); ans+=max(now-lst,0); lst=now;
	}
	printf("%d\n",ans);
	return 0;
}
