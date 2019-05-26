#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
using namespace std;
int i,j,k,t,n,a[1001];
int main(){
//	freopen("money.in","r",stdin);
//	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&n);
		for(j=1;j<=n;j++){
			scanf("%d",&a[j]);
		}
		sort(a+1,a+n+1);
	}
	
	
	
	return 0;
}
