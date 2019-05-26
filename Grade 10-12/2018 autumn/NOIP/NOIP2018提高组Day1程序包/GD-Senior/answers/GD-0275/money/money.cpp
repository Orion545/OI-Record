#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int t,n,a[105],prime[25005],v[25005];
int  num;
int read(){
	int a = 0;
	char ch = getchar();
	while (ch <'0'||ch>'9')ch = getchar();
	while (ch <= '9' && ch >= '0'){
		a = (a<<1) + (a<<3) + ch - '0';
		ch = getchar();
	}
	return a;
}
void getprime(){
	for(int i = 1;i <= 25000;++i){
		if (!v[i]){
			v[i] = i;
			prime[+num] = i;
		}
		for (int j = 1;j <= 25000;++j){
			if (j >= v[i]||j >= n/i)break;
			v[j] = i;
		}
	}
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t = read();
	getprime();
	while (t){
		int ans = 0;
		n = read();
		for (int i = 1;i <= n;++i)
			a[i] = read();
		
		for (int i = 1;i <= n;++i)
			if(v[a[i]] == a[i]) ++ ans;
		
		printf("%d\n",ans);
		--t;
	}


	return 0;
}

