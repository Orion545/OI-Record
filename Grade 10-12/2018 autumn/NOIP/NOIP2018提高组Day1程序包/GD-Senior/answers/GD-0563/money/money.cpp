#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n;
#define Maxn 105
int a[Maxn];
bool ok[25005];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(ok,false,sizeof(ok));
		int maxv=0,Ans=0;
		scanf("%d",&n);
		for(register int i=1;i<=n;++i)scanf("%d",&a[i]),maxv=max(maxv,a[i]);
		sort(a+1,a+n+1);
		n=unique(a+1,a+n+1)-a-1;
		ok[0]=true;
		for(register int i=1;i<=n;++i)
		if(!ok[a[i]]){
			Ans++;
			for(register int j=a[i];j<=maxv;++j)ok[j]|=ok[j-a[i]];
		}
		printf("%d\n",Ans);
	}
	return 0;
}
