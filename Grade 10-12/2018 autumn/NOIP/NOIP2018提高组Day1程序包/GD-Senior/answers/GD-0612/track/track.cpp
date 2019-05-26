#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int fa[50000],h[50000],dis[100000],des[100000],nxt[100000],cnt;
long long k,len[50000];
bool cmp(long long a,long long b)
{
	return a<b;
}
void build_tree(int p,int father)
{
	fa[p]=father;
	for(int i=h[p];i!=-1;i=nxt[i])
		if(des[i]!=father)
			build_tree(des[i],p);
}
long long build_track(int p)
{
	int size=0;
	for(int i=h[p];i!=-1;i=nxt[i])
		if(des[i]!=fa[p])
		{
			len[size]=dis[i]+build_track(des[i]);
			if(len[size]>=k)
				cnt++;
			else
				size++;
		}
	sort(len,len+size,cmp);
	// printf("%d ",p);
	// for(int i=0;i<size;i++)
		// printf("%lld ",len[i]);
	// putchar('\n');
	for(int i=0;i<size;i++)
		if(len[i]!=-1)
			for(int j=i+1;j<size;j++)
				if(len[i]+len[j]>=k)
				{
					cnt++;
					len[i]=len[j]=-1;
					break;
				}
	for(int i=size-1;i>=0;i--)
		if(len[i]!=-1)
			return len[i];
	return 0;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(h,-1,sizeof(h));
	int n,m;
	long long l=10000,r=0;
	scanf("%d%d",&n,&m);
	for(int i=0,a,b;i<n-1;i++)
	{
		scanf("%d%d%d",&a,&b,&dis[2*i]);
		a--;
		b--;
		dis[2*i+1]=dis[2*i];
		des[2*i]=b;
		nxt[2*i]=h[a];
		h[a]=2*i;
		des[2*i+1]=a;
		nxt[2*i+1]=h[b];
		h[b]=2*i+1;
		l=(l>dis[2*i])?dis[2*i]:l;
		r+=dis[2*i];
	}
	build_tree(0,-1);
	r=r/m;
	// printf("%lld %lld\n",l,r);
	// getchar();
	// getchar();
	for(k=(l+r)/2;l!=r;k=(l+r)/2)
	{
		if(l+1==r)
			k++;
		cnt=0;
		build_track(0);
		// printf("%lld %d\n",k,cnt);
		if(cnt>=m)
			l=k;
		else
			r=k-1;
	}
	printf("%lld",l);
	return 0;
}
