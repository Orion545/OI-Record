#include<cstdio>
#include<cstdlib>
#include<cstring>

struct map
{
	int x;
	int y;
};
map way[200001];
int first[100001],next[200001],p[100001],bz[100001],n,m,q,ans,type1,a,b,x,y,f[100001][2];
char type2;
int dg(int z,int s)
{
	int i,tf;
	if(z>n)
	{
		tf=1;
		for(i=1;i<=m/2;i++)
			if(bz[way[i].x]==0&&bz[way[i].y]==0){tf=0;break;}
		if(tf==1)
		{
			//for(i=1;i<=n;i++)printf("%d ",bz[i]);printf("\n");
			if(s<ans||ans==-1)ans=s;
		}
	}
	else
	{
		if(z==a)
		{
			if(x==0)dg(z+1,s);
			else
			{
				bz[z]=1;
				dg(z+1,s+p[z]);
				bz[z]=0;
			}
		}
		else if(z==b)
			 {
			 	if(y==0)dg(z+1,s);
			 	else
			 	{
			 		bz[z]=1;
			 		dg(z+1,s+p[z]);
			 		bz[z]=0;
			 	}
			 }
			 else
			 {
				dg(z+1,s);
				bz[z]=1;
				dg(z+1,s+p[z]);
				bz[z]=0;
			}
	}
}
int main()
{
freopen("defense.in","r",stdin);
freopen("defense.out","w",stdout);
int i,j;
scanf("%d %d %c%d\n",&n,&q,&type2,&type1);
for(i=1;i<n;i++)scanf("%d ",&p[i]);scanf("%d\n",&p[n]);
m=n-1;
for(i=1;i<=m;i++)
{
	scanf("%d %d\n",&way[i].x,&way[i].y);
	way[i+m].x=way[i].y;way[i+m].y=way[i].x;
}
m*=2;
for(i=m;i>=1;i--)next[i]=first[way[i].x],first[way[i].x]=i;
if(n<=10)
{
	while(q>=1)
	{
		scanf("%d %d %d %d\n",&a,&x,&b,&y);
		//printf("*%d %d %d %d*\n",a,x,b,y);
		ans=-1;
		dg(1,0);
		printf("%d\n",ans);
		q--;
	}
}
else if(type2=='A')
{
	while(q>=1)
	{
		scanf("%d %d %d %d",&a,&x,&b,&y);
		for(i=1;i<=n;i++)
		{
			if(i==a)
			{
				if(x==0)f[i][0]=f[i-1][1],f[i][1]=2000000000;
				else
				{
					f[i][0]=2000000000;
					if(f[i-1][0]<f[i-1][1])f[i][1]=f[i-1][0]+p[i];
					else f[i][1]=f[i-1][1]+p[i];
				}
			}
			if(i==b)
			{
				if(y==0)f[i][0]=f[i-1][1],f[i][1]=2000000000;
				else
				{
					f[i][0]=2000000000;
					if(f[i-1][0]<f[i-1][1])f[i][1]=f[i-1][0]+p[i];
					else f[i][1]=f[i-1][1]+p[i];
				}
			}
			if(i!=a&&i!=b)
			{
				f[i][0]=f[i-1][1];
				if(f[i-1][0]<f[i-1][1])f[i][1]=f[i-1][0]+p[i];
				else f[i][1]=f[i-1][1]+p[i];
			}
		}
		if(f[n][0]<f[n][1])ans=f[n][0];
		else ans=f[n][1];
		if(ans==2000000000)printf("-1\n");
		else printf("%d\n",ans);
		q--;
	}
}
return 0;
}
