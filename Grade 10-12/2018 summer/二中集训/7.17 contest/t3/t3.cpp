#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define rank DEEP_DARK_FANTASY
#define hash VAN_YOU_SEE
#define ull unsigned long long
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
ll n,m,q,book[100010],sa[100010],rank[100010],tmp[100010],a[100010],height[100010];
ll st[100010],pos[100010];
void sort(){
	ll i;
	for(i=0;i<=m;i++) book[i]=0;
	for(i=1;i<=n;i++) book[rank[i]]++;
	for(i=1;i<=m;i++) book[i]+=book[i-1];
	for(i=n;i>=1;i--) sa[book[rank[tmp[i]]]--]=tmp[i];
}
void getsa(){
	m=127;ll i,cnt,k,j;
	for(i=1;i<=n;i++) rank[i]=a[i],tmp[i]=i;
	sort();
	for(cnt=1,k=1;cnt<n;k<<=1,m=cnt){
		cnt=0;
		for(i=1;i<=k;i++) tmp[++cnt]=n-k+i;
		for(i=1;i<=n;i++) if(sa[i]>k) tmp[++cnt]=sa[i]-k;
		sort();swap(rank,tmp);
		rank[sa[1]]=cnt=1;
		for(i=2;i<=n;i++)
			rank[sa[i]]=(tmp[sa[i]]==tmp[sa[i-1]]&&tmp[sa[i]+k]==tmp[sa[i-1]+k])?cnt:++cnt;
	}
	k=0;
	for(i=1;i<=n;height[rank[i++]]=k){
		for((k?k--:k),j=sa[rank[i]-1];a[j+k]==a[i+k];k++);
	}
	st[1]=1;pos[1]=1;
	for(i=2;i<=n;i++){
		pos[i]=height[i]+1;
		st[i]=st[i-1]+((n-sa[i-1]+1)-pos[i-1]+1);
	}
	st[n+1]=st[n]+((n-sa[n]+1)-pos[n]+1);
}
ull pre[100010],suf[100010],hash[100010],mod=19260817;
char s[100010];
bool cmp1(ll l,ll r,ll len){
//	cout<<"		cmp1 "<<l<<' '<<r<<' '<<len;cout<<' '<<((pre[l+len-1]-pre[l-1]*hash[len])==(pre[r+len-1]-pre[r-1]*hash[len]))<<'\n';
	return ((pre[l+len-1]-pre[l-1]*hash[len])==(pre[r+len-1]-pre[r-1]*hash[len]));
}
bool cmp2(ll l,ll r,ll len){
//	cout<<"		cmp2 "<<l<<' '<<r<<' '<<len;cout<<' '<<((suf[l-len+1]-suf[l+1]*hash[len])==(suf[r-len+1]-suf[r+1]*hash[len]))<<'\n';
	return ((suf[l-len+1]-suf[l+1]*hash[len])==(suf[r-len+1]-suf[r+1]*hash[len]));
}
int main(){
//	freopen("7.in","r",stdin);
//	freopen("my.out","w",stdout);
	n=read();q=read();ll i,st1,st2,l,r,mid,len1,len2;ll t1,t2;
	scanf("%s",s);hash[0]=1;
	for(i=1;i<=n;i++) a[i]=s[i-1],pre[i]=pre[i-1]*mod+a[i],hash[i]=hash[i-1]*mod;
	for(i=n;i>=1;i--) suf[i]=suf[i+1]*mod+a[i];
	getsa();
//	for(i=1;i<=n;i++) cout<<sa[i]<<' '<<rank[i]<<' '<<height[i]<<' '<<st[i]<<' '<<pos[i]<<'\n';
	for(i=1;i<=q;i++){
		t1=read();t2=read();
		if(t2>=st[n+1]){
			puts("-1");continue;
		}
		
		l=1,r=n;
		while(l<r){
			mid=(l+r)>>1;mid++;
			if(st[mid]>t1) r=mid-1;
			else l=mid;
		}
		st1=sa[l];len1=t1-st[l]+pos[l];
		
		l=1,r=n;
		while(l<r){
			mid=(l+r)>>1;mid++;
			if(st[mid]>t2) r=mid-1;
			else l=mid;
		}
		st2=sa[l];len2=t2-st[l]+pos[l];
		
//		cout<<"get string "<<t1<<' '<<t2<<' '<<st1<<' '<<len1<<' '<<st2<<' '<<len2<<'\n';
		
		l=0,r=min(len1,len2);
		while(l<r){
//			cout<<"	bin1 "<<l<<' '<<r<<' '<<mid<<'\n';
			mid=(l+r)>>1;mid++;
			if(cmp1(st1,st2,mid)) l=mid;
			else r=mid-1;
		}
		t1=l;
		
		l=0,r=min(len1,len2);
		while(l<r){
			mid=(l+r)>>1;mid++;
//			cout<<"	bin2 "<<l<<' '<<r<<' '<<mid<<'\n';
			if(cmp2(st1+len1-1,st2+len2-1,mid)) l=mid;
			else r=mid-1;
		}
		t2=l;
		
		printf("%lld\n",t1*t1+t2*t2);
	}
}

