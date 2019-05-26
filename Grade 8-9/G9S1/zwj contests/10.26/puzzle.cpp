#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 0x7fffffff
using namespace std;
ll n,T,a[25][25],tmp[25],ans=inf;
void dfs(ll k,ll to,ll last,ll now,ll stay){
	if(last==n){
		if(now==T) ans=min(ans,k-1);
		return;
	} 
	if(now>T||ans<k) return;
	ll i;
	if(now+stay>T){
		bool flag=1;
		for(i=last+1;i<=n;i++)
			if(a[i][i]==0){
				flag=0;break;
			}
		if(flag) return;
	}
	for(i=n;i>=last+1;i--){
		dfs(k+1,to,i,now+stay*a[last+1][i],1);
		if(i<n) dfs(k+1,to,i,now,stay*a[last+1][i]);
	}
}
int main(){
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	string s;bool flag;
	ll i,j,k;
	while(cin>>s>>T&&T>=0){
		n=s.length();memset(a,0,sizeof(a));
		for(i=1;i<=n;i++){
			for(j=i;j<=min(n,i+n-2);j++){
				for(k=i;k<=j;k++){
					a[i][j]=a[i][j]*10+(s[k-1]-'0');
				}
//				cout<<i<<ends<<j<<ends<<a[i][j]<<endl;
			}
		}
		ans=inf;
		dfs(0,n-1,0,0,1);
		if(ans!=inf) printf("%lld\n",ans);
		else printf("-1\n",ans);
	}
}
