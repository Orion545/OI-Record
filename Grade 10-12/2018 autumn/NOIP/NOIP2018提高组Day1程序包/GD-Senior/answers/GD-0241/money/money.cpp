#include<iostream>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<vector>
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
int n,a[110],dp[110][25010];
vector<int>s;
inline int gcd(int l,int r){
	if(!r) return l;
	return gcd(r,l%r);
}
int dfs(int x,int k){
//	cout<<"	dfs "<<x<<' '<<k<<' '<<dp[k][x]<<'\n';
	if(~dp[k][x]) return dp[k][x];
	if(!x) return dp[k][x]=1;
	if(k==s.size()) return dp[k][x]=0;
	if(x%s[k]==0) return dp[k][x]=1;
	for(int i=0;i*s[k]<=x;i++){
		if(dfs(x-i*s[k],k+1)) return dp[k][x]=1;
	}
	return dp[k][x]=0;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read(),i,j;
	while(T--){
		n=read();bool f1=0;
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++) a[i]=read(),f1|=(a[i]==1);
		if(f1||n==1){
			puts("1");continue;
		}
		sort(a+1,a+n+1);
		int cur=1,minn;
		i=2;s.clear();
		while(i<=n&&a[i]%a[1]==0) i++;
		if(i==n+1){
			puts("1");continue;
		}
		s.push_back(a[1]),s.push_back(a[i]);
		cur=gcd(a[i],a[1]);minn=(a[i]/cur)*(a[1]/cur)-(a[i]/cur)-(a[1]/cur);
		for(i++;i<=n;i++){
//			cout<<"enter "<<i<<' '<<a[i]<<' '<<cur<<' '<<minn<<'\n';
			if(a[i]%cur){
				if(cur!=gcd(cur,a[i])) minn=1e9;
				cur=gcd(cur,a[i]);
				for(j=0;j<s.size();j++){
					minn=min(minn,(a[i]/cur)*(s[j]/cur)-(a[i]/cur)-(s[j]/cur));
				}
				s.push_back(a[i]);
				continue;
			}
			if((a[i]%cur==0)&&((a[i]/cur)>minn)) continue;
			
			for(j=0;j<=s.size();j++) memset(dp[j],-1,sizeof(dp[j]));
			if(dfs(a[i],0)) continue;
			else{
				if(cur!=gcd(cur,a[i])) minn=1e9;
				cur=gcd(cur,a[i]);
				for(j=0;j<s.size();j++){
					minn=min(minn,(a[i]/cur)*(s[j]/cur)-(a[i]/cur)-(s[j]/cur));
				}
				s.push_back(a[i]);
				continue;
			}
		}
		printf("%d\n",s.size());
	}
	return 0;
}
