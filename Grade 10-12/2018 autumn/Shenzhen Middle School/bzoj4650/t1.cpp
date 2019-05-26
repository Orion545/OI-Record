#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cassert>
#define ll long long
#define log VAN_YOU_SEE
#define rank DEEP_DARK_FANTASY
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
ll n;
char s[100010];
namespace SUF{
	ll m,a[100010],rank[100010],tmp[100010],book[100010],sa[100010],height[100010],st[100010][20],log[100010];
	inline void sort(){
		ll i;
		for(i=0;i<=m;i++) book[i]=0;
		for(i=1;i<=n;i++) book[rank[i]]++;
		for(i=1;i<=m;i++) book[i]+=book[i-1];
		for(i=n;i>=1;i--) sa[book[rank[tmp[i]]]--]=tmp[i];
	}
	void getsa(){
		ll k,cnt,j,i;m=127;
		for(i=1;i<=n;i++) rank[i]=a[i],tmp[i]=i;
		sort();
		for(k=1,cnt=1;cnt<n;m=cnt,k<<=1){
			cnt=0;
			for(i=1;i<=k;i++) tmp[++cnt]=n-k+i;
			for(i=1;i<=n;i++) if(sa[i]>k) tmp[++cnt]=sa[i]-k;
			sort();
			swap(rank,tmp);
			rank[sa[1]]=cnt=1;
			for(i=2;i<=n;i++){
				rank[sa[i]]=((tmp[sa[i]]==tmp[sa[i-1]])&&(tmp[sa[i]+k]==tmp[sa[i-1]+k]))?cnt:++cnt;
			}
		}
		k=0;
		for(i=1;i<=n;height[rank[i++]]=k)
			for((k?k--:k),j=sa[rank[i]-1];a[i+k]==a[j+k];k++);
	}
	void ST(){
		ll i,j;log[1]=0;
		for(i=2;i<=n;i++) log[i]=log[i>>1]+1;
		for(i=1;i<=n;i++) st[i][0]=height[i];
		for(j=1;j<=15;j++){
			for(i=1;i<=n-(1<<j)+1;i++){
				st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
			}
		}
	}
	ll lcp(ll l,ll r){
		l=rank[l];r=rank[r];
		if(l>r) swap(l,r);
		l++;
		ll k=log[r-l+1];
//		cout<<"	lcp "<<l<<' '<<r<<' '<<k<<' '<<min(st[l][k],st[r-(1<<k)+1][k])<<'\n';
		return min(st[l][k],st[r-(1<<k)+1][k]);
	}
}
namespace PRE{
	ll m,a[100010],rank[100010],tmp[100010],book[100010],sa[100010],height[100010],st[100010][20],log[100010];
	inline void sort(){
		ll i;
		for(i=0;i<=m;i++) book[i]=0;
		for(i=1;i<=n;i++) book[rank[i]]++;
		for(i=1;i<=m;i++) book[i]+=book[i-1];
		for(i=n;i>=1;i--) sa[book[rank[tmp[i]]]--]=tmp[i];
	}
	void getsa(){
		ll k,cnt,j,i;m=127;
		for(i=1;i<=n;i++) rank[i]=a[i],tmp[i]=i;
		sort();
		for(k=1,cnt=1;cnt<n;m=cnt,k<<=1){
			cnt=0;
			for(i=1;i<=k;i++) tmp[++cnt]=n-k+i;
			for(i=1;i<=n;i++) if(sa[i]>k) tmp[++cnt]=sa[i]-k;
			sort();
			swap(rank,tmp);
			rank[sa[1]]=cnt=1;
			for(i=2;i<=n;i++){
				rank[sa[i]]=((tmp[sa[i]]==tmp[sa[i-1]])&&(tmp[sa[i]+k]==tmp[sa[i-1]+k]))?cnt:++cnt;
			}
		}
		k=0;
		for(i=1;i<=n;height[rank[i++]]=k)
			for((k?k--:k),j=sa[rank[i]-1];a[i+k]==a[j+k];k++);
	}
	void ST(){
		ll i,j;log[1]=0;
		for(i=2;i<=n;i++) log[i]=log[i>>1]+1;
		for(i=1;i<=n;i++) st[i][0]=height[i];
		for(j=1;j<=15;j++){
			for(i=1;i<=n-(1<<j)+1;i++){
				st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
			}
		}
	}
	ll lcp(ll l,ll r){
		l=rank[l];r=rank[r];
		if(l>r) swap(l,r);
		l++;
		ll k=log[r-l+1];
//		cout<<"	lcp "<<l<<' '<<r<<' '<<k<<' '<<min(st[l][k],st[r-(1<<k)+1][k])<<'\n';
		return min(st[l][k],st[r-(1<<k)+1][k]);
	}
}
void init1(){
	using namespace SUF;
	memset(a,0,sizeof(a));
	memset(rank,0,sizeof(rank));
	memset(tmp,0,sizeof(tmp));
	memset(sa,0,sizeof(sa));
	memset(height,0,sizeof(height));
	memset(st,0,sizeof(st));
}
void init2(){
	using namespace PRE;
	memset(a,0,sizeof(a));
	memset(rank,0,sizeof(rank));
	memset(tmp,0,sizeof(tmp));
	memset(sa,0,sizeof(sa));
	memset(height,0,sizeof(height));
	memset(st,0,sizeof(st));
}
ll pref[100010],preg[100010],f[100010],g[100010];
void init(){
	memset(pref,0,sizeof(pref));
	memset(preg,0,sizeof(preg));
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
}
int main(){
	ll T=read();
	while(T--){
		init1();init2();
		init();
		scanf("%s",s);
		n=strlen(s);
		ll i,j,t1,t2;
		for(i=1;i<=n;i++){
			SUF::a[i]=s[i-1];
			PRE::a[i]=s[n-i];
		}
		SUF::getsa();
		PRE::getsa();
		SUF::ST();
		PRE::ST();
//		cout<<"input "<<s<<'\n';
		for(j=1;j<n;j++){
			for(i=1;i+j<=n;i+=j){
				t1=SUF::lcp(i,i+j);t1=min(j,t1);
				t2=PRE::lcp(n-i-j+1,n-i+1);t2=min(j,t2);
				if(t1+t2<=j) continue;
//				cout<<"do "<<i<<' '<<i+j<<' '<<j<<' '<<t1<<' '<<t2<<'\n';
				pref[i-t2+1]++;
				pref[i+t1-j+1]--;
				preg[i+j-t2+j]++;
				preg[i+j+t1]--;
			}
		}
		for(i=1;i<=n;i++) f[i]=f[i-1]+pref[i];
		for(i=1;i<=n;i++) g[i]=g[i-1]+preg[i];
//		for(i=1;i<=n;i++) cout<<i<<' '<<f[i]<<' '<<g[i]<<'\n';
		ll ans=0;
		for(i=1;i<n;i++) ans+=g[i]*f[i+1];
		cout<<ans<<'\n';
	}
}
