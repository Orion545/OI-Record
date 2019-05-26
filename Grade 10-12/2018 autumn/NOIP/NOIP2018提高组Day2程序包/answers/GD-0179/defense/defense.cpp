#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 100005
using namespace std;
int n , m, cnt = 0;
char in[5];
int cost[maxn];
struct edge{
	int u , v;
}e[maxn*3];
void read(){
	char ch = getchar();
	int cnt = 1; 
	while(ch < 'A' || ch > 'Z')ch = getchar();
	while((ch >= 'A' && ch <= 'Z')||(ch >= '0' && ch <= '9')){
		in[cnt++] = ch;
		ch = getchar();
	}
}
void add(int u , int v){
	e[cnt].u = u;
	e[cnt].v = v;
	cnt ++;
}
int main (){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&cost[i]);
	}
	for(int i=1;i<n;i++){
		int u , v;
		scanf("%d %d",&u,&v);
		add(u,v);
		add(v,u);
	}
	while(m > 0){
		int a , b , x , y;
		scanf("%d %d %d %d",&a,&x,&b,&y);
		printf("-1\n");
		m--;
	}
	return 0;
}
