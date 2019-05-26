#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
#define MOD 1000000007
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
int n,m,in[100010],out[100010];
ll p[1010],f[100010],g[100010],h[100010],w[100010],cnt[100010];
int main(){
	n=read();m=read();int i,s,t1,t2;
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		t1=(1<<(t1-1)),t2=(1<<(t2-1));
		in[t2]|=t1;
		out[t1]|=t2;
	}
	for(i=1;i<=(1<<n);i++) cnt[i]=cnt[i^(i&(-i))]+1;
	p[0]=1;
	for(i=1;i<=n*n;i++) p[i]=(p[i-1]<<1)%MOD;
	for(s=1;s<(1<<n);s++){
		t1=s&(-s);t2=s^t1;
		
		for(i=t2;i;i=(i-1)&t2)
			g[s]=(g[s]-g[i]*f[s^i]%MOD+MOD)%MOD;
			
		h[s]=h[t2]+cnt[in[t1]&t2]+cnt[out[t1]&t2];
		f[s]=p[h[s]];
		
		for(i=s;i;i=(i-1)&s){
			t1=(s^i)&-(s^i);t2=i^t1;
			if(i!=s) w[i]=w[t2]-cnt[in[t1]&(s^i)]+cnt[out[t1]&i];
			else w[i]=0;
			f[s]=(f[s]-p[w[i]+h[s^i]]*g[i]%MOD+MOD)%MOD;
		}
		(g[s]+=f[s])%=MOD;
	}
	printf("%lld\n",f[(1<<n)-1]);
}
/*
5 15
4 3
4 2
2 5
2 1
1 2
5 1
3 2
4 1
1 4
5 4
3 4
5 3
2 3
1 5
3 1

*/
