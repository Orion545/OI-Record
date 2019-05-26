#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
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
int n,q,a[100010];char s[100010];
namespace seg{
	struct node{
		int a[26];
		void getval(int val,int num){
			memset(a,0,sizeof(a));
			a[val]=num;
		}
		void merge(node l,node r){
//			cout<<"				begin merge\n";
			for(int i=0;i<26;i++){
				a[i]=l.a[i]+r.a[i];
//				if(a[i]) cout<<"			merging "<<i<<' '<<a[i]<<'\n';
			}
		}
	}seg[400010];
	int over[400010];
	inline void push(int l,int r,int num){
		if(l==r||over[num]==-1) return;
		int mid=(l+r)>>1;
		over[num<<1]=over[num<<1|1]=over[num];
		seg[num<<1].getval(over[num],mid-l+1);
		seg[num<<1|1].getval(over[num],r-mid);
	}
	void build(int l,int r,int num){
		if(l==r){seg[num].getval(a[l],1);over[num]=a[l];return;}
		int mid=(l+r)>>1;
		build(l,mid,num<<1);build(mid+1,r,num<<1|1);
		seg[num].merge(seg[num<<1],seg[num<<1|1]);
		if(over[num<<1]==over[num<<1|1]) over[num]=over[num<<1];
		else over[num]=-1;
	}
	void query(int l,int r,int ql,int qr,int num,node &re){
		push(l,r,num);re.getval(0,0);
//		cout<<"		query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<num<<' '<<over[num]<<'\n';
		if(l>=ql&&r<=qr){re=seg[num];return;}
		if(over[num]!=-1){
			if(l<=ql) l=ql;
			if(r>=qr) r=qr;
			re.getval(over[num],r-l+1);
			return;
		}
		int mid=(l+r)>>1;node tmp;
		if(mid>=ql) query(l,mid,ql,qr,num<<1,tmp),re.merge(re,tmp);
		if(mid<qr) query(mid+1,r,ql,qr,num<<1|1,tmp),re.merge(re,tmp);
	}
	void change(int l,int r,int ql,int qr,int num,int val){
		push(l,r,num);
//		cout<<"		change "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<num<<' '<<val<<'\n';
		if(l>=ql&&r<=qr){seg[num].getval(val,r-l+1);over[num]=val;return;}
		int mid=(l+r)>>1;
		if(mid>=ql) change(l,mid,ql,qr,num<<1,val);
		if(mid<qr) change(mid+1,r,ql,qr,num<<1|1,val);
		seg[num].merge(seg[num<<1],seg[num<<1|1]);
		if(over[num<<1]==over[num<<1|1]) over[num]=over[num<<1];
		else over[num]=-1;
	}
	void output(int l,int r,int num){
		push(l,r,num);
		if(l==r){putchar(over[num]+'a');return;}
		int mid=(l+r)>>1;
		output(l,mid,num<<1);output(mid+1,r,num<<1|1);
	}
}
int main(){
	using namespace seg;
	memset(over,-1,sizeof(over));
	n=read();q=read();scanf("%s",s);int i,j,t1,t2,t3;node tmp;
	for(i=1;i<=n;i++) a[i]=(int)(s[i-1]-'a');
//	for(i=1;i<=n;i++) cout<<a[i];
//	cout<<'\n';
	build(1,n,1);
	while(q--){
		t1=read();t2=read();t3=read();
//		cout<<"input query "<<t1<<' '<<t2<<' '<<t3<<'\n';
		tmp.getval(0,0);
		query(1,n,t1,t2,1,tmp);
		j=t1;
		if(t3){
			for(i=0;i<26;i++){
				if(!tmp.a[i]) continue;
//				cout<<"	counted "<<i<<' '<<tmp.a[i]<<'\n';
				change(1,n,j,j+tmp.a[i]-1,1,i);
				j+=tmp.a[i];
			}
		}
		else{
			for(i=25;i>=0;i--){
				if(!tmp.a[i]) continue;
//				cout<<"	counted "<<i<<' '<<tmp.a[i]<<'\n';
				change(1,n,j,j+tmp.a[i]-1,1,i);
				j+=tmp.a[i];
			}
		}
	}
	output(1,n,1);
}
