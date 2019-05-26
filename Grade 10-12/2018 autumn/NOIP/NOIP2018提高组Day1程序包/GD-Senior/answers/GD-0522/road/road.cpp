#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;
struct data{
	int x,d;
	friend bool operator<(data a,data b){
		return a.d<b.d;
	}
}rd[100100];
int sum[400100],sum2[400010],add[400010];
int n,ans;
void update(int o,int l,int r,int pos,int v){
	if(l==r){
		sum[o]+=v;
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid)update(o*2,l,mid,pos,v);
	else update(o*2+1,mid+1,r,pos,v);
	sum[o]=sum[o*2]+sum[o*2+1];
}
int query(int o,int l,int r,int x,int y){
	if(x<=l&&y>=r)return sum[o];
	if(x>r||y<l)return 0;
	int mid=(l+r)/2;
	if(y<=mid)return query(o*2,l,mid,x,y);
	else if(x>mid)return query(o*2+1,mid+1,r,x,y);
	else return query(o*2,l,mid,x,mid)+query(o*2+1,mid+1,r,mid+1,y);
}
void update2(int o,int l,int r,int x,int y,int v){
	if(x>r||y<l)return;
	if(x<=l&&y>=r){
		sum2[o]+=v;
		add[o]+=v;
	}
	else{
		update2(o*2,l,(l+r)/2,x,y,v);
		update2(o*2+1,(l+r)/2+1,r,x,y,v);
		sum2[o]=sum2[o*2]+sum2[o*2+1]+add[o]*(r-l+1);
	}
}
int query2(int o,int l,int r,int x,int y,int a){
	if(x<=l&&y>=r)return sum2[o]+(r-l+1)*a;
	if(x>r||y<l)return 0;
	int mid=(l+r)/2;
	if(y<=mid)return query2(o*2,l,mid,x,y,a+add[o]);
	else if(x>mid)return query2(o*2+1,mid+1,r,x,y,a+add[o]);
	else return query2(o*2,l,mid,x,mid,a+add[o])+query2(o*2+1,mid+1,r,mid+1,y,a+add[o]);
}
int c1[233333],c2[233333];
void inc1(int pos,int v){
	for(int i=pos;i<=n;i+=(i&(-i)))c1[i]+=v;
}
void inc2(int pos,int v){
	for(int i=pos;i<=n;i+=(i&-i))c2[i]+=v;
}
int calc1(int pos){
	int res=0;
	for(int i=pos;i;i-=(i&(-i)))res+=c1[i];
	return res;
}
int calc2(int pos){
	int res=0;
	for(int i=pos;i;i-=(i&(-i)))res+=c2[i];
	return res;
}
void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		read(rd[i].d);
		rd[i].x=i;
		update2(1,1,n,i,i,rd[i].d);
	}
	sort(rd+1,rd+n+1);
	for(int i=1;i<=n;++i){
		int pos=rd[i].x;
		int l=pos;
		for(int j=17;j>=0;--j){
			int tmp=l-(1<<j);
			if(tmp<=0)continue;
			if(calc1(pos)-calc1(tmp)==0)l=tmp;
		}
		int r=pos;
		for(int j=17;j>=0;--j){
			int tmp=r+(1<<j);
			if(tmp>n)continue;
			if(calc1(tmp)-calc1(pos)==0)r=tmp;
		}
		int tt=query2(1,1,n,pos,pos,0);
		inc1(pos,1);
		update2(1,1,n,l,r,-query2(1,1,n,pos,pos,0));
		ans+=tt;
	}
	cout<<ans;
}
//6 4 3 2 5 3 5
