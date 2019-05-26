#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
inline void dec(ll &a,ll b){
	a-=b;
	if(a<0) a+=MOD;
}
ll f[40][2][2][2],g[40][2][2][2],a[40],b[40],c[40];
ll solve(ll n,ll m,ll lim){
	if(n<0||m<0||lim<0) return 0;
	ll i,j,k,x,y,z,s;
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	x=n;y=m;z=lim;
	for(i=1;i<=31;i++){
		a[i]=x&1ll;x>>=1ll;
		b[i]=y&1ll;y>>=1ll;
		c[i]=z&1ll;z>>=1ll;
	}
	reverse(a+1,a+32);
	reverse(b+1,b+32);
	reverse(c+1,c+32);
	f[1][1][1][1]=1;
	for(s=1;s<=31;s++){
//		cout<<"s "<<s<<' '<<a[s]<<' '<<b[s]<<' '<<c[s]<<'\n';
		for(i=0;i<2;i++){
			for(j=0;j<2;j++){
				for(k=0;k<2;k++){
					if(f[s][i][j][k]==0&&g[i][j][k]==0) continue;
					for(x=0;x<2;x++){
						for(y=0;y<2;y++){
							z=x^y;
							if(i&&x&&(a[s]==0)) continue;
							if(j&&y&&(b[s]==0)) continue;
							if(k&&z&&(c[s]==0)) continue;
							add(f[s+1][i&(x==a[s])][j&(y==b[s])][k&(z==c[s])],f[s][i][j][k]);
							add(g[s+1][i&(x==a[s])][j&(y==b[s])][k&(z==c[s])],g[s][i][j][k]);
							add(g[s+1][i&(x==a[s])][j&(y==b[s])][k&(z==c[s])],f[s][i][j][k]*(z<<(31ll-s))%MOD);
						}
					}
//					if(f[s][i][j][k]||g[s][i][j][k]) cout<<s<<' '<<i<<' '<<j<<' '<<k<<' '<<f[s][i][j][k]<<' '<<g[s][i][j][k]<<'\n';
				}
			}
		}
	}
	ll re=0;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			for(k=0;k<2;k++){
//				cout<<"	final ans "<<i<<' '<<j<<' '<<k<<' '<<f[32][i][j][k]<<' '<<g[32][i][j][k]<<'\n';
				add(re,f[32][i][j][k]);
				add(re,g[32][i][j][k]);
			}
		}
	}
//	cout<<n<<' '<<m<<' '<<lim<<' '<<re<<'\n';
	return re;
}
int main(){
	ll T=read(),x1,x2,y1,y2,lim,ans;
	while(T--){
		x1=read();y1=read();x2=read();y2=read();lim=read();
		x1--;y1--;x2--;y2--;lim--;
		ans=0;
		add(ans,solve(x2,y2,lim));
		add(ans,solve(x1-1,y1-1,lim));
		dec(ans,solve(x2,y1-1,lim));
		dec(ans,solve(x1-1,y2,lim));
		printf("%lld\n",ans);
	}
}
