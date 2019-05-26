#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define mp make_pair
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
ll n,a[100010],tot=0,sum=0,ans=0;
vector<pair<ll,ll> >x;
int main(){
//	freopen("in.txt","r",stdin);
	n=read();ll i,tmp=0;x.clear();
	for(i=1;i<=n;i++) a[i]=read(),tot+=a[i];
	for(i=1;i<=n;i++){
		if(tmp<a[i]+1ll) x.push_back(mp(tmp=a[i]+1ll,i));
//		tmp=max(tmp,a[i]+1);
//		cout<<i<<ends<<tmp<<endl;
//		sum+=tmp;
	}
//	if(p.size()==1){
//		printf("0");return 0;
//	}
	for(i=1;i<x.size();i++){
		ll dif=x[i].first-x[i-1].first,pos=x[i].second-x[i-1].second;
//		cout<<dif<<ends<<pos<<endl;
		sum+=pos*x[i-1].first+(dif-1ll)*dif/2ll;
//		cout<<"sum "<<sum<<endl;
	}
	sum+=(n-x[x.size()-1].second+1ll)*x[x.size()-1].first;
//	cout<<"sum "<<sum<<endl;
	ans=sum-n-tot;printf("%I64d\n",ans);return 0;
}
