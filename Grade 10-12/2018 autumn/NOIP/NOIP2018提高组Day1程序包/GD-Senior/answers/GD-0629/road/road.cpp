#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int mx=1e5+10;
int n;
int a[mx];
int rmq[mx][20],lg[mx],rp[mx][20];
int ans=0;

inline int read()
{
	char ch=0;
	int w=0,x=0;
	while(!isdigit(ch)) w|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return w?-x:x;
}

void getrmq()
{
	lg[0]=lg[1]=0;
	for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++) rmq[i][0]=a[i],rp[i][0]=i;
	for(int k=1;k<=18;k++)
		for(int i=1;i+(1<<k)-1<=n;i++)
		{
			rmq[i][k]=min(rmq[i][k-1],rmq[i+(1<<(k-1))][k-1]);
			if(rmq[i][k-1]<rmq[i+(1<<(k-1))][k-1]) rp[i][k]=rp[i][k-1];
			else rp[i][k]=rp[i+(1<<(k-1))][k-1];
		}
}

int askrmq(int l,int r)
{
	if(l>r) swap(l,r);
	int k=lg[r-l+1];
	return min(rmq[l][k],rmq[r-(1<<k)+1][k]);
}

int askrp(int l,int r)
{
	if(l>r) swap(l,r);
	int k=lg[r-l+1];
	if(rmq[l][k]<rmq[r-(1<<k)+1][k]) return rp[l][k];
	else return rp[r-(1<<k)+1][k];
}



void solve(int l,int r,int cnt)
{
	if(l>r) return ;
	if(l==r)
	{
		ans+=a[l]-cnt;
		return ;
	}
	int p=askrp(l,r);
	
/*	cerr<<l<<" "<<r<<endl;
	for(int i=l;i<=r;i++)
		cerr<<a[i]<<" ";
	cerr<<endl;
*/	
	
	ans+=a[p]-cnt;
	solve(l,p-1,a[p]);
	solve(p+1,r,a[p]);	
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	getrmq();
	solve(1,n,0);
	printf("%d\n",ans);
	
	return 0;
}
