#include <iostream>
#include <cstdio>
using namespace std;

int n;
int map[100005];//[1,n+1]
int low = 1e9;
int sum;
int ans;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d",&n);
	int t1;
	for(int i = 1;i <= n;i++){
		scanf("%d",&t1);
		map[i] = t1;
		sum += t1;
	}
	
	int left,right,l;
	while(sum){
		left = 0;
		right = 0;
		for(int i = 0;i <= n+1;i++){
			if(!left) {
				if(map[i]) {
					left = i;
					l = map[i];
				}
			} else {
				if(!map[i]){
					right = i-1;
					for(int j = left;j <= right;j++){
						map[j] -= l;
					}
					sum -= (right-left+1)*l;
					ans += l;
					left = right = 0;
				}else{
					if(map[i] < l) l = map[i];
				}
			}
		}
	}
	cout << ans;
}
