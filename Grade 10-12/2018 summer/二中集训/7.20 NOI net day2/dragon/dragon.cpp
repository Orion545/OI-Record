#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<set>
#define ll long long
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
ll n,m,hp[100010],heal[100010],atk[100010],bonus[100010],cnt;
set<ll>s;
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){x=1,y=0;return a;}
	ll re=exgcd(b,a%b,x,y),tmp=x;
	x=y;y=tmp-(a/b)*y;
	return re;
}
void mul(ll &x,ll y,ll mod){
	ll re=0,flag=(y<0);
	if(flag) y=-y;
//	cout<<"mul "<<x<<' '<<y<<' '<<mod<<'\n';
	while(y){
		if(y&1) re=(re+x+mod)%mod;
		x=(x+x+mod)%mod;y>>=1;
	}
	x=re;if(flag) x=-x;
}
struct CRT{
	ll m[100010],a[100010];
	void clear(){
		memset(m,0,sizeof(m));
		memset(a,0,sizeof(a));
	}
	ll solve(){
		ll M=m[1],A=a[1],t,d,x,y,tmp;ll i;
		for(i=2;i<=cnt;i++){
//			cout<<i<<' '<<M<<' '<<A<<' '<<m[i]<<' '<<a[i]<<'\n';
			d=exgcd(M,m[i],x,y);
//			cout<<i<<' '<<d<<'\n';
			if((a[i]-A)%d) return -1;
			t=m[i]/d;
			mul(x,(a[i]-A)/d,t);
//			cout<<i<<' '<<t<<' '<<x<<'\n';
			tmp=M;M=M/d*m[i];A+=tmp%M*x%M;A%=M;
		}
		A=(A%M+M)%M;
		return A;
	}
}T;
void emp(){}
int main(){
	freopen("dragon.in","r",stdin);
	freopen("dragon.out","w",stdout); 
	ll Te=read();
	while(Te--){
		n=read();m=read();ll i,tmp,x,y,d,tt,ret,ttmp,cur;
		set<ll>::iterator it;bool flag=1;
		s.clear();cnt=0;T.clear(); 
		for(i=1;i<=n;i++) hp[i]=read();
		for(i=1;i<=n;i++) heal[i]=read(),flag=(flag&&(heal[i]==1));
		for(i=1;i<=n;i++) bonus[i]=read();
		for(i=1;i<=m;i++) atk[i]=read(),s.insert(atk[i]);
		if(flag){
			ll ans=0;
			for(i=1;i<=n;i++){
				it=s.lower_bound(hp[i]);
				if(it!=s.begin()) it--;
				tmp=ttmp=*it;
				ans=max(ans,(hp[i]/tmp)+((hp[i]%tmp)!=0));
				s.erase(it);s.insert(bonus[i]);
			}
			printf("%lld\n",ans);
		}
		else{
			for(i=1;i<=n;i++){
				it=s.lower_bound(hp[i]);
				if(it!=s.begin()) it--;
				tmp=ttmp=*it;cur=hp[i]/heal[i];hp[i]%=heal[i];
				s.erase(it);s.insert(bonus[i]);
				//CRT
				d=exgcd(tmp,heal[i],x,y);
				if(hp[i]%d){
					puts("-1");goto end;
				}
				tt=heal[i]/d;mul(x,hp[i]/d,tt);
				tt=tmp;tmp=tmp/d*heal[i];ret=tt%tmp*x%tmp;
				T.m[++cnt]=tmp/ttmp,T.a[cnt]=(ret+cur)/ttmp;
			}
			printf("%lld\n",T.solve());
			end:emp();
		}
		
	}
}
/*
1
5 1
100 100 100 100 100
1 1 1 1 1
10 10 10 10 10
10

2
3 3
3 5 7
4 6 10
7 3 9
1 9 1000
3 2
3 5 6
4 8 7
1 1 1
1 1

*/
