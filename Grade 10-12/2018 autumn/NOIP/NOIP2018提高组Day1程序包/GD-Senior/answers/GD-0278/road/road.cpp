#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<vector>
#define INF 2147483647
using namespace std;
typedef long long ll;
struct node1{int m;ll sum;};
node1 tr[500500];
ll ans;
int a[100010],n;
priority_queue<int> q;
void build(int now,int l,int r)
{
	if (l==r) {tr[now].m=a[l]; tr[now].sum=a[l]; /*tr[now].L=l;tr[now].R=r;*/return;}
	int mid=(l+r)/2;
	build(now*2,l,mid);
	build(now*2+1,mid+1,r);
	tr[now].m=min(tr[now*2].m,tr[now*2+1].m);
	tr[now].sum=tr[now*2].sum+tr[now*2+1].sum;
	//tr[now].L=tr[now*2].L;
	//tr[now].R=tr[now*2+1].R;
}
void update(int now,int l,int r,int L,int R,int k)
{
	if (l>R || L>r) return;
	if (l==r && l>=L && R>=r) {tr[now].sum-=k,tr[now].m-=k; if (tr[now].sum==0) q.push(l);return;}
	int mid=(l+r)/2;
	update(now*2,l,mid,L,R,k);
	update(now*2+1,mid+1,r,L,R,k);
	tr[now].m=min(tr[now*2].m,tr[now*2+1].m);
	tr[now].sum=tr[now*2].sum+tr[now*2+1].sum;
} 
//ÐÞ¸ÄMinÖµ ºÍsum 
int query_Min(int now,int l,int r,int L,int R)
{
	
	if (l>R || r<L) return INF;
	if (l==r) return tr[now].m;
	if (l>=L && r<=R) return tr[now].m;
	int qMin=INF;
	int mid=(l+r)/2;
	qMin=min(query_Min(now*2,l,mid,L,R),query_Min(now*2+1,mid+1,r,L,R));
	return qMin;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	 {
	 	scanf("%d",&a[i]);
	 	if (a[i]==0) q.push(i);
	 }
	build(1,1,n);
	
	q.push(0);
	q.push(n+1);
	for (;tr[1].sum;)
	 {
	 	int tmp=q.top();
	 	q.pop();
	 	int tmp2=q.top();
	 	for (;tmp-1==tmp2 || tmp==tmp2;)
	 	 {
	 	 	tmp=tmp2;
	 	 	q.pop();
	 	 	tmp2=q.top();
	 	 }
	 	int L=tmp2+1,R=tmp-1;
	 	q.push(tmp);q.push(tmp2);
	 	int Min=query_Min(1,1,n,L,R);
	 	ans+=Min;
		update(1,1,n,L,R,Min);
	 }
	printf("%lld",ans);
	return 0;
}

