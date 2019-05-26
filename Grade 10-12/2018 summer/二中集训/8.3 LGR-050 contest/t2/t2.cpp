#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define inf 1e16
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
void generate_array(int a[], int n, int m, int seed) {
    unsigned x = seed;
    for (int i = 1; i <= n; ++i) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        a[i] = x % m + 1;
    }
}
int n,m,S,x[10000010],a[10000010],q1[10000010];ll q2[10000010],h1=0,t1=0,h2=0,t2=0;
int main(){
	n=read();m=read();S=read();generate_array(x,n,m,S);int i;ll minn,sec,f1,f2;
	for(i=1;i<=n;i++) a[x[i]]++;
	for(i=1;i<=m;i++) if(a[i]) while(a[i]--) q1[t1++]=i; 
//	for(i=0;i<t1;i++) cout<<q1[i]<<' ';cout<<'\n';
	for(i=1;i<n;i++){
//		cout<<h1<<' '<<t1<<' '<<h2<<' '<<t2<<' '<<q1[h1]<<' '<<q1[h1+1]<<' '<<q2[h2]<<' '<<q2[h2+1]<<'\n'; 
		minn=sec=inf;
		
		if(t1>h1) minn=min(minn,(ll)q1[h1]);
		if(t2>h2) minn=min(minn,q2[h2]);
		if(minn==q1[h1]) f1=0;
		else f1=1;
		
		if(t1>h1+(f1==0)) sec=min(sec,(ll)q1[h1+(f1==0)]);
		if(t2>h2+(f1==1)) sec=min(sec,q2[h2+(f1==1)]);
		if(sec==q1[h1+(f1==0)]) f2=0;
		else f2=1;
		
		if((minn<<1ll)<sec){
			if(f1) q2[h2++]=0;
			else q1[h1++]=0;
		}
		else{
			q2[t2++]=(minn<<1ll);
			if(f1) q2[h2++]=0;
			else q1[h1++]=0;
			if(f2) q2[h2++]=0;
			else q1[h1++]=0;
		}
	}
	assert((t1+t2-h1-h2)==1);
	if(t1>h1) printf("%lld\n",(ll)q1[t1-1]);
	else printf("%lld\n",q2[t2-1]);
}
// 10000000 10000000 666
