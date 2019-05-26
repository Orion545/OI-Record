#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<unordered_map>
#include<queue>
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
inline void add(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
inline void addd(ll &a,ll b){
	a+=b;
}
unordered_map<ll,ll>mp;
ll n,m,f[20][20010][2],p[20],t[20],back[20010],cnt,len,sum[20010];
void init(){
	ll i,j,k,cur,tmp;
	p[1]=1;
	for(i=2;i<=13;i++) p[i]=p[i-1]*10ll%MOD;
	for(i=1;i<10;i++){
		mp[i]=++cnt;back[cnt]=i;
	}
	for(i=2;i<=13;i++,cnt=cur){
		cur=cnt;
		for(j=1;j<=cnt;j++){
			for(k=1;k<10;k++){
				tmp=k*back[j];
				if(mp[tmp]) continue;
				mp[tmp]=++cur;back[cur]=tmp;
			}
		}
	}
//	cout<<"finish init "<<cnt<<'\n';
}
inline bool cmp(ll l,ll r){
	return l>r;
}
void dp(){
	ll i,j,k,t1,t2;
	len=0;i=n;
	while(i){
		t[++len]=i%10ll;
		i/=10ll;
	}
	for(i=1;i<10;i++) f[1][mp[i]][(i>t[1])]=1;
	for(i=2;i<=len;i++){
		for(j=1;j<=cnt;j++){
			for(k=1;k<10;k++){
				t1=back[j];if(t1%k) continue;
				t2=mp[t1/k];
				if(k<t[i]) addd(f[i][j][0],(f[i-1][t2][0]+f[i-1][t2][1]));
				if(k>t[i]) addd(f[i][j][1],(f[i-1][t2][0]+f[i-1][t2][1]));
				if(k==t[i]){
					addd(f[i][j][0],f[i-1][t2][0]);
					addd(f[i][j][1],f[i-1][t2][1]);
				}
			}
		}
	}
	for(i=1;i<=cnt;i++){
		for(j=1;j<=len;j++){
			addd(sum[i],(f[j][i][0]+(j!=len)*f[j][i][1]));
		}
//		if(sum[i]) cout<<i<<' '<<back[i]<<' '<<sum[i]<<'\n';
	}
	sort(sum+1,sum+cnt+1,cmp);
}
struct node{
	ll i,j,val;
	inline bool operator <(const node &b)const{
		return val<b.val;
	}
};
priority_queue<node>q;
int main(){
	init();ll i,ans=0;node tmp;
	n=read();m=read();
	dp();
	for(i=1;i<=cnt;i++) q.push((node){i,1,sum[i]*sum[1]});
	for(i=1;i<=m;i++){
		tmp=q.top();q.pop();
		add(ans,tmp.val%MOD);
//		cout<<"get "<<i<<' '<<tmp.i<<' '<<tmp.j<<' '<<tmp.val<<'\n';
		tmp.j++;tmp.val=sum[tmp.i]*sum[tmp.j];
		q.push(tmp);
	}
	cout<<ans<<'\n';
}
