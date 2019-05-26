/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#define mp make_pair
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
int n,m,q;
struct BIT{
	ll a[2010][2010];
	inline int lowbit(int i){return i&(-i);}
	void add(int x,int y,ll val){
		int i;
		cout<<"add "<<x<<' '<<y<<' '<<val<<'\n';
		while(x<=n){
			for(i=y;i<=n;i+=lowbit(i)) a[x][i]+=val;
			x+=lowbit(x);
		}
	}
	ll sum(int x,int y){
		ll re=0;int i;
		while(x){
			for(i=y;i;i-=lowbit(i)) re+=a[x][i];
			x-=lowbit(x);
		}
		return re;
	}
}A,B,C;
map<pair<pair<int,int>,pair<int,int> >,ll>sa,sb,sc;
int main(){
	freopen("z.in","r",stdin);
	freopen("z.out","w",stdout);
	srand(19260817);
	n=read();m=read();q=read();
	int t1,t2,t3,t4,t5;
	ll tmp,a1,b1,c1,a2,b2,c2;
	while(q--){
		t5=read();
		t1=read();t2=read();t3=read();t4=read();
		if(t5==1){
			tmp=(ll)rand()*(ll)rand()%100000000000000ll;
			sa[mp(mp(t1,t3),mp(t2,t4))]=tmp;
			A.add(t1,t2,tmp);
			A.add(t1,t4+1,-tmp);
			A.add(t3+1,t2,-tmp);
			A.add(t3+1,t4+1,tmp);
			
			tmp=(ll)rand()*(ll)rand()%100000000000000ll;
			sb[mp(mp(t1,t3),mp(t2,t4))]=tmp;
			B.add(t1,t2,tmp);
			B.add(t1,t4+1,-tmp);
			B.add(t3+1,t2,-tmp);
			B.add(t3+1,t4+1,tmp);
			
			tmp=(ll)rand()*(ll)rand()%100000000000000ll;
			sc[mp(mp(t1,t3),mp(t2,t4))]=tmp;
			C.add(t1,t2,tmp);
			C.add(t1,t4+1,-tmp);
			C.add(t3+1,t2,-tmp);
			C.add(t3+1,t4+1,tmp);
		}
		if(t5==2){
			tmp=sa[mp(mp(t1,t3),mp(t2,t4))];
			A.add(t1,t2,-tmp);
			A.add(t1,t4+1,tmp);
			A.add(t3+1,t2,tmp);
			A.add(t3+1,t4+1,-tmp);
			sa.erase(mp(mp(t1,t3),mp(t2,t4)));
			
			tmp=sb[mp(mp(t1,t3),mp(t2,t4))];
			B.add(t1,t2,-tmp);
			B.add(t1,t4+1,tmp);
			B.add(t3+1,t2,tmp);
			B.add(t3+1,t4+1,-tmp);
			sb.erase(mp(mp(t1,t3),mp(t2,t4)));
			
			tmp=sc[mp(mp(t1,t3),mp(t2,t4))];
			C.add(t1,t2,-tmp);
			C.add(t1,t4+1,tmp);
			C.add(t3+1,t2,tmp);
			C.add(t3+1,t4+1,-tmp);
			sc.erase(mp(mp(t1,t3),mp(t2,t4)));
		}
		if(t5==3){
			a1=A.sum(t1,t2);
			b1=B.sum(t1,t2);
			c1=C.sum(t1,t2);
			a2=A.sum(t3,t4);
			b2=B.sum(t3,t4);
			c2=C.sum(t3,t4);
			if(a1!=a2||b1!=b2||c1!=c2) puts("No");
			else puts("Yes");
		}
	}
}
/*
5 6 5
1 2 2 4 5
1 3 3 3 3
3 4 4 1 1
2 2 2 4 5
3 1 1 4 4

*/
