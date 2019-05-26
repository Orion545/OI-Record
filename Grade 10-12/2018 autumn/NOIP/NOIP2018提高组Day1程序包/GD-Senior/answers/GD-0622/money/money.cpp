#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
inline ll read() {
	ll x=0,f=1ll; char ch=getchar();
	while(ch<'0'||ch>'9') { if(f=='-') f=-f; ch=getchar(); }
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
#define _ read()
const int N=1e2+5;
int a[N],n;
inline int solve() {
	int ans=0,dp[25005];
	for(int i=0;i<=a[n];i++)
		dp[i]=0;
	for(int i=1;i<=n;i++) 
		if(dp[a[i]]==0) {
			++ans; //元素个数+1 
			dp[a[i]]=1; //打标记 
			for(int j=1;j<=a[n];j++) //更新1..max{a_i}能被b_i构成的元素 
				if(dp[j]) dp[j+a[i]]=1; 
		}
	//最终结果一定dp[a[i]]=1(i: 1~n ) 
	return ans;
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t=_;
	while(t--) {
		n=_;
		for(int i=1;i<=n;i++)
			a[i]=_;
		sort(a+1,a+n+1);
		printf("%d\n",solve());
	}
}
/*
显然b_i是a_i的一个子集，不然肯定会出现新的数。
把a_i从小到大排序，如果a_i能被目前的b_i构成，则a_i可以被略去
否则a_i作为b_i的一个元素。然后统计一下b_i能构成1..max{a_i} 中的哪些数 。对能构成的数打标记 
*/

