#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
	int x,y,c,next;
}a[110000];int len,last[51000];
inline void ins(int x,int y,int c)
{
	len++;
	a[len].x=x;a[len].y=y;a[len].c=c;
	a[len].next=last[x];last[x]=len;
}
//h1s
int ss=999999999;
int dfs(int x,int fa)
{
	int s=0,sc=0;
	for(int k=last[x];k>0;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa)
		{
			int z=dfs(y,x)+a[k].c;
			if(z>s){sc=s;s=z;}
			else sc=z;
		}
	}
	if(sc+s>ss)ss=sc+s;
	return s;
}
//h1t
//h2s
int ar[51000],n,m;
//h2t
//h3s
int aa[51000];
bool check(int x)
{
	int s=0,ss=0;
	for(int i=1;i<n;i++)
	{
		if(s+aa[i]>=x)
		{
			s=0;ss++;
		}
		else s=s+aa[i];
	}
	return ss>=m;
}
//h3t
//h4s
//h4t
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool bk1=true;
	bool bk2=true;int sr2=0;
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<n;i++)
	{
		int x,y,c;scanf("%d%d%d",&x,&y,&c);
		ins(x,y,c);ins(y,x,c);
		if(x!=1)bk1=false;
		ar[y-1]=c;
		if(y!=x+1)bk2=false;
		aa[x]=c;sr2=sr2+c;
	}
	if(m==1)
	{
		ss=0;int t=dfs(1,0);
		if(t>ss)ss=t;
		printf("%d\n",ss);
		return 0;
	}
	else if(bk1==true)
	{
		sort(ar+1,ar+n);
		int ss=0x3f3f3f3f,i;
		for(i=n-1;2*m>i;i--,m--)
		{
			if(ar[i]<ss)ss=ar[i];
		}
		for(int j=1;j<=m;j++)
		{
			int tk=ar[i-j+1]+ar[i-2*m+j];
			if(tk<ss)ss=tk;
		}
		printf("%d\n",ss);
		return 0;
	}
	else if(bk2==true)
	{
		int l=1,r=sr2;
		while(l<r)
		{
			int mid=(l+r+1)/2;
			if(check(mid))l=mid;
			else r=mid-1;
		}
		printf("%d\n",l);
	}
	return 0;
}
