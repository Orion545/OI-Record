#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int MAXN=100005;
int n,m,ans[MAXN],a[MAXN],x1[MAXN],x2[MAXN],y1[MAXN],y2[MAXN],edge[MAXN][2],lb[11][11];
char s[5];
int b[MAXN],l,bb,bd;

int minn(int a,int b){return a<b?a:b;}

int ok(int nb,int o)
{
    if (nb==x1[o]&&b[nb]!=x2[o])return 0;
    if (nb==y1[o]&&b[nb]!=y2[o])return 0;
    return 1;
}

int main()
{
    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
    scanf("%d%d%s",&n,&m,s);
    for (int i=1;i<=n;i++)
    scanf("%d",&a[i]);memset(lb,0,sizeof(lb));
    for (int j=1;j<=n-1;j++)
    {
        scanf("%d%d",&edge[j][0],&edge[j][1]);
        lb[edge[j][0]][edge[j][1]]=lb[edge[j][1]][edge[j][0]]=1;
	}
    
    for (int i=1;i<=m;i++)
    {
    	scanf("%d%d%d%d",&x1[i],&x2[i],&y1[i],&y2[i]);
        ans[i]=-1;
    }
    bb=1;l=0;
    while (bb)
    {
        bd=1;l++;b[l]=-1;
        while (bd)
        {
            b[l]++;
            if (b[l]<=1)
            {
            	int bj=1;
            	
            	if  (l==n)
            	{
            	     for (int i=1;i<=m;i++)
            	     {
            	     	int bh[11];memset(bh,0,sizeof(bh));
            	         int bj=1,anss=0;
            	         for (int j=1;j<=n;j++)
            	         if (!ok(j,i)){bj=0;break;}
						 else anss+=(a[j]*b[j]);
						 for (int j=1;j<=n;j++)
						 {
						 	 bh[j]=b[j];
						 	 for (int k=1;k<=n;k++)
						     if (b[j]==1&&lb[j][k])bh[k]=1;
						 }
						 for (int j=1;j<=n;j++)
						 if (!bh[j])bj=0;
						 if (bj)ans[i]=minn(ans[i],anss);
						 if (bj)if (ans[i]=-1)ans[i]=anss;
            	     }
            	}
            	else bd=0;
            }
            else
            {
                l--;
                if (l<1)
                {
                	bb=0;
                    bd=0;
                }
            }
        }
    }
    for (int i=1;i<=m;i++)
    printf("%d\n",ans[i]);
    fclose(stdin);fclose(stdout);
    return 0;
}
