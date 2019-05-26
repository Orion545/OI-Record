#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int MAXN=100005;
int n,a[MAXN],ans,bj[MAXN],tol,jian,w,st;

int minn(int x,int y){return x>y?y:x;}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d",&n);
    memset(bj,0,sizeof(bj));tol=n;
    for (int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
    	if (a[i]==0)
    	{
    	    bj[i]=1;
    	    tol--;
    	}
    }
    ans=0;st=1;
    while (tol)
    {
    	jian=MAXN;
    	w=n+1;
    	while (!a[st])st++;
        for (int i=st;i<=n;i++)
        if (a[i]!=0)jian=minn(a[i],jian);
        else 
        {
        	w=i;
        	break;
        }
        for (int j=w-1;j>=1;j--)
        {
            if (a[j]==0)break;
            a[j]-=jian;
            if (a[j]==0)
            {
                bj[j]=1;
                tol--;
            }
        }
        ans+=jian;
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
