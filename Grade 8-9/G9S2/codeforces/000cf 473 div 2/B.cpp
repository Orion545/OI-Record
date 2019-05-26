#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define ll long long
ll inf=1e9+7;
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
ll n,m,k,c[100010],minn[100010],belong[100010];
map<string,ll>ma;
int main(){
	std::ios::sync_with_stdio(false);
	cin>>n>>k>>m;ll i,t1,j,t2;string s;
	for(i=1;i<=n;i++){
		cin>>s;ma[s]=i;
	}
	for(i=1;i<=n;i++) cin>>c[i];
	for(i=1;i<=k;i++){
		cin>>t1;minn[i]=inf;
		for(j=1;j<=t1;j++){
			cin>>t2;minn[i]=min(minn[i],c[t2]);belong[t2]=i;
		}
//		cout<<i<<ends<<minn[i]<<endl;
	}
	ll ans=0;
	for(i=1;i<=m;i++){
		cin>>s;
//		cout<<s<<ends<<ma[s]<<endl;
		ans+=minn[belong[ma[s]]];
	}
	cout<<ans;
}
/*
5 3 10
aaads basda sdc das ee
1 10 100 1000 10000
1 5
2 2 4
2 1 3
aaads basda sdc ee das sdc basda das sdc aaads

*/
