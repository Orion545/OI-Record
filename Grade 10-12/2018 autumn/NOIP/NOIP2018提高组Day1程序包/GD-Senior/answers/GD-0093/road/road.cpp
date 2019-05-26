#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int maxn=100010,INF=1e9+10;
int n,ans;
int a[maxn];
struct data
{
	int num,lazy;
}tree[4*maxn];

void build(int root,int L,int R)
{
	if (L==R) {tree[root].num=a[L];tree[root].lazy=0;return;}
	int mid=(L+R)/2;
	int Lson=root*2,Rson=root*2+1;
	build(Lson,L,mid);
	build(Rson,mid+1,R);
	tree[root].num=min(tree[Lson].num,tree[Rson].num);
}

void down(int root,int L,int R,int k)
{
	tree[L].num-=k;tree[L].lazy+=k;
	tree[R].num-=k;tree[R].lazy+=k;
	tree[root].lazy=0;
}

int query(int root,int L,int R,int i,int j)
{
	if (i<=L && R<=j) return tree[root].num;
	if (R<i || j<L) return INF;
	int mid=(L+R)/2;
	int Lson=root*2,Rson=root*2+1;
	down(root,Lson,Rson,tree[root].lazy);
	int now1=query(Lson,L,mid,i,j);
	int now2=query(Rson,mid+1,R,i,j);
	return min(now1,now2);
}

void updata(int root,int L,int R,int i,int j,int k)
{
	if (i<=L && R<=j) {tree[root].num-=k;tree[root].lazy+=k;return;}
	if (R<i || j<L) return;
	int mid=(L+R)/2;
	int Lson=root*2,Rson=root*2+1;
	down(root,Lson,Rson,tree[root].lazy);
	updata(Lson,L,mid,i,j,k);
	updata(Rson,mid+1,R,i,j,k);
	tree[root].num=min(tree[Lson].num,tree[Rson].num);
}

void made(int L,int R,int k)
{
	if (L>R) return;
	
	int now=query(1,1,n,L,R);
	updata(1,1,n,L,R,now);
	ans+=now;
	
	int star=L;
	for (register int i=L;i<=R;i++)
		if (a[i]-(k+now)==0) {made(star,i-1,k+now);star=i+1;}
	made(star,R,k+now);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	build(1,1,n);
	made(1,n,0);
	printf("%d\n",ans);
	
	return 0;
}
