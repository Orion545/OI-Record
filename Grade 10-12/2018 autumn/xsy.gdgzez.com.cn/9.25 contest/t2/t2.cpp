#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define MOD 1000000007
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll f[200010],finv[200010],meth[200010];
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=(re*a)%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
void init(){
	ll i,len=200000;
	f[0]=f[1]=finv[0]=finv[1]=1;
	for(i=2;i<=len;i++) f[i]=f[i-1]*i%MOD;
	finv[len]=qpow(f[len],MOD-2);
	for(i=len;i>2;i--) finv[i-1]=finv[i]*i%MOD;
}
int n,a[200010],vis[200010],cir[200010],cntcir=0,in[200010],bst[200010],siz[200010];
ll ans=1;
vector<int>s;
vector<int>nd[200010];
bool cmp(int l,int r){
	return siz[l]<siz[r];
}
ll C(ll x,ll y){
	return f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
int main(){
	n=read();int i,j;ll tmp,c,cc;
	init();
	meth[0]=1;
	for(i=1;i<=n;i++) meth[i]=C(i*2,i)*f[i]%MOD*qpow(qpow(2,MOD-2),i)%MOD;

	for(i=1;i<=n;i++) a[i]=read(),in[a[i]]++;
	for(i=1;i<=n;i++){
		j=i;
		while(!vis[j]) vis[j]=i,j=a[j];
//		cout<<"get "<<i<<' ' <<j<<'\n';
		if(vis[j]^i) continue;
//		cout<<"getnew "<<i<<' ' <<j<<'\n';
		cntcir++;
		while(!cir[j]){
//			if(cntcir==20) cout<<"getcir "<<j<<' '<<a[j]<<' '<<cntcir<<'\n';
			cir[j]=cntcir,nd[cntcir].push_back(j),siz[cntcir]++,j=a[j];
		}
	}
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++){
		if(in[i]) continue;
		j=i;
		while(!cir[j]&&!vis[j]) j=a[j];
		if(vis[j]){
			puts("0");return 0;
		}
//		cout<<"find "<<i<<' '<<j<<'\n';
		bst[cir[j]]=1;tmp=cir[j];
		j=i;c=0;
		while(!cir[j]) cir[j]=tmp,c++,vis[j]=1,j=a[j];
		vis[j]=c;
//		cout<<"finish add "<<cir[j]<<' '<<c<<'\n';
	}
	for(i=1;i<=cntcir;i++){
//		cout<<"check link "<<i<<' '<<bst[i]<<'\n';
		if(!bst[i]){s.push_back(i);continue;}
		for(j=0;j<nd[i].size();j++) if(vis[nd[i][j]]) break;
		tmp=j;
		do{
			c=j;cc=1;
			j--;
			(j+=(int)nd[i].size());
			j%=(int)nd[i].size();
			for(;!vis[nd[i][j]];j--,j=((j<0)?j+nd[i].size():j)) cc++;
//			cout<<"	end "<<c<<' '<<j<<' '<<cc<<' '<<vis[nd[i][c]]<<'\n';
			if(vis[nd[i][c]]>cc){
				puts("0");return 0;
			}
//			cout<<"survive "<<ans<<"\n";
			if(vis[nd[i][c]]<cc) (ans*=2)%=MOD;
		}while(tmp!=j);
	}
	sort(s.begin(),s.end(),cmp);
	for(i=0;i<s.size();i+=c){
		j=i;tmp=0;
		while(siz[s[j]]==siz[s[i]]&&j<s.size()) j++;
//		cout<<"circles "<<i<<' '<<j<<'\n';
		c=j-i;
		for(j=0;j<=c/2;j++){
			(tmp+=C(c,2*j)*meth[j]%MOD*qpow(siz[s[i]],j)%MOD*qpow(2,(c-2*j)*(siz[s[i]]!=1)*(siz[s[i]]&1))%MOD)%=MOD;
//			cout<<'	'<<j<<' '<<tmp<<'\n';
		}
		ans=ans*tmp%MOD;
	}
	printf("%lld\n",ans);
}
