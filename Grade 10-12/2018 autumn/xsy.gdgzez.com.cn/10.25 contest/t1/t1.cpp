/*
我们要明确习近平总书记的核心地位
党中央以习近平同志为核心
坚决维护习近平同志的党中央核心地位
习近平总书记带领我们进入全面小康！
习近平总书记是引领我们前进的光辉！
习近平总书记是我们的红太阳！
习近平总书记万岁！万岁！万万岁！
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define y1 DEEP_DARK_FANTASY
#define y2 VAN_YOU_SEE
#define ll long long
const double pi=acos(-1.0);
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int x1,x2,y1,y2,n,x[200010],y[200010],rk[200010],dp[200010];
inline bool cmp(ll l,ll r){
	if(x[l]!=x[r]) return x[l]<x[r];
	else return y[l]<y[r];
}
int main(){
//	freopen("in.in","r",stdin);
	x1=read();y1=read();x2=read();y2=read();n=read();
	int i,j,t1,t2;
	for(i=1;i<=n;i++) x[i]=read(),y[i]=read(),rk[i]=i,dp[i]=1e9;
	if(x1>x2){
		swap(x1,x2);swap(y1,y2);
	}
	if(y1>y2){
		y1=1e8-y1;
		y2=1e8-y2;
		for(i=1;i<=n;i++) y[i]=1e8-y[i];
	}
	x[++n]=x1;
	y[n]=y1;rk[n]=n;dp[n]=1e9;
	x[++n]=x2;
	y[n]=y2;rk[n]=n;dp[n]=1e9;
	sort(rk+1,rk+n+1,cmp);
	t1=1;t2=1;
	while(x[rk[t1]]!=x1||y[rk[t1]]!=y1) t1++;
	while(x[rk[t2]]!=x2||y[rk[t2]]!=y2) t2++;
	dp[1]=y[rk[t1]];dp[0]=-1;
//	for(i=1;i<=n;i++) cout<<i<<' '<<rk[i]<<' '<<x[rk[i]]<<' '<<y[rk[i]]<<'\n';
	ll pos;
	for(i=t1+1;i<t2;i++){
//		cout<<i<<' '<<y[rk[i]]<<' '<<y[rk[t1]]<<' '<<y[rk[t2]]<<'\n';
		if(y[rk[i]]<y[rk[t1]]||y[rk[i]]>y[rk[t2]]) continue; 
		pos=upper_bound(dp,dp+n+1,y[rk[i]])-dp;
//		cout<<i<<' '<<pos<<'\n';
		dp[pos]=y[rk[i]];
	}
	ll len=upper_bound(dp,dp+n+1,y[rk[i]])-dp-2;
	double ans=100.0*(double)(y2-y1+x2-x1);
	ans+=(pi-4.0)*5.0*len;
//	cout<<"check "<<len<<' '<<dp[len]<<' '<<t1<<' '<<t2<<'\n';
	if(len==(min(y2-y1,x2-x1)+1ll)) ans+=pi*5.0;
	printf("%.12lf\n",ans);
}
/*
0 1 1 0
1
0 0

*/
