#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

struct jgt
{
	int to,next;
}qxx[10010];
int head[5010],ans[5010],a[5010],u,n,m,o,temp=1;
bool b[10010];

void add(int x,int y)
{
	qxx[temp].to=y;
	qxx[temp].next=head[x];
	head[x]=temp++;
}

void Sdg(int k,int shang)
{
	ans[++u]=k;
	int o1=o;
	for (int i=head[k];i;i=qxx[i].next)
	if (qxx[i].to!=shang) a[++o]=qxx[i].to;
	if (o==o1) return;
	
	sort(a+o1+1,a+o+1);
	int o2=o;
	for (int i=o1+1;i<=o2;i++)
	Sdg(a[i],k);
}

void Shu()
{
	u=0;
	Sdg(1,0);
	for (int i=1;i<=n;i++)
	printf("%d ",ans[i]);
	printf("\n");
}

void Hdg(int k,int shang)
{
	b[k]=true;
	ans[++u]=k;
	int o1=o;
	for (int i=head[k];i;i=qxx[i].next)
	if (b[qxx[i].to]==false) a[++o]=qxx[i].to;
	if (o==o1) return;
	
	sort(a+o1+1,a+o+1);
	int o2=o;
	for (int i=o1+1;i<=o2;i++)
	Hdg(a[i],k);
}

void Huan()
{
	u=0;
	Hdg(1,0);
	for (int i=1;i<=n;i++)
	printf("%d ",ans[i]);
	printf("\n");
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	
	if (n==m+1) Shu();
	else Huan();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
