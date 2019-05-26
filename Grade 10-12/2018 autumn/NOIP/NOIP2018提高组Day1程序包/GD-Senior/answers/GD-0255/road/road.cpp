#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int N=1e5+5;
const int INF=0x3f3f3f3f;

int n,ans=0;
int add[N<<2],a[N<<2],minn[N<<2];

template <class T> inline void qread(T &x){
	x=0;
	char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}

void update(int k,int l,int r,int v){
	add[k]+=v;
	minn[k]+=v;
	return;
}

void pushdown(int k,int l,int r){
	add[k<<1]+=add[k];
	minn[k<<1]+=add[k];
	add[(k<<1)|1]+=add[k];
	minn[(k<<1)|1]+=add[k];
	add[k]=0;
}

int query(int k,int l,int r){
	if (add[k]<0&&l!=r) pushdown(k,l,r);
	if (minn[k]) return minn[k];
	if (l==r) return INF;
	int mid=(l+r)>>1;
	return min(query(k<<1,l,mid),query((k<<1)|1,mid+1,r));
}

void build(int k,int l,int r){
	if (l==r){
		minn[k]=a[l];
		return;
	}
	else{
		int mid=(l+r)>>1;
		build(k<<1,l,mid);
		build((k<<1)|1,mid+1,r);
		minn[k]=min(minn[k<<1],minn[(k<<1)|1]);
	}
}

void operate(int k,int l,int r,int v){
	if (minn[k]){
		update(k,l,r,v);
		return;
	}
	if (l==r) return;
	int mid=(l+r)>>1;
	if (query(k<<1,l,mid)!=INF) operate(k<<1,l,mid,v);
	else operate((k<<1)|1,mid+1,r,v);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	qread(n);
	memset(add,0,sizeof(add));
	for (int i=1;i<=n;i++) qread(a[i]);
	build(1,1,n);
	int v=query(1,1,n);
	while (v!=INF){
		operate(1,1,n,-v);
		ans+=v;
		v=query(1,1,n);
//		cout<<v<<"\n";
	}
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
