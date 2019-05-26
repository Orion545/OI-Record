#include<stdio.h>
struct map{
	int numv;
	int nume;
	int v[100001];
};
struct map g;
int a1,b1,a2,b2;

int min(int a,int b)
{
	return a<b?a:b;
}
int dp[100001][2]={0};

void donggui(int a)
{
	int i;
	for(i=1;i<=a;i++)
{
	
	if(i==a1)
	{
		if(a2==1)
	{
	dp[i][1]=min(dp[i-1][1]+g.v[i],dp[i-1][2]+g.v[i]);
	dp[i][2]=min(dp[i-1][1]+g.v[i],dp[i-1][2]+g.v[i]);
    continue;
	}
     else
     {
    dp[i][1]=dp[i-1][2];
    dp[i][2]=100000001;
    continue;
     }
    }
	if(i==b1)
	{
		if(b2==1)
	{
	dp[i][1]=min(dp[i-1][1]+g.v[i],dp[i-1][2]+g.v[i]);
	dp[i][2]=min(dp[i-1][1]+g.v[i],dp[i-1][2]+g.v[i]);
    continue;
	}
    else
    {
    dp[i][1]=dp[i-1][2];
    dp[i][2]=100000001;
    continue;
	}
}
    dp[i][1]=dp[i-1][2];
    dp[i][2]=min(dp[i-1][1]+g.v[i],dp[i-1][2]+g.v[i]);
}
}


int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int i,x,y,q,ans=0,w;
	char z[2];
	scanf("%d %d",&g.numv,&q);
	w=q;
	scanf("%s",&z);
	g.nume=g.numv-1;
	for(i=1;i<=g.numv;i++)
	{
		scanf("%d",&g.v[i]);
	}	
	for(i=1;i<=g.nume;i++)
	{
		scanf("%d %d",&x,&y);
	}
	q=w;
	for(i=1;i<=q;i++)
	{
		ans=0;
		scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
		if((a1==b1+1||a1==b1-1)&&a2==0&&b2==0)
		{
		   printf("-1\n");
		   continue;
	    }
	    donggui(g.numv);
	    ans=min(dp[g.numv][1],dp[g.numv][2]);
	    printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
