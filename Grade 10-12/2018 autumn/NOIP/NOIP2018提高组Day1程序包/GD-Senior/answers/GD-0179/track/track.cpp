#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 50005
#define min(x,y) x < y ? x : y
using namespace std;
struct edge{
	int u , v , w;
}e[maxn];
int n , m, minn = 99999999;
int main (){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
		minn=min(minn,e[i].w);
	}
	if(m == n-1){
		printf("%d",minn);
	}
	return 0;
}
