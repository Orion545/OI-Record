#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 51123987
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
ll n,len[4000010],l2[4000010],r1[4000010],sufl[2000010];char ss[4000010],s[4000010];
inline void add(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
int main(){
	n=read();ll i,mid=0,lim=0,l,r,sum=0;
	scanf("%s",ss);
	s[0]='$';
	for(i=0;i<n;i++){
		s[i<<1|1]='#';
		s[(i+1)<<1]=ss[i];
	}
	s[n<<1|1]='#';
	n=n<<1|1;
	for(i=1;i<=n;i++){
		if(i<=lim) len[i]=min(len[mid*2-i],lim-i+1);
		else len[i]=1;
//		cout<<"init len "<<i<<' '<<len[i]<<' '<<lim<<' '<<mid<<' '<<len[mid*2-i]<<'\n';
		while(i-len[i]>=0&&i+len[i]<=n+1&&s[i+len[i]]==s[i-len[i]]) len[i]++;
		if(i+len[i]-1>lim) lim=i+len[i]-1,mid=i;
//		cout<<"finish len "<<i<<' '<<len[i]<<'\n';
	}
//	cout<<"finish manacher"<<endl;
	for(i=1;i<=n;i++){
//		cout<<i<<' '<<s[i]<<' '<<len[i]<<'\n';
		l=i-len[i]+1;r=i+len[i]-1;
		l2[i]++;l2[l-1]--;
		r1[i]++;r1[r+1]--;
	}
	for(i=1;i<=n;i++){
		if(r1[i]<0) r1[i]+=MOD;
		add(r1[i],r1[i-1]);
		if(i&1) continue;
//		cout<<i<<' '<<s[i]<<' '<<l1[i]<<' '<<r1[i]<<'\n';
		add(sum,r1[i]);
	}
	sum=(sum*(sum-1)/2)%MOD;
	for(i=n;i>=1;i--){
		if(l2[i]<0) l2[i]+=MOD;
		add(l2[i],l2[i+1]);
		if(i&1) continue;
		sufl[i>>1]=(sufl[(i>>1)+1]+l2[i])%MOD;
	}
	ll ans=0;
	for(i=1;i<=(n>>1);i++) add(ans,r1[i<<1]*sufl[i+1]%MOD);
	cout<<(sum-ans+MOD)%MOD<<'\n';
}
