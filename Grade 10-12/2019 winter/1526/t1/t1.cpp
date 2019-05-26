#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
#include<cmath>
#define hash DEEP_DARK_FANTASY
#define MOD 998244353
#define ll long long
using namespace std;
int mmp[60000010],*pos=mmp;
inline int* newint(int len){int *p=pos;pos+=len;return p;}
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
inline int add(int a,int b){
	a+=b;
	if(a>=MOD) a-=MOD;
	return a;
}
inline int dec(int a,int b){
	a-=b;
	if(a<0) a+=MOD;
	return a;
}
inline int qpow(int a,int b){
	int re=1;
	while(b){
		if(b&1) re=1ll*re*a%MOD;
		a=1ll*a*a%MOD;b>>=1;
	}
	return re;
}
int n,tot,K;
vector<int>tr[2000010];
struct op{
	int l,r,p;
}q[100010];
int hash[200010];
int *poly[2000010];
int len[2000010];
namespace p{
	const int g=3,ginv=332748118;
	int r[400010],lim,cnt,A[400010],B[400010];
	inline void ntt(int *a,int type){
		int i,j,k,mid,x,y,w,wn,l;
		for(i=0;i<lim;i++) if(i<r[i]) swap(a[i],a[r[i]]);
		for(mid=1;mid<lim;mid<<=1){
			l=mid<<1;wn=qpow((type==1)?g:ginv,(MOD-1)/l);
			for(j=0;j<lim;j+=l){
				for(k=0,w=1;k<mid;k++,w=1ll*w*wn%MOD){
					x=a[j+k];y=1ll*a[j+k+mid]*w%MOD;
					a[j+k]=add(x,y);
					a[j+k+mid]=dec(x,y);
				}
			}
		}
		if(type==1) return;
		int inv=qpow(lim,MOD-2);
		for(i=0;i<lim;i++) a[i]=1ll*a[i]*inv%MOD;
	}
	inline void mul(int *re,int *a,int *b,int lena,int lenb){
		register int i,j;
//		/*
		if(lena<=80||lenb<=80){
			memset(A,0,sizeof(int)*(lena+lenb+1));
			for(i=0;i<=lena;i++){
				for(j=0;j<=lenb;j++){
					A[i+j]=add(A[i+j],1ll*a[i]*b[j]%MOD);
				}
			}
			memcpy(re,A,sizeof(int)*(min(K,lena+lenb)+1));
			return;
		}
//		*/
		lim=1;cnt=0;
		while(lim<=(lena+lenb)) lim<<=1,cnt++;
		assert(lim<=262144);
		for(i=0;i<lim;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1)));
		for(i=0;i<lim;i++) A[i]=(i<=lena)?a[i]:0;
		for(i=0;i<lim;i++) B[i]=(i<=lenb)?b[i]:0;
		ntt(A,1);ntt(B,1);
		for(i=0;i<lim;i++) A[i]=1ll*A[i]*B[i]%MOD;
		ntt(A,-1);
		memcpy(re,A,sizeof(int)*(min(K,lena+lenb)+1));
		return;
	}
}
namespace seg{
	inline void insert(int l,int r,int ql,int qr,int num,int p){
//		cout<<"insert "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<num<<' '<<p<<'\n';
		if(l>=ql&&r<=qr){
			tr[num].push_back(p);
			return;
		}
		int mid=(l+r)>>1;
		if(mid>=ql) insert(l,mid,ql,qr,num<<1,p);
		if(mid<qr) insert(mid+1,r,ql,qr,num<<1|1,p);
	}
	inline int* query(int l,int r,int pos){
//		cout<<"		seg query "<<l<<' '<<r<<' '<<pos<<' '<<tr[pos][l]<<'\n';
		if(l==r){
			int *re=newint(2);
			re[0]=((tr[pos][l]<=1)?(1-tr[pos][l]):(MOD+1-tr[pos][l]));
			re[1]=tr[pos][l];
			return re;
		}
		int mid=(l+r)>>1;
		int *le=query(l,mid,pos);
		int *ri=query(mid+1,r,pos);
		int *re=newint(min(K+1,r-l+2));
		p::mul(re,le,ri,mid-l+1,r-mid);
		return re;
	}
}
inline void solve(int l,int r,int num){
	assert(num<=2000000);
	len[num]=min(K,(int)tr[num].size());
	poly[num]=newint(len[num]+1);poly[num][0]=1;
	if(tr[num].size()) poly[num]=seg::query(0,tr[num].size()-1,num);
//	cout<<"solve "<<l<<' '<<r<<' '<<num<<' '<<len[num]<<'\n';
//	for(int i=0;i<=len[num];i++) cout<<i<<' '<<poly[num][i]<<'\n';
	if(l==r){
		int lenth=hash[l+1]-hash[l],i;
		for(i=0;i<=len[num];i++) poly[num][i]=1ll*poly[num][i]*lenth%MOD;
//		cout<<"	reach solve end "<<l<<' '<<lenth<<"\n";
//		for(i=0;i<=len[num];i++) cout<<'	'<<i<<' '<<poly[num][i]<<'\n';
		return;
	}
	int mid=(l+r)>>1,i;
	solve(l,mid,num<<1);
	solve(mid+1,r,num<<1|1);
	if(len[num<<1]<len[num<<1|1]){
		swap(len[num<<1],len[num<<1|1]);
		swap(poly[num<<1],poly[num<<1|1]);
	}
	for(i=0;i<=len[num<<1|1];i++) poly[num<<1][i]=add(poly[num<<1][i],poly[num<<1|1][i]);
	int *tmp=newint(min(K,len[num<<1]+len[num])+1);
	p::mul(tmp,poly[num],poly[num<<1],len[num],len[num<<1]);
	poly[num]=tmp;len[num]=min(K,(len[num<<1]+len[num]));
}
int main(){
	n=read();int i;
	for(i=1;i<=n;i++){
		q[i].l=read();
		q[i].r=read();
		q[i].p=read();
		hash[i]=q[i].l;
		hash[i+n]=q[i].r+1;
	}
	K=read();
	sort(hash+1,hash+(n<<1)+1);
	tot=unique(hash+1,hash+(n<<1)+1)-hash-1;
//	for(i=1;i<=tot;i++) cout<<i<<' '<<hash[i]<<'\n';
	for(i=1;i<=n;i++){
		q[i].l=lower_bound(hash+1,hash+tot+1,q[i].l)-hash;
		q[i].r=lower_bound(hash+1,hash+tot+1,q[i].r+1)-hash-1;
		seg::insert(1,tot-1,q[i].l,q[i].r,1,q[i].p);
	}
	solve(1,tot-1,1);
	printf("%d\n",poly[1][K]);
}
