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
			++ans; //Ԫ�ظ���+1 
			dp[a[i]]=1; //���� 
			for(int j=1;j<=a[n];j++) //����1..max{a_i}�ܱ�b_i���ɵ�Ԫ�� 
				if(dp[j]) dp[j+a[i]]=1; 
		}
	//���ս��һ��dp[a[i]]=1(i: 1~n ) 
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
��Ȼb_i��a_i��һ���Ӽ�����Ȼ�϶�������µ�����
��a_i��С�����������a_i�ܱ�Ŀǰ��b_i���ɣ���a_i���Ա���ȥ
����a_i��Ϊb_i��һ��Ԫ�ء�Ȼ��ͳ��һ��b_i�ܹ���1..max{a_i} �е���Щ�� �����ܹ��ɵ������� 
*/

