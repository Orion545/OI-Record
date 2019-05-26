#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 1000000007
#define INV 500000004
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
ll n,p[2000010],l1[2000010],l2[2000010],r1[2000010],r2[2000010];char ss[1000010],s[2000010];
void add(ll &a,ll b){
//	cout<<"	add "<<a<<' '<<b<<'\n';
	a+=b;
	if(a>=MOD) a-=MOD;
}
int main(){
	while(~scanf("%s",ss)){
		memset(s,0,sizeof(s));memset(p,0,sizeof(p));
		n=strlen(ss);ll i,l,r,mid=0,lim=0,ans=0;
		for(i=0;i<n;i++) s[i<<1|1]='#',s[(i+1)<<1]=ss[i];
		n=n<<1|1;s[n]='#';s[0]='$';
//		cout<<"finish input "<<ss<<' '<<s<<'\n';
		for(i=1;i<=n;i++){
			if(i<lim) p[i]=min(p[i*2-mid],lim-i);
			else p[i]=1;
			while(s[i+p[i]]==s[i-p[i]]) p[i]++;
			if(lim<i+p[i]) lim=i+p[i],mid=i;
		}
		memset(l1,0,sizeof(l1));
		memset(l2,0,sizeof(l2));
		memset(r1,0,sizeof(r1));
		memset(r2,0,sizeof(r2));
		for(i=1;i<=n;i++){
			l=i-p[i]+1;
			r=i+p[i]-1;
			add(l1[l],r);add(l2[l+1],-1);
			add(l1[i+1],-i);add(l2[i+1],1);
			add(r1[i],i);add(r2[i+1],-1);
			add(r1[r+1],-l);add(r2[r+1],1);
		}
		for(i=1;i<=n;i++){
			add(l1[i],l1[i-1]);add(r1[i],r1[i-1]);
			add(l2[i],l2[i-1]);add(r2[i],r2[i-1]);
			add(l1[i],l2[i]);add(r1[i],r2[i]);
//			cout<<i<<' '<<s[i]<<' '<<p[i]<<' '<<l1[i]<<' '<<r1[i]<<'\n';
		}
		for(i=2;i<n-2;i+=2) add(ans,(r1[i]*INV%MOD)*(l1[i+2]*INV%MOD)%MOD);
		cout<<ans<<'\n';
	}
}
