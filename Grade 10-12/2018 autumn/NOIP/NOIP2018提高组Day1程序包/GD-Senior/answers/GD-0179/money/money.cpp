#include <iostream>
#include <cstring>
#include <cstdio>
#define maxn 105
using namespace std;
int a[maxn], t , n, ans;
int main (){
	freopen("money.in","r",stdin);
	freopen("money.out","r",stdout);
	scanf("%d",&t);
	while(t > 0){
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		bool test = false;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i] == 1){
				printf("1\n");
				test = true;
				break;
			}
		}
		if(!test){
			printf("%d",n);
		}
		t--;
	}
	return 0;
}
