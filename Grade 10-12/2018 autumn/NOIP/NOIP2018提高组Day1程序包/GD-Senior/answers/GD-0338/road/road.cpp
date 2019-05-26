#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
#define MAXN 100000+10
#define INF 0x7fffffff

long long n, d[MAXN], ans=0, cnt=1;
int block[MAXN];
struct Node {int key, num;}s[MAXN];
bool cmp(struct Node a, struct Node b) {return a.num<b.num;}

int main(){
	freopen("road.in","r", stdin);
	freopen("road.out","w", stdout);
	scanf("%lld", &n);
	for(long long i=2; i<=n+1; i++)
		scanf("%lld", &s[i].num), s[i].key=i;
	s[1].num=0, s[1].key=1, s[n+2].num=0, s[n+2].key=n+2, n=n+2;
	block[1]=block[n]=1;
	sort(s+1, s+1+n, cmp);
	for(int i=2; i<=n; i++){
		if(s[i].num!=s[i-1].num)  ans+=(s[i].num-s[i-1].num)*cnt;
		if(block[(s[i].key-2+n)%n+1] && block[(s[i].key%n)+1])  cnt--;
		if(!block[(s[i].key-2+n)%n+1] && !block[(s[i].key%n)+1])  cnt++;
		block[s[i].key]=1;
	}
	printf("%lld\n", ans);
	fclose(stdin);  fclose(stdout);
	return 0;
}
