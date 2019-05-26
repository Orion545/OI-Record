#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;char s=getchar();
	while(s>'9'||s<'0') 
	{
		if(s=='-') f=-1;
		s=getchar();
	}
	while(s<='9'&&s>='0') x=x*10+s-48,s=getchar();
	return x*f;
}
struct node{int x,y,next;}a[11000];int len=0,last[11000];
void ins(int x,int y)
{
	++len;
	a[len].x=x;a[len].y=y;a[len].next=last[x];last[x]=len;
}
int dep[5100],fa[5100],son[5100][5100],tot[5100],st,ed;
void dfs(int x,bool pd)
{
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y==fa[x]||!y) continue;
		else if(dep[y]) {st=x,ed=y;continue;}
		dep[y]=dep[x]+1;fa[y]=x;
		if(pd) son[x][++tot[x]]=y;
		dfs(y,pd);
	}
}
int cir[5100],num=0;
void get_cir()
{
	int x=ed;
	while(x!=st)
	{
		cir[++num]=x;
		x=fa[x];
	}
	cir[++num]=st;
}
int ans[5100],cnt=0;
void get_ans(int x)
{
	for(int i=1;i<=tot[x];i++)
	{
		ans[++cnt]=son[x][i];
		get_ans(son[x][i]);
	}
}
int la1,la2,xx1,yy1,xx2,yy2,la[5100];
inline void del(int p1,int p2)
{
	for(register int i=1;i<=len;i++) 
	{
		if(((a[i].x==p1&&a[i].y==p2)||(a[i].x==p2&&a[i].y==p1))&&!la1) xx1=a[i].x,yy1=a[i].y,a[i].y=a[i].x=0,la1=i;
		else if((a[i].x==p1&&a[i].y==p2)||(a[i].x==p2&&a[i].y==p1)) xx2=a[i].x,yy2=a[i].y,a[i].x=a[i].y=0,la2=i;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		ins(x,y);ins(y,x);
	}
	dep[1]=1,fa[1]=0;dfs(1,0);
	if(n==m)
	{
		get_cir();memset(la,63,sizeof(la));
		for(int i=1;i<=num;++i)
		{
			la1=la2=0;
			if(i<num) del(cir[i],cir[i+1]);
			else del(cir[num],cir[1]);
			memset(fa,0,sizeof(fa));memset(dep,0,sizeof(dep));memset(tot,0,sizeof(tot));
			fa[1]=0,dep[1]=1;dfs(1,1);
			for(register int j=1;j<=n;++j) sort(son[j]+1,son[j]+tot[j]+1);
			cnt=0;get_ans(1);
			bool pd=0;
			for(register int j=1;j<=cnt;++j)
			{
				if(la[j]==ans[j]) continue;
				else if(la[j]>ans[j]) {pd=1;break;}
				else {pd=0;break;}
			}
			if(pd) {for(register int j=1;j<=cnt;++j) la[j]=ans[j];}
			if(i<num) a[la1].x=xx1,a[la1].y=yy1,a[la2].x=xx2,a[la2].y=yy2;
		}
		printf("1");
		for(int i=1;i<=cnt;i++) printf(" %d",la[i]);
	}
	else
	{
		memset(fa,0,sizeof(fa));memset(dep,0,sizeof(dep));
		fa[1]=0,dep[1]=1;dfs(1,1);
		for(int i=1;i<=n;i++) sort(son[i]+1,son[i]+tot[i]+1);
		get_ans(1);
		printf("1");
		for(int i=1;i<=cnt;i++) printf(" %d",ans[i]);
	}
	return 0;
}
