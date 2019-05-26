#include <cmath>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
//Constant
const int N=100000;
const int T=N*4;
//Quick Read
int Read(){
	int x=0;
	bool neg=false;
	char c=getchar();
	while(isdigit(c)==false)neg^=c=='-',c=getchar();
	while(isdigit(c)==true)x=x*10+c-'0',c=getchar();
	return x;
}
void Read(int &x){x=Read();}
//Segment Tree
struct Data{
	int pos,min;
	Data(int pos=0,int min=0):pos(pos),min(min){}
	friend bool operator<(Data x,Data y){return x.min<y.min;}
	friend void operator+=(Data &x,int val){x.min+=val;}
};
struct Segment_Tree{
	#define lc x<<1
	#define rc x<<1|1
	int lazy[T+1];
	Data val[T+1];
	inline void Push_Up(int x){val[x]=std::min(val[lc],val[rc]);}
	inline void Add(int x,int add){val[x]+=add,lazy[x]+=add;}
	void Push_Down(int x){
		if(lazy[x]==0)return;
		Add(lc,lazy[x]),Add(rc,lazy[x]);
		lazy[x]=0;
	}
	void Insert(int x,int l,int r,int pos,int min){
		if(l==r){
			val[x]=Data(pos,min);
			return;
		}
		int mid=l+r>>1;
		if(pos<=mid)Insert(lc,l,mid,pos,min);
		else Insert(rc,mid+1,r,pos,min);
		Push_Up(x);
	}
	void Modify(int x,int l,int r,int ql,int qr,int add){
		if(l==ql&&r==qr){
			Add(x,add);
			return;
		}
		Push_Down(x);
		int mid=l+r>>1;
		if(qr<=mid)Modify(lc,l,mid,ql,qr,add);
		else if(ql>mid)Modify(rc,mid+1,r,ql,qr,add);
		else Modify(lc,l,mid,ql,mid,add),Modify(rc,mid+1,r,mid+1,qr,add);
		Push_Up(x);
	}
	Data Query(int x,int l,int r,int ql,int qr){
		if(l==ql&&r==qr)return val[x];
		Push_Down(x);
		Data ans;
		int mid=l+r>>1;
		if(qr<=mid)ans=Query(lc,l,mid,ql,qr);
		else if(ql>mid)ans=Query(rc,mid+1,r,ql,qr);
		else ans=std::min(Query(lc,l,mid,ql,mid),Query(rc,mid+1,r,mid+1,qr));
		Push_Up(x);
		return ans;
	}
	#undef lc
	#undef rc
}seg;
//Solve
int n,ans;
void Solve(int l,int r){
	if(l>r)return;
	Data temp=seg.Query(1,1,n,l,r);
	if(temp.min!=0)seg.Modify(1,1,n,l,r,-temp.min),ans+=temp.min;
	Solve(l,temp.pos-1),Solve(temp.pos+1,r);
}
//Main
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	Read(n);
	for(int i=1;i<=n;++i)seg.Insert(1,1,n,i,Read());
	Solve(1,n);
	printf("%d\n",ans);
	return 0;
}
