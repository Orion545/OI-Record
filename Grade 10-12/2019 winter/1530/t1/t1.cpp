#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
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
ll n,m,dp[2010][2010],a[2010][2010],val[2010][2010];
int main(){
	n=read();ll i,j,l,r,tmp,cur,x,y,ans=0;char s[20];
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			a[i][j]=read();
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
			val[i][j]=dp[i-1][j]-dp[i][j-1];
			ans+=dp[i][j];
		}
	}
	cout<<ans<<'\n';
	for(j=1;j<=n;j++){
		scanf("%s",s);
		x=read();y=read();
		if(s[0]=='U') tmp=1;
		else tmp=-1;
		a[x][y]+=tmp;
		for(i=y,l=x,r=x;i<=n;i++){
//			cout<<"	enter "<<i<<' '<<l<<' '<<r<<'\n';
			while(i>y&&l<=n){
				val[l][i]-=tmp;
				if(val[l][i]+tmp>0&&tmp==1) l++;
				else if(val[l][i]+tmp>=0&&tmp==-1) l++;
				else break;
			}
			while(r<n){
				val[r+1][i]+=tmp;
				if(val[r+1][i]-tmp>=0&&tmp==1) r++;
				else if(val[r+1][i]-tmp>0&&tmp==-1) r++;
				else break;
			}
//			cout<<"	change "<<tmp<<' '<<i<<' '<<l<<' '<<r<<'\n';
			if(l>r) break;
			ans+=(r-l+1)*tmp;
		}
		printf("%lld\n",ans);
	}
}
