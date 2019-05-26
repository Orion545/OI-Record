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
int n,m,op,ed,first[100010],cnte;ll in[100010],inv[200010],re[100010];
struct edge{
	int to,next;
}a[200010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
}
ll ans=1,dp[100010];
int q[100010],head,tail;
void topo(){
	int i,u,v;head=tail=0;
	dp[ed]=ans;in[ed]--;
//	cout<<"topo "<<dp[ed]<<'\n'; 
	for(i=1;i<=n;i++){
		if(!in[i]) q[tail++]=i;
		re[i]=in[i];
	}
	in[ed]++;
	while(head<tail){
		u=q[head++];dp[u]=dp[u]*inv[in[u]]%MOD;
//		cout<<"topo "<<u<<' '<<dp[u]<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;re[v]--;
			dp[v]=(dp[v]+dp[u])%MOD;
			if(!re[v]) q[tail++]=v;
		}
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();op=read();ed=read();in[ed]++;
	int i,t1,t2;
	inv[1]=1;
	for(i=2;i<=m;i++) inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		add(t1,t2);in[t2]++;
	}
	for(i=2;i<=n;i++) ans=ans*in[i]%MOD;
	if(ed==1){
		printf("%lld\n",ans);return 0;
	}
	topo();
	printf("%lld\n",(ans-dp[op]+MOD)%MOD);
}
/*
10 12 2 5
1 2
2 3
3 4
4 5
2 6
6 7
7 5
1 8 
1 9
8 9
9 10
10 7

*/
