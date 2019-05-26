#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define rank ddf
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
struct seg{
	int l,r;
}s[800010];int cnt;
struct segtree{
	int a[800010],lazy[800010];
	void push(int pos){
		if(!lazy[pos]) return;
//		cout<<"push "<<pos<<ends<<lazy[pos]<<endl;
		int son=pos<<1;
		a[son]=lazy[pos];a[son+1]=lazy[pos];lazy[pos]=0;
	}
	void update(int pos){
		int son=pos<<1;
		if(a[son]==a[son+1]) a[pos]=a[son];
		else a[pos]=-1; 
	}
	void change(int l,int r,int ql,int qr,int num,int t){
		push(num);
//		cout<<"change "<<l<<ends<<r<<ends<<ql<<ends<<qr<<ends<<num<<ends<<t<<endl; 
		int mid=(l+r)>>1,son=num<<1;
		if(l>=ql&&r<=qr){
			a[num]=lazy[num]=t;push(num);return;
		}
		if(mid>=ql) change(l,mid,ql,qr,son,t);
		if(mid<qr) change(mid+1,r,ql,qr,son+1,t);
		update(num);
	}
	int check(int l,int r,int num,int pos){
		push(num);
//		cout<<"check "<<l<<ends<<r<<ends<<num<<ends<<pos<<ends<<a[num]<<endl;
		if(~a[num]) return a[num];
		int mid=(l+r)>>1,son=num<<1;
		if(mid>=pos) return check(l,mid,son,pos);
		else return check(mid+1,r,son+1,pos);
	} 
}T;
struct d{
	int w,num,rank;
}a[200010];int n,rk[200010];
bool cmp(d l,d r){
	return l.w>r.w;
}
bool cmp2(d l,d r){
	return l.num<r.num;
}
int len[200010]={0},tot=0,ans=0,tans;
int main(){
	n=read();int i,tmp,belong,tl,tr;
	for(i=1;i<=n;i++) a[i].w=read(),a[i].num=i;
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++) a[i].rank=i,rk[i]=a[i].num;
	sort(a+1,a+n+1,cmp2);
	tot=1;cnt=1;
	T.change(1,n,1,n,1,1);
	s[1].l=1;s[1].r=n;
	ans=1;tans=a[rk[1]].w+1;
	for(i=1;i<n;i++){
		tmp=rk[i];
		belong=T.check(1,n,1,tmp);
		if(belong>20000000){
			puts("F**K!!!!");return 0;
		}
		tl=s[belong].l;tr=s[belong].r;
		if(tmp==tl&&tmp==tr){
			len[1]--;tot--;
			T.change(1,n,tmp,tmp,1,20000000+tmp);
		}
		if(tmp==tl&&tmp!=tr){
			len[tr-tl+1]--;len[tr-tl]++;
			T.change(1,n,tl+1,tr,1,++cnt);
			s[cnt].l=tl+1;s[cnt].r=tr;
			T.change(1,n,tl,tl,1,20000000+tl);
		}
		if(tmp==tr&&tmp!=tl){
			len[tr-tl+1]--;len[tr-tl]++;
			T.change(1,n,tl,tr-1,1,++cnt);
			s[cnt].l=tl;s[cnt].r=tr-1;
			T.change(1,n,tr,tr,1,20000000+tr);
		}
		if(tmp!=tl&&tmp!=tr){
			len[tr-tl+1]--;tot--;
			
			cnt++;tot++;
			len[tmp-tl]++;
			T.change(1,n,tl,tmp-1,1,cnt);
			s[cnt].l=tl;s[cnt].r=tmp-1; 
			
			cnt++;tot++;
			len[tr-tmp]++;
			T.change(1,n,tmp+1,tr,1,cnt);
			s[cnt].l=tmp+1;s[cnt].r=tr; 
			
			T.change(1,n,tmp,tmp,1,20000000+tmp);
		}
		if(len[s[cnt].r-s[cnt].l+1]==tot){
			if(tot>ans||(tot==ans&&tans>(a[rk[i+1]].w+1))){
				ans=tot;tans=(a[rk[i+1]].w+1);
			}
		}
	}
	printf("%d\n",tans);
}
