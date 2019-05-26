#include <bits/stdc++.h>

using namespace std;

bool f[30005];
int num[105];

int main() {
  freopen("money.in","r",stdin);
  freopen("money.out","w",stdout);
  int cases;
  scanf("%d",&cases);
  for(;cases;cases--) {
  	memset(f,0,sizeof(f));
  	int n;
  	scanf("%d",&n);
  	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
  	sort(num+1,num+n+1);
  	int ans=0,maxn=num[n];
  	f[0]=1;
  	for(int i=1;i<=n;i++) {
  		int x=num[i];
  		if (f[x]) continue;
  		ans++;
  		for(int j=x;j<=maxn;j++) f[j]|=f[j-x];
  	}
  	printf("%d\n",ans);
  }
  return 0;
}
