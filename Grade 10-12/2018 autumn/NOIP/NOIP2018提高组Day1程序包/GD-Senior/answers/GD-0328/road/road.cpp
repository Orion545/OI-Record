#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[100005],c[100005],b,p,ans,mina[400005],mini[400005],add[400005],i,j,n;
int oo=10000000;
void build(int now,int L,int R)
{
	if (L==R) { mina[now]=a[L]; mini[now]=L;return;}
	int mid=(L+R)/2;
	build(now*2,L,mid);
	build(now*2+1,mid+1,R);
	mina[now]=min(mina[now*2],mina[now*2+1]);
	if (mina[now*2]<=mina[now*2+1]) mini[now]=mini[now*2]; else mini[now]=mini[now*2+1];
}
void down(int root,int l,int r)
{
	int ls=root*2,rs=root*2+1;
	mina[ls]+=add[root];
	mina[rs]+=add[root];
	add[ls]+=add[root];
	add[rs]+=add[root];
	add[root]=0;
}
int query(int now,int L,int R,int s,int t)
{
	if (s<=L&&R<=t)  
	{
		return mina[now];
	}
	if (L>t||R<s) return oo;
	down(now,L,R);
	int mid=(L+R)/2;
	int w,w2;
    w=query(now*2,L,mid,s,t);
	w2=query(now*2+1,mid+1,R,s,t);
    return min(w,w2);
}
int query2(int now,int L,int R,int s,int t)
{
	if (s<=L&&R<=t)  
	{
		return mini[now];
	}
	if (L>t||R<s) return 0;
	down(now,L,R);
	int mid=(L+R)/2;
	int w,w2;
    w=query2(now*2,L,mid,s,t);
	w2=query2(now*2+1,mid+1,R,s,t);
    if (a[w]<=a[w2]) return w; else return w2;
}
void update(int now,int L,int R,int s,int t,int v)
{
	if (s<=L&&R<=t)  
	{
		add[now]+=v;
		mina[now]+=v;
		return;
	}
	if (L>t||R<s) return;
	down(now,L,R);
	int mid=(L+R)/2;
	update(now*2,L,mid,s,t,v);
	update(now*2+1,mid+1,R,s,t,v);
	mina[now]=min(mina[now*2],mina[now*2+1]);
	if (mina[now*2]<=mina[now*2+1]) mini[now]=mini[now*2]; else mini[now]=mini[now*2+1];
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;++i) scanf("%d",&a[i]);
	a[0]=oo;
	build(1,1,n);
	c[n+1]=1;
	i=1; j=n+1;
	while(i<=n)
	 {
	 	b=query(1,1,n,i,j-1);
	 	p=query2(1,1,n,i,j-1);
	 	update(1,1,n,i,j-1,-b);
		j=p; c[p]=1; ans+=b;
	 	if (j==i)
	 	 {
	 	 	while(c[i]==1) i++;
	 	 	j=i;
	 	 	while(c[j]!=1) j++;
	 	 }
	 }
	cout<<ans;
	return 0;
}
