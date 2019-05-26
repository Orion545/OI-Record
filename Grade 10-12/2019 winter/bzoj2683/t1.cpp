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
int len;
namespace BIT{
	int a[500010];
	inline void add(int x,int val){
//		cout<<"	add "<<x<<' '<<val<<'\n';fflush(stdout);
		if(x==0) return;
		for(;x<=len;x+=(x&(-x))) a[x]+=val;
	}
	inline int sum(int x){
		int re=0;
		for(;x;x^=(x&(-x))) re+=a[x];
		return re;
	}
}
struct query{
	int x,y,k,id,val;
	inline bool operator <(const query r)const{
		if(x!=r.x) return x<r.x;
		return id<r.id;
	}
}a[800010],tmp[800010];int cnt;
int ans[200010],cntq;
void solve(int l,int r){
	if(l>=r){assert(a[l].id==l);return;}
//	cout<<"solve "<<l<<' '<<r<<' '<<a[l].id<<'\n';fflush(stdout);
	int i,j,cntl,cntr,cur,mid=(l+r)>>1;

	cntl=l-1;cntr=mid;
	for(i=l;i<=r;i++){
		if(a[i].id<=mid) tmp[++cntl]=a[i];
		else tmp[++cntr]=a[i];
	}
	for(i=l;i<=r;i++) a[i]=tmp[i];

	solve(l,mid);

	j=l;
	for(i=mid+1;i<=r;i++){
		if(a[i].k==0) continue;
		for(;j<=mid&&a[j].x<=a[i].x;j++) if(a[j].k==0) BIT::add(a[j].y,a[j].val);
		ans[a[i].k]+=a[i].val*BIT::sum(a[i].y);
//		if(a[i].k==34) cout<<"change "<<a[i].x<<' '<<a[i].y<<' '<<a[i].val<<' '<<BIT::sum(a[i].y)<<'\n';
	}
	for(i=l;i<j;i++) if(a[i].k==0) BIT::add(a[i].y,-a[i].val);
	
	solve(mid+1,r);
	
	merge(a+l,a+mid+1,a+mid+1,a+r+1,tmp+l);
	for(i=l;i<=r;i++) a[i]=tmp[i];
//	cout<<"finish solve "<<l<<' '<<r<<'\n';
}
int main(){
	len=read();cnt=cntq=0;int t1,t2,t3,t4,tq;
	while((tq=read())&&(tq!=3)){
		if(tq==1){
			t1=read();t2=read();t3=read();
			cnt++;
			a[cnt].x=t1;a[cnt].y=t2;
			a[cnt].k=0;a[cnt].id=cnt;a[cnt].val=t3;
		}
		else{
			t1=read();t2=read();t3=read();t4=read();
			cnt++;cntq++;
			a[cnt].x=t1-1;a[cnt].y=t2-1;
			a[cnt].k=cntq;a[cnt].id=cnt;a[cnt].val=1;
			cnt++;
			a[cnt].x=t1-1;a[cnt].y=t4;
			a[cnt].k=cntq;a[cnt].id=cnt;a[cnt].val=-1;
			cnt++;
			a[cnt].x=t3;a[cnt].y=t2-1;
			a[cnt].k=cntq;a[cnt].id=cnt;a[cnt].val=-1;
			cnt++;
			a[cnt].x=t3;a[cnt].y=t4;
			a[cnt].k=cntq;a[cnt].id=cnt;a[cnt].val=1;
		}
	}
	sort(a+1,a+cnt+1);
//	for(int i=1;i<=cnt;i++) cout<<"check input "<<i<<' '<<a[i].x<<' '<<a[i].y<<' '<<a[i].k<<' '<<a[i].id<<' '<<a[i].val<<'\n';
	solve(1,cnt);
	for(int i=1;i<=cntq;i++) printf("%d\n",ans[i]);
}
