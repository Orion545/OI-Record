#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

struct jgt
{
	int to,next;
}qxx[200010];
int head[100010],f[100010][2],a[100010],bz[100010],n,m,temp=1;
char st[10];

void add(int x,int y)
{
	qxx[temp].to=y;
	qxx[temp].next=head[x];
	head[x]=temp++;
}

void dg(int k,int shang)
{
	bool b=false;
	int sum=0,o=0;
	for (int i=head[k];i;i=qxx[i].next)
	if (qxx[i].to!=shang)
	{
		b=true;
		dg(qxx[i].to,k);
		if (min(f[qxx[i].to][0],f[qxx[i].to][1])==(1<<29)) return;
		sum=sum+min(f[qxx[i].to][0],f[qxx[i].to][1]);
		o=o+f[qxx[i].to][1];
	}
	
	if (!b)
	{
		f[k][0]=0;
		f[k][1]=a[k];
		if (bz[k]!=0) f[k][1-(bz[k]-1)]=(1<<29);
		return;
	}
	
	f[k][1]=a[k]+sum;
	f[k][0]=o;
	
	if (bz[k]!=0) f[k][1-(bz[k]-1)]=(1<<29);
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	scanf("%d %d %s\n",&n,&m,st+1);
	for (int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	
	for (int i=1;i<=m;i++)
	{
		int p,q,x,y;
		scanf("%d%d%d%d",&x,&p,&y,&q);
		for (int j=1;j<=n;j++)
		f[j][0]=f[j][1]=(1<<29);
		bz[x]=p+1;
		bz[y]=q+1;
		
		dg(1,0);
		
		int ans=(1<<29);
		ans=min(ans,min(f[1][0],f[1][1]));
		if (ans==(1<<29)) printf("-1\n");
		else printf("%d\n",ans);
		
		bz[x]=0;
		bz[y]=0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
