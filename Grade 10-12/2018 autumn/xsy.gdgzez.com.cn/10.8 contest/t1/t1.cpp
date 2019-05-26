#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
#define MOD 998244353
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
ll T,n;
ll cur[60010],pre[60010],l[20],r[20],p3[20];
ll limp[60],lim[60],lp[60],rp[60];
//0:middle
//1:equal to l
//2:equal to r

void dfs(ll x,ll flag,ll s1,ll s2){
//	cout<<"dfs "<<x<<' '<<flag<<' '<<s1<<' '<<s2<<' '<<cur[s2]<<' '<<pre[s1]<<'\n';
	if(x==0){(cur[s2]+=pre[s1])%=MOD;return;}
	s1*=3;s2*=3;
	if(!limp[x]){//normal
		if(!lp[x]) dfs(x-1,flag,s1,s2);//if lp==1 then must reach limit on right
		dfs(x-1,flag,s1+1,s2+1+rp[x]);
		dfs(x-1,flag,s1+2,s2+2);
		if(!flag){
			dfs(x-1,1,s1,s2+(lp[x]^1)*2);
			if(rp[x]) dfs(x-1,1,s1+1,s2+1);
			//must be added on pos x, so if wanted reaching left limitation,then prev left needed
			dfs(x-1,1,s1+2,s2+2);
		}
	}
	else if(!lim[x]){
		dfs(x-1,flag,s1,s2);
		if(!flag) dfs(x-1,1,s1,s2+1);
		//this time, all pos before x are equal(l[i]=r[i]), but l[x]=0,r[x]=1;
		//so only walking straight and adding 1 is available
		//when adding, can go from left bound in x+1 to anywhere in s1 (because lbound of x+1 slightly fits rbound)
	}
	else if(flag+rp[x]<=1) dfs(x-1,flag+rp[x],s1,s2);
}
int main(){
	ll T=read(),i,j;
	p3[0]=1;
	for(i=1;i<=10;i++) p3[i]=p3[i-1]*3%MOD;
	while(T--){
		n=read();
		for(i=1;i<=n;i++) l[i]=read(),l[i]--;
		for(i=1;i<=n;i++) r[i]=read(),r[i]--;
		cur[0]=1;
		for(i=50;i>=0;i--){
			swap(pre,cur);
			memset(cur,0,sizeof(cur));
			memset(lim,0,sizeof(lim));
			memset(limp,0,sizeof(limp));
			memset(lp,0,sizeof(lp));
			memset(rp,0,sizeof(rp));
			for(j=1;j<=n;j++){
				lp[j]=(l[j]>>i)&1;
				rp[j]=(r[j]>>i)&1;

				lim[j]=!((r[j]^l[j])>>i);
//				if(!lim[j]) lim[j]=1;
//				else lim[j]=0;

				limp[j]=!((r[j]^l[j])>>(i+1));
//				if(!limp[j]) limp[j]=1;
//				else limp[j]=0;
				
//				cout<<i<<' '<<j-1<<' '<<lp[j]<<' '<<rp[j]<<' '<<lim[j]<<' '<<limp[j]<<'\n';
			}
			dfs(n,0,0,0);
		}
		ll ans=0;
		for(i=0;i<=p3[n];i++) (ans+=cur[i])%=MOD;
		cout<<ans<<'\n';
	}
}
