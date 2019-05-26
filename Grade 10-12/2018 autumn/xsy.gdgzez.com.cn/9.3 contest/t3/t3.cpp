#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define rank DEEP_DARK_FANTASY
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
ll a[500010],sa[500010],rank[500010],tmp[500010],book[500010],height[500010],n,m;
void sort(){
	ll i;
	for(i=0;i<=m;i++) book[i]=0;
	for(i=1;i<=n;i++) book[rank[i]]++;
	for(i=1;i<=m;i++) book[i]+=book[i-1];
	for(i=n;i>=1;i--) sa[book[rank[tmp[i]]]--]=tmp[i];
}
void getsa(){
	m=127;ll i,j,k,cnt;
	for(i=1;i<=n;i++) rank[i]=a[i],tmp[i]=i;
	sort();
	for(k=1,cnt=0;cnt<n;m=cnt,k<<=1){
		cnt=0;
		for(i=1;i<=k;i++) tmp[++cnt]=n-k+i;
		for(i=1;i<=n;i++) if(sa[i]>k) tmp[++cnt]=sa[i]-k;
		sort();
		swap(rank,tmp);
		rank[sa[1]]=cnt=1;
		for(i=2;i<=n;i++)
			rank[sa[i]]=((tmp[sa[i]]==tmp[sa[i-1]]&&tmp[sa[i]+k]==tmp[sa[i-1]+k])?cnt:++cnt);
	}
	k=0;
//	for(i=1;i<=n;i++) cout<<i<<' '<<sa[i]<<' '<<rank[i]<<'\n';
	for(i=1;i<=n;height[rank[i++]]=k)
		for((k?k--:k),j=sa[rank[i]-1];a[i+k]==a[j+k];k++);
}
#define log VAN_YOU_SEE
char s[500010];
ll pre[500010];
namespace ST{
	ll st[500010][20],log[500010];
	void getst(){
		ll i,j;log[1]=0;
		for(i=2;i<=n;i++) log[i]=log[i/2]+1;
		for(i=1;i<=n;i++) st[i][0]=height[i];
		for(j=1;j<=19;j++){
			for(i=1;i<=n-(1<<j)+1;i++)
				st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	ll query(ll l,ll r){
		ll k=log[r-l+1];
		return min(st[l][k],st[r-(1<<k)+1][k]);
	}
}
ll root[500010];
namespace seg{
	ll cnt=0,ch[10000010][2],siz[10000010];
	ll build(ll l,ll r,ll pos,ll pre){
		ll cur=++cnt,mid=(l+r)>>1;
		ch[cur][0]=ch[pre][0];
		ch[cur][1]=ch[pre][1];
		siz[cur]=siz[pre]+1;
		if(l==r) return cur;
		if(mid>=pos) ch[cur][0]=build(l,mid,pos,ch[pre][0]);
		else ch[cur][1]=build(mid+1,r,pos,ch[pre][1]);
		return cur;
	}
	ll query(ll l,ll r,ll ql,ll qr,ll pre,ll cur){
		if(ql>qr) return 0;
//		cout<<"query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<siz[pre]<<' '<<siz[cur]<<'\n';
		if(l>=ql&&r<=qr) return siz[cur]-siz[pre];
		ll mid=(l+r)>>1,re=0;
		if(mid>=ql) re+=query(l,mid,ql,qr,ch[pre][0],ch[cur][0]);
		if(mid<qr) re+=query(mid+1,r,ql,qr,ch[pre][1],ch[cur][1]);
		return re;
	}
	ll getk(ll l,ll r,ll pre,ll cur,ll k){
//		cout<<"getk "<<l<<' '<<r<<' '<<siz[pre]<<' '<<siz[cur]<<' '<<k<<'\n';
		if(l==r) return l;
		ll mid=(l+r)>>1,tmp=siz[ch[cur][0]]-siz[ch[pre][0]];
		if(k<=tmp) return getk(l,mid,ch[pre][0],ch[cur][0],k);
		else return getk(mid+1,r,ch[pre][1],ch[cur][1],k-tmp);
	}
}
#define mp make_pair
pair<ll,ll>get(ll pos,ll lim){
	ll l,r,mid;pair<ll,ll>re;
//	cout<<"	binary search "<<pos<<' '<<lim<<'\n';
	l=1,r=pos;
	while(l<r){
		mid=(l+r)>>1;
		if(ST::query(mid+1,pos)<lim) l=mid+1;
		else r=mid;
	}
	re.first=l;
	l=pos,r=n;
	while(l<r){
		mid=(l+r)>>1;mid++;
		if(ST::query(pos+1,mid)<lim) r=mid-1;
		else l=mid;
	}
	re.second=l;
	return re;
}
int main(){
	scanf("%s",s);ll i,t1,t2,t3,Q=read(),l,r,mid,len,k1,k2;pair<ll,ll>tmp;
	n=strlen(s);
	for(i=0;i<n;i++) a[i+1]=(ll)s[i];
	getsa();
	for(i=1;i<=n;i++) pre[i]=pre[i-1]+(n-sa[i]+1)-height[i];
	for(i=1;i<=n;i++) root[i]=seg::build(1,n,sa[i],root[i-1]);
	ST::getst();
	while(Q--){
		t1=read();t2=read();t3=read();
		if(t1==1){
			l=1;r=n;
			while(l<r){
				mid=(l+r)>>1;
				if(pre[mid]<t2) l=mid+1;
				else r=mid;
			}
			len=t2-pre[l-1]+height[l];
			tmp=get(l,len);
			k1=seg::getk(1,n,root[tmp.first-1],root[tmp.second],t3);
//			cout<<"getans "<<l<<' '<<len<<' '<<sa[l]<<' '<<k1<<' '<<t3<<'\n';
			printf("%lld %lld\n",k1,k1+len-1);
		}
		if(t1==2){
			len=t3-t2+1;
			tmp=get(rank[t2],len);
			k1=pre[tmp.first-1]+len-height[tmp.first];
			k2=seg::query(1,n,1,t2-1,root[tmp.first-1],root[tmp.second])+1;
			printf("%lld %lld\n",k1,k2);
		}
	}
}
