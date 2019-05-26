#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=25010;
int f[N],a[N];
int n,m,T,cnt,mx;

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	scanf("%d",&T);
	for (int o=1;o<=T;++o){
		scanf("%d",&n);
		for (int i=1;i<=n;++i) scanf("%d",a+i);
		sort(a+1,a+1+n);
		mx=a[n];
		memset(f,0,sizeof(f));
		cnt=0; f[0]=1;
		for (int i=1;i<=n;++i){
			if (f[a[i]]==1) continue;
			++cnt;
			for (int j=0;j+a[i]<=mx;++j)
				f[j+a[i]]|=f[j];
		}
		printf("%d\n",cnt);
	}
}
