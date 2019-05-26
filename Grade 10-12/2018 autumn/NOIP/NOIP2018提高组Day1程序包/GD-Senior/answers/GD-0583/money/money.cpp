#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int a[110],ok;
void  ky(int x,int j){
	for(int u=j;u>=1;u--){
		if(a[u]==x||x%a[u]==0){
			ok=1;
			return ;
		}
		if(a[u]<x){
			ky(x-a[u],u);
		}
	}
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		int tot=n;
		for(int i=n;i>=2;i--){
			ok=0;
			ky(a[i],i-1);
			if(ok)tot--;
		}
		printf("%d\n",tot);
	}
	return 0;
}
