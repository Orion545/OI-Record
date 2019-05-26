#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
const int N=1e2+10;
const int mx=2.5e4+10;
int n,t,a[N],ans,mxa;
bool b[mx],f[mx];

void Do(int a,int c) {
	for (int i=1;i<=mxa/a;i++) b[c+a*i]=1;
}

int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);mxa=0;
		for (int i=1;i<=n;++i) scanf("%d",&a[i]),mxa=max(a[i],mxa);
		sort(a+1,a+n+1);n=unique(a+1,a+n+1)-a-1;
		memset(b,0,sizeof b);memset(f,0,sizeof f);
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
				Do(a[i],a[j]);
		ans=n;
		for (int i=1;i<=mxa;++i)
			if (b[i])
				for (int j=1;j<=n;++j) {
					if (!b[a[j]])
						Do(a[j],i);
					else !f[a[j]]?ans--:ans,f[a[j]]=1;
				}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
