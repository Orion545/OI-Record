#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
typedef long long LL;
const int N=1e5+5;
const LL inf=1e18;
int tot,a,an,b,bn;
int first[N],nex[N<<1],en[N<<1];
char ty[5];
int p[N],fa[N];
LL f[N][2];
inline int read()
{
	int X=0,w=0; char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
	return w?-X:X;
}
inline void insert(int x,int y)
{
	nex[++tot]=first[x];
	first[x]=tot;
	en[tot]=y;
}
inline LL min(LL x,LL y)
{
	return x<y?x:y;
}
void dfs(int x)
{
	for(int i=first[x];i;i=nex[i])
		if(en[i]^fa[x])
		{
			fa[en[i]]=x;
			dfs(en[i]);
		}
}
void work(int x)
{
	f[x][1]=p[x],f[x][0]=0;
	for(int i=first[x];i;i=nex[i])
		if(en[i]^fa[x])
		{
			work(en[i]);
			f[x][0]+=f[en[i]][1];
			f[x][1]+=min(f[en[i]][0],f[en[i]][1]);
		}
	if(x==a) f[x][an^1]=inf; else
		if(x==b) f[x][bn^1]=inf;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n=read(),m=read();
	scanf("%s",&ty);
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		insert(x,y);
		insert(y,x);
	}
	dfs(1);
	while(m--)
	{
		a=read(),an=read();
		b=read(),bn=read();
		if((fa[a]==b || fa[b]==a) && !(an+bn))
		{
			puts("-1");
			continue;
		}
		work(1);
		printf("%lld\n",min(f[1][0],f[1][1]));
	}
	return 0;
}
