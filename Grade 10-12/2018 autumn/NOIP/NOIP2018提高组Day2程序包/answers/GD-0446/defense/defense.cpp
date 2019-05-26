#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=2001;
int n,m,qwq[N][N],a,b,x,y,zz[N],v[N],mo[N];
char s[5];

int read()
{
	char c=getchar();int x=0,f=1;
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}



int cal(int x,int st)
{
	if(x==n)
	{
		if(st==1)return mo[x];
		else return 0; 
	}
	if(st==0)return cal(x+1,1);
	else return min(cal(x+1,1)+mo[x],cal(x+1,0)+mo[x]);
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();m=read();scanf("%s",s);
	for(int i=1;i<=n;i++)mo[i]=read();
	memset(qwq,0,sizeof(qwq));
	for(int i=1;i<n;i++)
	{
		a=read();b=read();
		qwq[a][b]=qwq[b][a]=1;qwq[a][0]++;qwq[b][0]++;
	}
	if(s[0]=='A')
	{
		for(int i=1;i<=m;i++)
		{
			a=read();x=read();b=read();y=read();
			if(a==b+1&&(b==1||a==n))printf("-1\n"),continue;
			else if(b==a+1&&(a==1||b==n))printf("-1\n"),continue;
			int aa=cal(1,0),bb=cal(1,1);
			printf("%d\n",min(aa,bb));
		}
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int i=1;i<=n;i++)zz[i]=-1,v[i]=0;
		a=read();x=read();b=read();y=read();zz[a]=x;zz[b]=y;
		if(x==0&&y==0&&(qwq[a][0]==0||qwq[b][0]==0&&(qwq[a][b]==1))){printf("-1");continue;}
		printf("%d\n",min(check(1,0),check(1,1)));
	}
}

