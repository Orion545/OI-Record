#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 1e15
using namespace std;
inline ll read(){
    ll re=0,flag=1;char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-') flag=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
    return re*flag;
}
ll n,K,a[100010],dp[2][100010],p[100010],cur=0,pre=1;
ll q[100010],head,tail;
int from[100010][210];
ll getx(ll l,ll r){
//	cout<<"	getx "<<l<<' '<<r<<' '<<dp[pre][l]-dp[pre][r]-p[l]*p[l]+p[r]*p[r]<<'\n';
	return dp[pre][l]-dp[pre][r]-p[l]*p[l]+p[r]*p[r];
}
ll gety(ll l,ll r){
//	cout<<"	gety "<<l<<' '<<r<<' '<<p[r]-p[l]<<'\n';
	return p[r]-p[l];
}
int main(){
	n=read();K=read();ll i,j;
	for(i=1;i<=n;i++) a[i]=read(),p[i]=p[i-1]+a[i];
	for(j=1;j<=K;j++){
//		cout<<"do layer "<<j<<'\n';
		swap(cur,pre);
		memset(q,0,sizeof(q));head=tail=0;
		memset(dp[cur],0,sizeof(dp[cur]));
		q[tail++]=j;
		for(i=j+1;i<=n;i++){
//			cout<<"	dp "<<i<<'\n';
			while(head<tail-1&&getx(q[head],q[head+1])<=gety(q[head],q[head+1])*p[i])
				q[head++]=0;
//			cout<<"	choose "<<q[head]<<'\n';
			dp[cur][i]=dp[pre][q[head]]+p[q[head]]*(p[i]-p[q[head]]);
			from[i][j]=q[head];
//			cout<<"		val "<<dp[cur][i]<<'\n';
			while(head<tail-1&&getx(q[tail-1],i)*gety(q[tail-2],q[tail-1])<=gety(q[tail-1],i)*getx(q[tail-2],q[tail-1]))
				q[--tail]=0;
			q[tail++]=i;
		}
	}
	printf("%lld\n",dp[cur][n]);
	for(i=K;i>=1;i--){
		printf("%d ",from[n][i]);
		n=from[n][i];
	}
}
