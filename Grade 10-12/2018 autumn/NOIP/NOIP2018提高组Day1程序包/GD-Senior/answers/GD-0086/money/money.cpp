#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int MAXN=105;
int t,n,a[MAXN],bj,bb,bk,bh,nice,zh,usee,b[MAXN],trueb,ttb,l;

int gcd(int a,int b)
{
    if (a%b==0)return b;
    else return gcd(b,a%b);
}

int zheng(int a)
{
    if (a<0)a=-a;
    return a;
}

void swap(int &x,int &y)
{
    int z=x;
    x=y;
    y=z;
}

void dfs(int o)
{
    trueb=0;
    while (trueb<=1<<o-1)
    {
        trueb++;
        l=0;bb=trueb;
        memset(b,0,sizeof(b));
        while (bb!=1)
        {
            b[++l]=bb%2;
			bb/=2;  
        }
        b[++l]=1;int rng=0;bj=0;
        for (int ig=1;ig<=l;ig++)
        if (b[ig])
        rng+=a[ig];
		if (!bj)
		{
		    int edg=a[o+1]-rng;
		    if (edg>1)
		    for (int ig=1;ig<=o;ig++)
		    {
		        nice=gcd(edg,a[ig]);
		        if (nice==a[ig])
		        {
		            bh=1;
		            break;
		        }
		    }
		    if (bh)break;
		}
    }
}

int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    scanf("%d",&t);
    for (int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
             scanf("%d",&a[i]);
             if (a[i]==1)bj=1;
        }
        if (n==1||bj==1)
        printf("1\n");
        else
        if (n==2)
        {
            nice=gcd(a[1],a[2]);
            if (a[1]==nice||a[2]==nice)printf("1\n");
            else printf("2\n");
        }
        else
        if (n==3)
        {
            nice=gcd(a[1],gcd(a[2],a[3]));
            if (nice==a[1]||nice==a[2]||nice==a[3])
            {
                printf("1\n");
                continue;
            }
            zh=a[1]+a[2]+a[3];bj=0;
            for (int j=1;j<=2;j++)
            {
                for (int k=j+1;k<=3;k++)
                {
                    int nice1=a[k],nice2=a[j];
                    nice=gcd(nice1,nice2);
                    if (nice==a[1]||nice==a[2]||nice==a[3])bj=1;
                    if (zheng(nice1-nice2)!=1)
                    {
                        nice=(zheng(nice1-nice2),zh-nice1-nice2);
                        if (nice==a[1]||nice==a[2]||nice==a[3])bj=1;
                    }
                }
            }
            if (bj)printf("2\n");
            else
            printf("3\n");
        }
        else
        {
            for (int j=1;j<n;j++)
            for (int k=j+1;k<=n;k++)
            if (a[j]>a[k])swap(a[j],a[k]);
            usee=n;
            for (int j=n;j>=1;j--)
            {
            	bh=0;
            	for (int k=1;k<=j-1;k++)
            	{
            	    nice=gcd(a[j],a[k]);
            	    if (nice==a[k])bh=1;
            	    if (bh)break;
            	}
            	if (bh==0)
            	dfs(j-1);
            	if (bh)usee--;
            	
            }
            printf("%d\n",usee);
        }
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
