#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>

using namespace std;

const int MAX_N = 105, MAX_a = 25005;
int t,n,cnt;
bool cnted[MAX_a],a[MAX_N];

int gcd(int AAAA, int BBBB){
	if(BBBB) return gcd(BBBB,AAAA%BBBB);
	return AAAA;
}

// 1. gcd == 其中一个数，删除。 
// 2. 一个数模大数后能整除另外一个数，删除。 

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t){
		t--;
		cnt = n;
		scanf("%d",&n);
		for (int i = 1; i <= n; i++){
			scanf("%d",a[i]);
		}
		if (n == 2){
			if (gcd(a[1],a[2]) == a[1] || gcd(a[1],a[2]) == a[2]){
				printf("%d\n",1);
				continue;
			} else{
				printf("%d\n",2);
				continue;
			}
		} else if (n == 3){
			if (gcd(a[1],a[2]) == a[3] || gcd(a[1],a[3]) == a[2] || gcd(a[2],a[3]) == a[1]){
				printf("%d\n",3);
			}
		} else{
			printf("%d\n",n);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
