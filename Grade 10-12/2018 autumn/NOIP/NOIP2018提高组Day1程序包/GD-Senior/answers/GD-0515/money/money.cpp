#include<iostream>
#include<stdio.h>
#include<string.h>
#define N 27000
using namespace std;
bool p[N],q[N];
int a[N],prime[120],tot,n,o;
int solve(){
	scanf("%d",&n);
	tot=0,o=0;
	memset(p,0,sizeof(p));
	memset(q,0,sizeof(q));
	memset(a,0,sizeof(a));
	memset(prime,0,sizeof(prime));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),o=max(o,a[i]),q[a[i]]=1;
	for(int i=1;i<=o;i++){
		for(int j=1;j<=tot;j++){
			if(p[i-prime[j]]==1){
				p[i]=1;
				break;
			}
		}
		if(p[i]==0&&q[i]==1)prime[++tot]=i,p[i]=1;
	}
	printf("%d\n",tot);
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
