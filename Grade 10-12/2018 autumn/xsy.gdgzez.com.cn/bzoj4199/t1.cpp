#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
#define rank DEEP_DARK_FANTASY
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
ll n,m,a[300010],tmp[300010],sa[300010],rank[300010],height[300010],book[300010];char s[300010];
void sort(){
	ll i;
	for(i=0;i<=m;i++) book[i]=0;
	for(i=1;i<=n;i++) book[rank[i]]++;
	for(i=1;i<=m;i++) book[i]+=book[i-1];
	for(i=n;i>=1;i--) sa[book[rank[tmp[i]]]--]=tmp[i];
}
void getsa(){
	ll i,j,cnt,k;m=127;
	for(i=1;i<=n;i++) tmp[i]=i,rank[i]=a[i];
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
ll rk[300010],f[300010],w[300010],minn[300010],maxn[300010],siz[300010];
ll find(ll x){return ((f[x]==x)?x:f[x]=find(f[x]));}
inline bool cmp(ll l,ll r){
	return height[l]>height[r];
}
ll ans[300010],maxw[300010];
int main(){
	n=read();ll i,l,r,tt,max1=-1e9-7,max2=-1e9-7,min1=1e9+7,min2=1e9+7;
	scanf("%s",s);
	for(i=0;i<n;i++) a[i+1]=s[i]-'a'+1;
	getsa();
	for(i=1;i<=n;i++){
		maxw[i]=-1e18;
		w[i]=read();
		minn[i]=maxn[i]=w[i];
		f[i]=i;siz[i]=1;
		rk[i]=i;
		if(w[i]>max1){
			max2=max1;max1=w[i];
		}
		else if(w[i]>max2){
			max2=w[i];
		}
		if(w[i]<min1){
			min2=min1;min1=w[i];
		}
		else if(w[i]<min2){
			min2=w[i];
		}
	}
	ans[0]=n*(n-1)/2;maxw[0]=max(max1*max2,min1*min2);
	sort(rk+2,rk+n+1,cmp);
	for(i=1;i<=n;i++){
//		cout<<i<<' '<<w[i]<<' '<<rank[i]<<' '<<sa[i]<<' '<<height[i]<<'\n';
	}
//	cout<<"fin check "<<n<<' '<<max1<<' '<<max2<<'\n';
	for(i=2;i<=n;i++){
		if(height[rk[i]]==0) break;
		l=sa[rk[i]];r=sa[rk[i]-1];
		l=find(l);r=find(r);
		tt=height[rk[i]];
		ans[tt]+=siz[l]*siz[r];
//		cout<<"gettmp "<<tt<<' '<<l<<' '<<r<<' '<<siz[l]<<' '<<siz[r]<<'\n';
		maxw[tt]=max(maxw[tt],max(minn[l]*minn[r],maxn[l]*maxn[r]));
		f[r]=l;
		maxn[l]=max(maxn[l],maxn[r]);
		minn[l]=min(minn[l],minn[r]);
		siz[l]+=siz[r];
	}
	for(i=n-1;i>=1;i--){
		ans[i]+=ans[i+1];
		maxw[i]=max(maxw[i],maxw[i+1]);
	}
	for(i=0;i<n;i++){
		if(ans[i]==0) maxw[i]=0;
		printf("%lld %lld\n",ans[i],maxw[i]);
	}
}
