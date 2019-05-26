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
char op[3];
int c[110000];
struct node{int x,y,next;}a[210000];int len=0,last[210000];
void ins(int x,int y)
{
	++len;
	a[len].x=x;a[len].y=y;a[len].next=last[x];last[x]=len;
}
long long f[2100][2];
int v[2100];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n=read(),m=read();
	scanf("%s",op+1);
	if(op[1]=='A')
	{
		for(int i=1;i<=n;i++) c[i]=read();
		for(int i=1;i<n;i++)
		{
			int x=read(),y=read();
			ins(x,y),ins(y,x);
		}
		for(int i=1;i<=m;i++)
		{
			memset(v,-1,sizeof(v));memset(f,0,sizeof(f));
			int x=read(),op1=read(),y=read(),op2=read();
			if((x==y+1||y==x+1)&&op1&&op2) {printf("-1\n");continue;}
			else v[x]=op1,v[y]=op2;
			for(int j=1;j<=n;j++)
			{
				if(v[j]!=-1)
				{
					if(!v[j]) f[j][1]=1e9,f[j][0]=f[j-1][1];
					else f[j][0]=1e9,f[j][1]=min(f[j-1][0],f[j-1][1])+c[j];
				}
				else
				{
					f[j][0]=f[j-1][1];
					f[j][1]=min(f[j-1][0],f[j-1][1])+c[j];
				}
			}
			printf("%lld\n",min(f[n][0],f[n][1]));
		}
	}
	else printf("-1\n");
	return 0;
}
