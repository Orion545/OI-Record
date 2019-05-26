#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
#define dtz 1023
#define id(A,B,C,D) ((A<<30)+(B<<20)+(C<<10)+D)
#define get1(A) (A>>30)
#define get2(A) ((A>>20)&dtz)
#define get3(A) ((A>>10)&dtz)
#define get4(A) (A&dtz)
#define rotate(A) (((A&dtz)<<30)|(A>>10))
#define MOD 19260817
#define next DEEP_DARK_FANTASY
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
namespace HASH{
	int first[MOD],cnt,next[10010],siz[10010];ll w[10010];
	void insert(ll val,int num){
		int pval=val%MOD,u=first[pval];
//		cout<<"	insert "<<val<<' '<<pval<<' '<<num<<'\n';
		if(!u){
			cnt++;
			first[pval]=cnt;w[cnt]=val;siz[cnt]=num;
			return;
		}
		for(;next[u]&(w[u]!=val);u=next[u]);
		if(w[u]==val) siz[u]+=num;
		else{
			cnt++;
			next[u]=cnt;
			w[cnt]=val;
			siz[cnt]=num;
		}
	}
	int query(ll val){
		int pval=val%MOD,u=first[pval];
		for(;u&&next[u]&&(w[u]!=val);u=next[u]);
//		cout<<"	query "<<val<<' '<<pval<<' '<<((w[u]==val)?siz[u]:0)<<'\n';
		return w[u]==val?siz[u]:0;
	}
}
void change(ll val,int num){
	HASH::insert(val,num);
	val=rotate(val);
	HASH::insert(val,num);
	val=rotate(val);
	HASH::insert(val,num);
	val=rotate(val);
	HASH::insert(val,num);
}
int n;ll c0[510],c1[510],c2[510],c3[510];
int main(){
	n=read();int i,j;ll t1,t2,t3,t4,ans=0,cur,val;
	for(i=1;i<=n;i++){
		t1=read();t2=read();t3=read();t4=read();
		c0[i]=id(t1,t2,t3,t4);
		c1[i]=id(t2,t3,t4,t1);
		c2[i]=id(t3,t4,t1,t2);
		c3[i]=id(t4,t1,t2,t3);
		HASH::insert(c0[i],1);
		HASH::insert(c1[i],1);
		HASH::insert(c2[i],1);
		HASH::insert(c3[i],1);
	}
	for(i=1;i<n;i++){
		HASH::insert(c0[i],-1);
		HASH::insert(c1[i],-1);
		HASH::insert(c2[i],-1);
		HASH::insert(c3[i],-1);
		for(j=i+1;j<=n;j++){
			HASH::insert(c0[j],-1);
			HASH::insert(c1[j],-1);
			HASH::insert(c2[j],-1);
			HASH::insert(c3[j],-1);
//			cout<<"do "<<i<<' '<<j<<' '<<ans<<'\n';
//			**********************************************************************0 degree rotation
			cur=1;
			//in face 1
			t1=id(get2(c0[i]),get1(c0[i]),get2(c0[j]),get1(c0[j]));
			val=HASH::query(t1);cur*=val;
			if(!val) goto jump_0_1;
			change(t1,-1);
			//in face 2
			t2=id(get2(c1[i]),get1(c1[i]),get2(c3[j]),get1(c3[j]));
			val=HASH::query(t2);cur*=val;
			if(!val) goto jump_0_2;
			change(t2,-1);
			//in face 3
			t3=id(get2(c2[i]),get1(c2[i]),get2(c2[j]),get1(c2[j]));
			val=HASH::query(t3);cur*=val;
			if(!val) goto jump_0_3;
			change(t3,-1);
			//in face 4
			t4=id(get2(c3[i]),get1(c3[i]),get2(c1[j]),get1(c1[j]));
			val=HASH::query(t4);cur*=val;
//			if(!val) goto jump_0_4;
//			change(t4,-1);
			//back face 4
//			change(t4,1);
//			jump_0_4:
			//back face 3
			change(t3,1);
			jump_0_3:
			//back face 2
			change(t2,1);
			jump_0_2:
			//back face 1
			change(t1,1);
			jump_0_1:
			ans+=cur;
//			cout<<"finish 0 degree "<<t1<<' '<<t2<<' '<<t3<<' '<<t4<<'\n';
//			**********************************************************************90 degree rotation counter-clockwise
			cur=1;
			//in face 1
			t1=id(get2(c0[i]),get1(c0[i]),get3(c0[j]),get2(c0[j]));
			val=HASH::query(t1);cur*=val;
			if(!val) goto jump_90_1;
			change(t1,-1);
			//in face 2
			t2=id(get2(c1[i]),get1(c1[i]),get3(c3[j]),get2(c3[j]));
			val=HASH::query(t2);cur*=val;
			if(!val) goto jump_90_2;
			change(t2,-1);
			//in face 3
			t3=id(get2(c2[i]),get1(c2[i]),get3(c2[j]),get2(c2[j]));
			val=HASH::query(t3);cur*=val;
			if(!val) goto jump_90_3;
			change(t3,-1);
			//in face 4
			t4=id(get2(c3[i]),get1(c3[i]),get3(c1[j]),get2(c1[j]));
			val=HASH::query(t4);cur*=val;
//			if(!val) goto jump_90_4;
//			change(t4,-1);
			//back face 4
//			change(t4,1);
//			jump_90_4:
			//back face 3
			change(t3,1);
			jump_90_3:
			//back face 2
			change(t2,1);
			jump_90_2:
			//back face 1
			change(t1,1);
			jump_90_1:
			ans+=cur;
//			cout<<"finish 90 degree "<<t1<<' '<<t2<<' '<<t3<<' '<<t4<<'\n';
//			**********************************************************************180 degree rotation counter-clockwise
			cur=1;
			//in face 1
			t1=id(get2(c0[i]),get1(c0[i]),get4(c0[j]),get3(c0[j]));
			val=HASH::query(t1);cur*=val;
			if(!val) goto jump_180_1;
			change(t1,-1);
			//in face 2
			t2=id(get2(c1[i]),get1(c1[i]),get4(c3[j]),get3(c3[j]));
			val=HASH::query(t2);cur*=val;
			if(!val) goto jump_180_2;
			change(t2,-1);
			//in face 3
			t3=id(get2(c2[i]),get1(c2[i]),get4(c2[j]),get3(c2[j]));
			val=HASH::query(t3);cur*=val;
			if(!val) goto jump_180_3;
			change(t3,-1);
			//in face 4
			t4=id(get2(c3[i]),get1(c3[i]),get4(c1[j]),get3(c1[j]));
			val=HASH::query(t4);cur*=val;
//			if(!val) goto jump_180_4;
//			change(t4,-1);
			//back face 4
//			change(t4,1);
//			jump_180_4:
			//back face 3
			change(t3,1);
			jump_180_3:
			//back face 2
			change(t2,1);
			jump_180_2:
			//back face 1
			change(t1,1);
			jump_180_1:
			ans+=cur;
//			cout<<"finish 180 degree "<<t1<<' '<<t2<<' '<<t3<<' '<<t4<<'\n';
//			**********************************************************************270 degree rotation counter-clockwise
			cur=1;
			//in face 1
			t1=id(get2(c0[i]),get1(c0[i]),get1(c0[j]),get4(c0[j]));
			val=HASH::query(t1);cur*=val;
			if(!val) goto jump_270_1;
			change(t1,-1);
			//in face 2
			t2=id(get2(c1[i]),get1(c1[i]),get1(c3[j]),get4(c3[j]));
			val=HASH::query(t2);cur*=val;
			if(!val) goto jump_270_2;
			change(t2,-1);
			//in face 3
			t3=id(get2(c2[i]),get1(c2[i]),get1(c2[j]),get4(c2[j]));
			val=HASH::query(t3);cur*=val;
			if(!val) goto jump_270_3;
			change(t3,-1);
			//in face 4
			t4=id(get2(c3[i]),get1(c3[i]),get1(c1[j]),get4(c1[j]));
			val=HASH::query(t4);cur*=val;
//			if(!val) goto jump_270_4;
//			change(t4,-1);
			//back face 4
//			change(t4,1);
//			jump_270_4:
			//back face 3
			change(t3,1);
			jump_270_3:
			//back face 2
			change(t2,1);
			jump_270_2:
			//back face 1
			change(t1,1);
			jump_270_1:
			ans+=cur;
//			cout<<"finish 270 degree "<<t1<<' '<<t2<<' '<<t3<<' '<<t4<<'\n';
//			******************************back j
			HASH::insert(c0[j],1);
			HASH::insert(c1[j],1);
			HASH::insert(c2[j],1);
			HASH::insert(c3[j],1);
		}
	}
	printf("%lld\n",ans);
}
