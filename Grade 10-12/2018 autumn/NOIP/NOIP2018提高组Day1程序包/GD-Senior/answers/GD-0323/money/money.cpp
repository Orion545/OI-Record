#include<cstdio>
#include<cstring>
using namespace std;
int a[110],f[25010],g[25010],p[110],len,last[25010],next[110];
void add(int x,int y)
{
	p[++len]=y;
	next[len]=last[x];
	last[x]=len;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int tn,n,i,j,k;
	scanf("%d",&tn);
	while(tn--)
	{
		scanf("%d",&n);
		memset(last,0,sizeof(last));
		memset(g,0,sizeof(g));
		len=0;
		int s=0;
		for(i=1;i<=n;i++) 
		{
			scanf("%d",&k);
			if(!g[k])
			{
				g[k]=1;
				a[++s]=k;
				add(k,s);
			}
		}
		n=s;
		memset(f,0,sizeof(f));
		f[0]=1;
		for(i=1;i<=25000;i++) if(!f[i])
		{
			for(j=1;j<=n;j++) if(i>=a[j]&&f[i-a[j]]) 
			{
				f[i]=1;
				break;
			}
			for(j=last[i];j;j=next[j])
				for(k=1;k<=n;k++) if(k!=p[j]&&i>=a[k]&&f[i-a[k]]) 
				{
					s--;
					break;
				}
		}
		printf("%d\n",s);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
