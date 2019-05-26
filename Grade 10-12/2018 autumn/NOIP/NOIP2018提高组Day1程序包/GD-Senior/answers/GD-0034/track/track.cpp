#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int readin()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
const int maxn=100005;
int n,m,head[maxn],nxt[maxn],v[maxn],l[maxn],nume=2,save1[maxn],savesum=0;
void addedge(int x,int y,int z)
{
	v[nume]=y,l[nume]=z,nxt[nume]=head[x],head[x]=nume++;
	v[nume]=x,l[nume]=z,nxt[nume]=head[y],head[y]=nume++;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=readin(),m=readin();
	bool type1=true,type2=true;
	int x,y,z;
	for(int i=1;i<=n-1;i++)
	{
		x=readin(),y=readin(),z=readin(),addedge(x,y,z),save1[i]=z,savesum+=z;
		if(x!=1) type1=false;
		if(y!=x+1) type2=false;
	}
	if(type1)
	{
		sort(save1+1,save1+n);
		int l=save1[1],r=save1[n]+save1[n-1];
		while(l<r)
		{
			int mid=(l+r)/2+1,p=1,cnt=0;
			for(int i=n;i>=1;i--)
			{
				if(save1[i]>=mid){cnt++;continue;}
				while(p<i&&save1[p]+save1[i]<mid) p++;
				if(p>=i) break;
				cnt++;
			}
			if(cnt>=m) l=mid;
			else r=mid-1;
		}
		printf("%d\n",l);
	}
	else if(type2)
	{
		int l=0,r=savesum;
		while(l<r)
		{
			int mid=(l+r)/2+1,tmp=0,cnt=0;
			for(int i=1;i<=n-1;i++)
			{
				tmp+=save1[i];
				if(tmp>=mid)
					tmp=0,cnt++;
			}
			if(cnt>=m) l=mid;
			else r=mid-1;
		}
		printf("%d\n",l);
	}
	else
	{
		printf("%d\n",savesum/m);
	}
}

