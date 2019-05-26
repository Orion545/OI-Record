#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 100005, MAX_d = 10005, INF = 0x3f3f3f3f;
int n, a[MAX_N], pre[MAX_N], cnt, mx=-INF;
bool processed[MAX_N];
//每个联通块的当前值等于他祖先的值 

int find(int k){
	if (pre[k] == k) return k;
	return pre[k] = find(pre[k]);
}

void join(int x, int y){
	int fx = find(x), fy = find(y);
	if (fx != fy) pre[fx] = fy;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
	for (int i = 1; i <= n; i++) pre[i] = i;
	for (int i = 1; i <= n; i++) mx = max(mx,a[i]);
//	cout<<"mx = "<<mx<<endl;
	for (int i = mx; i >= 1; i--){
		for (int j = 2; j <= n; j++){
			if (a[j] == a[j-1] && find(j) != find(j-1)) join(j,j-1); //更新联通块 
		}
//		for (int j = 1; j <= n; j++){
//			printf("i = %d, find(%d) = %d\n",i,j,find(j));
//		}
		for (int j = 1; j <= n; j++){
//			if (!processed[find(j)] && a[j] == i){ //标记本轮未处理的联通块 
//				cnt++;
//				processed[j] = true;
//				a[j]--;
//			} else if (a[j] == i){ //大小--，下次继续。 
//				a[j]--;
//			}
			if (a[j] == i){
				if (!processed[find(j)]){
					cnt++;
					processed[j] = true;
				}
				a[j]--;
			}
		}
		memset(processed,0,sizeof(processed));
	}
	printf("%d",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
