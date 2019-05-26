#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define MOD 1000000007
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
int n,a[20][20][20];
ll ans=0;
ll x[20][20],deg[20],ch;
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
ll MatrixTree(){
	int i,j,k,num;ll tmp,inv,re=1;
	n--;
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n;j++) cout<<x[i][j]<<' ';
//		cout<<'\n';
//	}
	for(i=1;i<=n;i++){
//		cout<<"	Do Gauss "<<i<<'\n';
		if(!x[i][i]){
			num=i+1;
			while(!x[num][i]) num++;
			if(num>n) continue;
			for(j=1;j<=n;j++) swap(x[i][j],x[num][j]);
			ch^=1;
		}
		inv=qpow(x[i][i],MOD-2);
		for(j=i+1;j<=n;j++){
			if(!x[j][i]) continue;
			tmp=x[j][i]*inv%MOD;
			for(k=1;k<=n;k++) x[j][k]=(x[j][k]-x[i][k]*tmp%MOD+MOD)%MOD;
		}
	}
	for(i=1;i<=n;i++) re=re*x[i][i]%MOD;
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n;j++) cout<<x[i][j]<<' ';
//		cout<<'\n';
//	}
	n++;
//	cout<<"Matrix tree "<<re<<'\n';
	return re;
}
void dfs(int u,int cnt,int S){
//	cout<<"dfs "<<u<<' '<<cnt<<' '<<S<<'\n';
	if(u==n-1){
		int i,j,k;
		memset(x,0,sizeof(x));memset(deg,0,sizeof(deg));
		for(i=1;i<n;i++){
			if(!(S&(1<<(i-1)))) continue;
			for(j=1;j<=n;j++){
				for(k=j+1;k<=n;k++){
					if(!a[i][j][k]) continue;
//					cout<<"	add edge "<<j<<' '<<k<<'\n';
					x[j][k]=(x[j][k]+MOD-1)%MOD;
					x[k][j]=(x[k][j]+MOD-1)%MOD;
					deg[j]++;deg[k]++;
				}
			}
		}
		for(i=1;i<=n;i++) x[i][i]=deg[i];
		ch=0;
		ans+=((((n-1-cnt)&1)?-1:1)*MatrixTree()*(ch==1?-1:1)%MOD+MOD)%MOD;ans%=MOD;
		return;
	}
	dfs(u+1,cnt+1,S|(1<<u));
	dfs(u+1,cnt,S);
}
int main(){
	n=read();int i,t1,t2,t3;
	for(i=1;i<n;i++){
		t1=read();
		while(t1--){
			t2=read();t3=read();
			a[i][t2][t3]=a[i][t3][t2]=1;
		}
	}
	dfs(0,0,0);
	printf("%lld\n",ans);
}

