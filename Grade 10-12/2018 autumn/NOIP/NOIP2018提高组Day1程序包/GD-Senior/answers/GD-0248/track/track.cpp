#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#define ll long long
using namespace std;
inline int read()
{
	int f=1,x=0;
	char c=getchar();
	while(!(c>='0'&&c<='9')){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return f*x;
}
struct edge
{
	int x,y,d,next;
}a[110000];int len,last[110000];
void ins(int x,int y,int d)
{
	len++;
	a[len].x=x,a[len].y=y,a[len].d=d;
	a[len].next=last[x];last[x]=len;
}
queue<int>q;
ll d[110000];
int in[51000];
bool v[51000];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n=read(),m=read();
	int st=0;ll ans=0;
	memset(in,0,sizeof(in));
	for(int i=1;i<=n-1;i++)
	{
		int x=read(),y=read(),d=read();
		in[x]++;in[y]++;
		ins(x,y,d);
		ins(y,x,d);
	}
	for(int i=1;i<=n;i++)
	{
		if(in[i]==1){st=i;break;}
	}
	if(m==1)
	{
		q.push(st);
		memset(v,false,sizeof(v));v[st]=true;
		memset(d,0,sizeof(d));
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(int k=last[x];k;k=a[k].next)
			{
				int y=a[k].y;
				if(d[y]<d[x]+a[k].d&&v[y]==false)
				{
					d[y]=d[x]+a[k].d;
					ans=max(d[y],ans);
					v[y]=true;
					q.push(y);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

