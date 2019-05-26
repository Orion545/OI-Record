#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const ll inf=1e9;
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
	int x,y,next;
}a[110000];int len,last[110000];
void ins(int x,int y)
{
	len++;a[len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
char s[5];
int p[110000];
bool v[110000];
ll f[110000][4];int a1,p1,b1,q1;//1站人安全，2不站人不安全，0不站人安全 
void treedp(int x)
{
	f[x][1]=p[x],f[x][2]=0,f[x][0]=0;
	if((x==a1&&p1==1)||(x==b1&&q1==1))
	{
		f[x][2]=f[x][0]=inf;
	}
	if((x==a1&&p1==0)||(x==b1&&q1==0))
	{
		f[x][1]=inf;
	}
	bool bk=false;
	ll minn=1e9;
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(v[y]==false)
		{
			v[y]=true;
			treedp(y);
			if(f[y][1]<=f[y][0])bk=true;
			f[x][0]+=min(f[y][1],min(f[y][2],f[y][0]));
			minn=min(minn,max(f[y][1]-f[y][0],f[y][1]));
			f[x][1]+=min(f[y][1],min(f[y][2],f[y][0]));
			f[x][2]+=min(f[y][2],f[y][0]);
		}
	}
	if(bk==false)f[x][0]+=minn;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n=read(),m=read();scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		p[i]=read();	
	}
	for(int i=1;i<=n-1;i++)
	{
		int x=read(),y=read();
		ins(x,y);ins(y,x);
	}
	while(m--)
	{
		memset(f,0,sizeof(f));
		memset(v,false,sizeof(v));
		scanf("%d%d%d%d",&a1,&p1,&b1,&q1);
		v[1]=true;
		treedp(1);
		ll ans=min(f[1][0],f[1][1]);
		if(ans>=inf)printf("-1\n");
		else printf("%lld\n",ans);
	}
	return 0;
}

