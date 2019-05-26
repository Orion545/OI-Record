#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

const int maxn=200000;
const int INF=2000000;

struct brr{
	int s,wz;
};

struct arr{
	int l,r;
	brr s;
	int b;
}f[maxn*3];

int n;

brr bs(brr a,brr b)
{
	if (a.s<=b.s) return a;
	else return b; 
}

void ins(int r,int x,int y,brr add)
{
	f[r].s=bs(f[r].s,add);
	f[r].b=max(f[r].b,add.s);
	if ((f[r].l==x)&&(f[r].r==y))
		return;
	int mid=(f[r].l+f[r].r)/2;
	if (y<=mid)	ins(r*2,x,y,add);
		else if (x>mid) ins(r*2+1,x,y,add);
			else ins(r*2,x,mid,add),ins(r*2+1,mid+1,y,add);
	return;
}

int fb(int r,int x,int y)
{
	if ((f[r].l==x)&&(f[r].r==y))
		return f[r].b;
	int mid=(f[r].l+f[r].r)/2;
	if (y<=mid)	return fb(r*2,x,y);
		else if (x>mid) return fb(r*2+1,x,y);
			else return max(fb(r*2,x,mid),fb(r*2+1,mid+1,y));
}

brr fs(int r,int x,int y)
{
	if ((f[r].l==x)&&(f[r].r==y))
		return f[r].s;
	int mid=(f[r].l+f[r].r)/2;
	if (y<=mid)	return fs(r*2,x,y);
		else if (x>mid) return fs(r*2+1,x,y);
			else return bs(fs(r*2,x,mid),fs(r*2+1,mid+1,y));
}

void mt(int r,int x,int y)
{
	f[r].s.s=INF;
	f[r].b=0;
	f[r].l=x,f[r].r=y;
	if (x==y) return;
	int mid=(x+y)/2;
	mt(r*2,x,mid);
	mt(r*2+1,mid+1,y);
	return;
}

int ans=0;

int bfs(int x,int y,int nw)
{
	int bb=fb(1,x,y);
	brr ss=fs(1,x,y);
	if (bb==nw)
		return 0;
	ans+=(ss.s-nw);
	if (x<ss.wz) bfs(x,ss.wz-1,ss.s);
	if (y>ss.wz) bfs(ss.wz+1,y,ss.s);
	return 0;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	mt(1,1,n+100);
	for (int i=1;i<=n;i++)
	{
		brr ax;
		scanf("%d",&ax.s);
		ax.wz=i;
		ins(1,i,i,ax);
	}
	bfs(1,n,0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
