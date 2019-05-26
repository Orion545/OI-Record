#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define mp make_pair
#define MOD 1000000007
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
ll n;char s[100010];
pair<ll,string>q[100010];
pair<ll,ll>num[10],tmp[10];
int main(){
	scanf("%s",s);ll i,j,k,len,cur;
	n=read();
	for(i=1;i<=n;i++){
		static char t[100010];
		scanf("%s",t);
		len=strlen(t);
		q[i]=mp(t[0]-'0',t+3);
	}
	for(i=0;i<10;i++) num[i]=mp(i,10);
	for(i=n;i;i--){
		len=q[i].second.length();cur=q[i].first;
		tmp[cur].first=0;tmp[cur].second=1;
		ll &t1=tmp[cur].first,&t2=tmp[cur].second;
		for(j=len-1;j>=0;j--){
			k=q[i].second[j]-'0';
			t1=(t1+t2*num[k].first%MOD)%MOD;
			t2=(t2*num[k].second)%MOD;
		}
		num[cur]=tmp[cur];
	}
	len=strlen(s);ll ans=0;cur=1;
	for(i=len-1;i>=0;i--){
		k=s[i]-'0';
		ans=(ans+cur*num[k].first%MOD)%MOD;
		cur=(cur*num[k].second)%MOD;
	}
	cout<<ans<<'\n';
}
