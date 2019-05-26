#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

bool vi[25010];
int a[110],n,he,ans,T;

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	scanf("%d",&T);
	for (int t=1;t<=T;++t) {
		scanf("%d",&n);
		for (int i=1;i<=n;++i) scanf("%d",&a[i]);
		a[n+1]=26000;
		for (register int i=1;i<=25000;++i) 
		vi[i]=0;
		sort(a+1,a+1+n);
		he=0;ans=n;
		for (register int i=1;i<=25000;++i) {
			for (int j=1;j<=he;++j)
			if (vi[i-a[j]]) {vi[i]=1;break;}
			while (i==a[he+1]) {
				++he;
				if (vi[i]) --ans;
				else vi[i]=1;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
