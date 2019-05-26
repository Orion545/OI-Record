#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
struct Node{
	int y,next,c;
}a[100010];int len=0,last[50010];
struct node{
	int a,b;
	node() {}
	node(int x,int y) {a=x;b=y;}
};
void ins(int x,int y,int c)
{
	a[++len].y=y;a[len].c=c;
	a[len].next=last[x];last[x]=len;
}
int tot=0,q[50010],f[50010],L[50010],R[50010];
int insert(int x,int y) {L[y]=x;R[x]=y;return x;}
int del(int x)
{
	int y=R[x];
	R[x]=0;L[y]=0;
	return y;
}
node solve(int l,int r,int K)
{
	sort(q+1,q+r+1);
	node ans=node(0,0);
	while(l<=r&&q[r]>=K) ans.a++,r--;
	if(l>r) return ans;
	int x=0,t=0;
	for(int i=l;i<=r;i++) L[i]=R[i]=0;
	while(l<r&&q[l]+q[r]<K) t=l,l++;
	if(l>=r) node(ans.a,q[r]);
	while(l<r)
	{
		while(l<r-1&&q[l]+q[r-1]>=K) x=insert(r,x),r--;
		if(q[l]+q[r]>=K) ans.a++,r--;
		else
		{
			if(x!=0) x=del(x),ans.a++;
			else t=l;
		}
		l++;
	}
	if(l==r)
	{
		if(x) x=del(x),ans.a++;
		else t=l;
	}
	int cnt=0;
	while(x)
	{
		cnt++;ans.b=q[x];
		x=del(x);
	}
	ans.a+=cnt/2;
	if(cnt%2==0) ans.b=q[t];
	return ans;
}
void dfs(int x,int fa,int K)
{
	f[x]=0;
	for(int i=last[x];i;i=a[i].next) if(a[i].y!=fa)
		dfs(a[i].y,x,K);
	int l=1,r=0;
	for(int i=last[x];i;i=a[i].next) if(a[i].y!=fa)
		q[++r]=f[a[i].y]+a[i].c;
	if(r==0) return;
	sort(q+1,q+r+1);
	node t=solve(l,r,K);
	tot+=t.a;f[x]=t.b;
	return;
}
bool check(int k)
{
	tot=0;dfs(1,0,k);
	return tot>=m;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	int sum=0;
	for(int i=1;i<n;i++)
	{
		int x,y,c;scanf("%d %d %d",&x,&y,&c);
		ins(x,y,c);ins(y,x,c);sum+=c;
	}
	int l=1,r=sum/m,ans=1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",ans);
}
