#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int p[40000005],sum[40000010],cur,tot=0,C[40000010];int *buc;
int seed, n, k, S;
int ans1,ans2,ans3;
int getrand() {
    seed = ((seed * 12321) ^ 9999) % 32768;
    return seed;
}
void generateData() {
    scanf( "%d%d%d", &k, &seed, &S );
    int t = 0;
    n = k * 2 + 1;
    memset(p, 0, sizeof(p));
    for( int i = 1; i <= n; ++i ) {
        p[i] = (getrand() / 128) % 2;
        t += p[i];
    }
    int i = 1;
    while( t > k ) {
        while ( p[i] == 0 ) ++i;
        p[i] = 0;
        --t;
    }
    while( t < k ) {
        while( p[i] == 1 ) ++i;
        p[i] = 1;
        ++t;
    }
}
void move1(int pos){
	if(~p[pos]) tot-=buc[1];
	else tot+=buc[0];
	buc+=p[pos];
	if(~p[pos]) buc[0]--;
	if(~p[pos+n]){
		buc[sum[pos+n]-sum[pos]]++;
		if(sum[pos+n]-sum[pos]>0) tot++;
	}
} 
void solve1(){
	int i;tot=0;
	memset(C,0,sizeof(C));buc=C+20000005;
	for(i=1;i<=n;i++) if(~p[i]){
		buc[sum[i]]++;
		if(sum[i]>0) tot++;
	}
	for(i=1;i<=n;i++){
		move1(i);
		if(p[i]==-1){
			if(tot==S) ans2=i;
			if(tot==0) ans1=i;
		}
	}
}
void move2(int pos){
	if(~p[pos]) tot-=buc[1];
	else tot+=buc[0];
	buc+=p[pos];
	if(p[pos]==-1) buc[0]--;
	if(p[pos+n]==-1){
		buc[sum[pos+n]-sum[pos]]++;
		if(sum[pos+n]-sum[pos]>0) tot++;
	}
}
void solve2(){
	int i;tot=0;
	memset(C,0,sizeof(C));buc=C+20000005;
	for(i=1;i<=n;i++) if(p[i]==-1){
		buc[sum[i]]++;
		if(sum[i]>0) tot++;
	}
	for(i=1;i<=n;i++){
		move2(i);
		if(p[i]==-1){
			if(k-tot-buc[0]==S) ans3=i;
		}
	}
}
int main(){
	generateData();int i;
	for(i=1;i<=n;i++){
		if(!p[i]) p[i]=-1;
		p[i+n]=p[i];
	}
	for(i=1;i<=(n<<1);i++) sum[i]=sum[i-1]+p[i];
	solve1();
	solve2();
	printf("%d\n%d\n%d\n",ans1,ans2,ans3);
} 
/*
5
3344
2

500000
4545
234567

*/
