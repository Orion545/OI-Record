#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline ll read(){
	ll p=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-t;ch=getchar();}
	while(ch>='0'&&ch<='9')p=p*10+ch-48,ch=getchar();
	return p*t;
}
ll a[105],Maxn;
bool p[30000];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	ll t;
	t=read();
	while(t--){
		memset(p,0,sizeof(p));
		ll n,ans=0;
		n=read();
		for(ll i=0;i<n;i++)a[i]=read();
		sort(a,a+n);
		Maxn=a[n-1];
		for(ll i=0;i<n;i++){
			if(p[a[i]])continue;
			ans++;
			p[a[i]]=1;
			for(ll k=a[0];k<=Maxn;k++){
				if(k+a[i]>Maxn)break;
				if(p[k])p[k+a[i]]=1;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
