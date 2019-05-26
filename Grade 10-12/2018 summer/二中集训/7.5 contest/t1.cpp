#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#define ll long long
#define uint unsigned long long
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
const uint MOD=19260817;
map<uint,int>s;
int n,a[200010];
uint pre[200010],suf[200010];
vector<int>num;int ans=0;
uint qpow(uint a,uint b){
	uint re=1;
	while(b){
		if(b&1) re=re*a;
		a=a*a;b>>=1;
	}
	return re;
}
int main(){
	#ifdef dedicatus545
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	#endif
	n=read();int i,j,tmp;uint t1,t2,tmod;
	for(i=1;i<=n;i++) a[i]=read();
	for(i=1;i<=n;i++){
		pre[i]=pre[i-1]*MOD+a[i];
	}
	for(i=n;i>=1;i--){
		suf[i]=suf[i+1]*MOD+a[i];
	}
	for(j=1;j<=n;j++){
		if(n/j<ans) continue;
		s.clear();tmp=0;tmod=qpow(MOD,j);
//		cout<<"do "<<j<<'\n';
		for(i=1;(i+j-1)<=n;i+=j){
			t1=pre[i+j-1]-pre[i-1]*tmod;
			t2=suf[i]-suf[i+j]*tmod;
//			cout<<"	"<<t1<<' '<<t2<<' '<<i<<' '<<j<<'\n';
			if(!s[t1]&&!s[t2]) s[t1]=1,tmp++;
		}
//		cout<<"finish "<<j<<' '<<tmp<<'\n';
		if(ans<tmp){
			ans=tmp;
			num.clear();num.push_back(j);
		}
		else if(ans==tmp) num.push_back(j);
	}
	printf("%d %d\n",ans,num.size());
	for(i=0;i<num.size();i++) printf("%d ",num[i]);
}
