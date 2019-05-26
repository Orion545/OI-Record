#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 110
using namespace std;
int T,n,m,f[30010],v[N];
int _18520(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",v+i);
	sort(v+1,v+1+n); m=v[n];
	memset(f,0,sizeof f); f[0]=1; 
	int ans=n;
	for(int i=1;i<=n;++i){
		if(f[v[i]]) --ans;
		else for(int j=0;j+v[i]<=m;++j) f[j+v[i]]|=f[j];
	}
	printf("%d\n",ans);
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--) _18520();
	return 0;
}
