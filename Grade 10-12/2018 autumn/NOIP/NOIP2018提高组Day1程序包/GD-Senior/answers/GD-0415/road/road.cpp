#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<cstdio>
#include<math.h>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
const int N=100005;
struct Road{
	int l,r;
};
queue<Road> q;
int n,a[N],ans;
void read();
void read_into(int L,int R);
void work();
int find_min(int L,int R);
int main()
{
	read();
	work();
	return 0;
}
void work()
{
	while(!q.empty())
	{
		Road now=q.front();q.pop();
		int h=now.l,t=now.r,mid=find_min(h,t),rue=a[mid];
		ans+=rue;
		for(int i=h;i<=t;i++)
		  a[i]-=rue;
		if(h==t) continue;
		if(h<=mid-1) read_into(h,mid-1);
		if(t>=mid+1) read_into(mid+1,t);
	}
	printf("%d",ans);
}
int find_min(int L,int R)
{
	int num=0;
	for(int i=L;i<=R;i++)
	  if(a[i]<a[num])
	    num=i;
	return num;
}
void read()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	a[0]=100005;
	read_into(1,n);
}
void read_into(int L,int R)
{
	Road add_in;
	add_in.l=L;add_in.r=R;
	q.push(add_in);
}
