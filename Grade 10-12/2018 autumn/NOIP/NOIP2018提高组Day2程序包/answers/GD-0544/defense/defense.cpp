#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

struct node
{
	int x,y,next;
}a[210000];int len,last[110000];
void ins(int x,int y)
{
	len++;
	a[len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}

int A,B,X,Y,p[110000];
int f[3][110000];
void treeDP(int x,int fr)
{
	f[0][x]=0;f[1][x]=p[x];f[2][x]=0;
	bool bk=false;
	int mmin,mn=(1<<30);
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fr)
		{
			treeDP(y,x);
			
			if(f[0][x]==-1)continue;
			mmin=(1<<30);
			if(f[0][y]!=-1)mmin=min(mmin,f[0][y]);
			if(f[1][y]!=-1)mmin=min(mmin,f[1][y]);
			if(mmin==(1<<30))f[0][x]=-1;
			else f[0][x]+=mmin;
			if(mmin==f[1][y])bk=true;
			if(f[0][y]!=-1&&f[1][y]!=-1&&f[0][y]>f[1][y])mn=min(mn,f[1][y]-f[0][y]);
			
			if(f[1][x]==-1)continue;
			mmin=(1<<30);
			if(f[0][y]!=-1)mmin=min(mmin,f[0][y]);
			if(f[1][y]!=-1)mmin=min(mmin,f[1][y]);
			if(f[2][y]!=-1)mmin=min(mmin,f[2][y]);
			if(mmin==(1<<30))f[1][x]=-1;
			else f[1][x]+=mmin;
			
			if(f[2][x]==-1)continue;
			if(f[0][y]==-1)f[2][x]=-1;
			else f[2][x]+=f[0][y];
		}
	}
	if(bk==false)
	{
		if(mn==(1<<30))f[0][x]=-1;
		else f[0][x]+=mn;
	}
	
	if(X==x)
	{
		if(A==1)f[0][x]=f[2][x]=-1;
		else f[1][x]=-1;
	}
	if(Y==x)
	{
		if(B==1)f[0][x]=f[2][x]=-1;
		else f[1][x]=-1;
	}
}

char ss[10];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,Q,x,y;
	scanf("%d%d%s",&n,&Q,ss+1);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		ins(x,y),ins(y,x);
	}
	while(Q--)
	{
		scanf("%d%d%d%d",&X,&A,&Y,&B);
		treeDP(1,0);
		if(f[0][1]==-1&&f[1][1]==-1)printf("-1\n");
		else if(f[0][1]==-1)printf("%d\n",f[1][1]);
		else if(f[1][1]==-1)printf("%d\n",f[0][1]);
		else printf("%d\n",min(f[0][1],f[1][1]));
	}
	return 0;
}
