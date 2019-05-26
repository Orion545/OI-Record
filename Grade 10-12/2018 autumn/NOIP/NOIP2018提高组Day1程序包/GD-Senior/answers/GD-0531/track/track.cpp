#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct node{
	int v,c,nxt;
}e[100010];
int en,f[100010],maxn,ezs[60010];
int dfs(int u,int fa)
{
	int k1=0,k2=0;
	for (int i=f[u];i;i=e[i].nxt)
	 	if (e[i].v!=fa)
	 		{
	 			int k3=dfs(e[i].v,u)+e[i].c;
	 			if (k3>k1) k2=k1,k1=k3;
	 			 else if (k3>k2) k2=k3;
	 		}
	maxn=max(maxn,k1+k2);
	return k1;
}
void add(int u,int v,int c)
{
	++en;e[en].v=v;e[en].c=c;e[en].nxt=f[u];f[u]=en;
}
int n,m,sum;
int  dfs2(int u,int fa,int k)
{
	if (f[u]==0) return 0;
	int s=0;
	int a[ezs[u]+2];
	memset(a,0,sizeof(a));
  	for (int i=f[u];i;i=e[i].nxt)
	 if (fa!=e[i].v)
	 	 a[++s]=dfs2(e[i].v,u,k)+e[i].c;
	sort(a+1,a+s+1);
	int l=1,r=s,lxl=0,qian=0,hom=0;
	while (l+1<r)
	 {
	 	if (a[l]+a[r]<k) qian=l,l++;
	 	 else if (a[l]+a[r-1]<k)
	 	  sum++,l++,r--;else {
	 	  	 lxl=max(lxl,r);r--;hom++;
	 	  }
	 }
	if (a[l]+a[r]>=k) 
	 {
	 	sum++;
	 	sum+=(hom/2);
	 }
	if (hom%2==0){sum++;return qian;}
	return a[lxl];
}
bool check(int k)
{
	sum=0;
	if (dfs2(1,0,k)>=m) return true;else return false;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;++i)
	 {
	 	int x,y,z;
	 	scanf("%d%d%d",&x,&y,&z);
	 	add(x,y,z);
	 	add(y,x,z);
	 	ezs[x]++;ezs[y]++;
	 	sum+=z;
	 }
	if (m==1){
		maxn=max(maxn,dfs(1,0));
		cout<<maxn;
		return 0;
	}
	int l=1,r=sum/m;
	while (l<r)
	 {
	 	int mid=(l+r)/2;
	 	if (check(mid)) l=mid;
	 	 else r=mid-1;
	 }
	cout<<l;
 	return 0;
}
