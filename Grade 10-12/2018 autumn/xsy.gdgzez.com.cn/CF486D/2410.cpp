/*

宣告——
汝身在我之下，托付吾之命运于汝之剑，
遵从圣杯之名，若汝遵从此意志此理，回应吧。
在此起誓，吾是成就世间一切行善之人，吾是肃清世间一切罪恶之人，
被狂乱之槛所囚的囚徒。吾是此锁链的操纵者，
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
#define MOD 1000000007
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll dp[2010],ans;
int n;
vector<int>a[2010];
inline void add(int u,int v){
	a[u].push_back(v);
	a[v].push_back(u);
}
int w[2010],lim1,lim2,d,rt;
void dfs(int u,int f){
	dp[u]=1;
//	cout<<"dfs "<<u<<' '<<f<<'\n';
	for(auto v:a[u]){
		if(v==f||w[v]>lim1||w[v]<w[rt]||(w[v]==w[rt]&&v<rt)) continue;
		dfs(v,u);
		(dp[u]*=(dp[v]+1))%=MOD;
	}
}
int main(){
	d=read();n=read();int t1,t2,i;
	for(i=1;i<=n;i++) w[i]=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	for(i=1;i<=n;i++){
		lim1=w[i]+d;rt=i;
		dfs(i,0);
//		cout<<"finish dp "<<i<<' '<<dp[i]<<'\n';
		ans+=dp[i];
		if(ans>=MOD) ans-=MOD;
	}
	printf("%lld\n",ans);
}
