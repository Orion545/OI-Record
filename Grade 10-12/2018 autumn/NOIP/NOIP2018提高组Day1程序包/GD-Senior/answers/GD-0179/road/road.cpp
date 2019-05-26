#include <iostream>
#include <cstring>
#include <cstdio>
#define maxn 100005
#define min(x,y) x < y ? x : y
using namespace std;
int n, ans = 0;
int road[maxn];
int main (){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	memset(road,0,sizeof(road));
	for(int i=1;i<=n;i++){
		scanf("%d",&road[i]);
	}
	bool temp = true;
	while(temp){
		temp = false;
		int cnt = 1;
		while(cnt <= n){
			if(road[cnt]!= 0){
				temp = true;
				int tmp = cnt;
				int minn = 1000000;
				while(road[cnt]!=0){
					minn = min(minn,road[cnt]);
					cnt ++;
				}
				while(tmp < cnt)road[tmp++] -= minn;
				ans += minn;
				break;
			}
			cnt++;
		}
	}
	printf("%d",ans);
	return 0;
}
