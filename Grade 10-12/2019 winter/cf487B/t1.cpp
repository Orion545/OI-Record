#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#define mp make_pair
#define ll long long
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
int n,s,len,a[200010],dp[200010],lb[200010];
deque<pair<int,int> >maxn,minn,q;
int main(){
	n=read();s=read();len=read();int i,j,t1,t2;pair<int,int>tmp;
	for(i=1;i<=n;i++) a[i]=read(),dp[i]=1e9;
	maxn.clear();minn.clear();
	for(i=1;i<=n;i++){
		t1=t2=1;
		while(!maxn.empty()&&maxn.front().first>a[i]+s) t1=maxn.front().second+1,maxn.pop_front();
		while(!minn.empty()&&minn.front().first<a[i]-s) t2=minn.front().second+1,minn.pop_front();
		lb[i]=max(t1,t2);
//		cout<<"do "<<i<<' '<<t1<<' '<<t2<<' '<<lb[i]<<'\n';
		while(!maxn.empty()&&maxn.back().first<a[i]) maxn.pop_back();
		while(!minn.empty()&&minn.back().first>a[i]) minn.pop_back();
		maxn.push_back(mp(a[i],i));
		minn.push_back(mp(a[i],i));
	}
//	for(i=1;i<=n;i++) cout<<i<<' '<<lb[i]<<'\n';

	dp[0]=0;q.clear();
	for(i=1;i<=n;i++){
		if(i>=len){
			while(!q.empty()&&q.back().first>dp[i-len]) q.pop_back();
			q.push_back(mp(dp[i-len],i-len));
		}
		while(!q.empty()&&q.front().second<lb[i]-1) q.pop_front();
		if(!q.empty()&&q.front().first!=1e9) dp[i]=q.front().first+1;
//		cout<<"dp "<<i<<' '<<dp[i]<<' '<<q.size()<<' '<<q.front().first<<' '<<q.front().second<<'\n';
	}	
	if(dp[n]==1e9) puts("-1");
	else cout<<dp[n]<<'\n';
}
