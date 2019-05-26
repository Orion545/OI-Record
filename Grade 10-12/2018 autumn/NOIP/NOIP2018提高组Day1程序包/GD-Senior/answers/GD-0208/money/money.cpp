#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
bool re,t;
int i,j,k,l,zu,bi,yy,n,q,m,se,ans,p,a[30000],f[30000],c[30000],zs[10000];
bool dfs(int x,int y,int z)
{
	int o;
	if(y==z) return true;
	if(x==0) return false;
	o=f[x];
	while(y<=z)
	{
		y=y+o;
		re=dfs(x-1,y,z);
		if(re==true) return true;
	}
	return false;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&n);
	for(i=2;i<=1000;i++)
	{
	  t=true;
	  for(j=2;j<=i/2+1;j++) 
			if(i%j==0&&i!=j)
			{
				t=false;
				break;
			}	
	  if(t)
	  {
	  	q++;
	  	zs[q]=i;
	  }
	}
	for(i=1;i<=n;i++)
	{
		bi=0;
		se=0;
		scanf("%d",&m);
		for(j=1;j<=m;j++) 
		{
			t=true;
		    scanf("%d",&yy);
		    for(k=1;k<=se;k++)
		    if(f[k]%yy==0)
		    {
		    	yy=f[k];
		    	t=false;
		    	break;
		    }
		    else if(yy%f[k]==0) t=false;
		    if(t) 
			{
				se++;
				f[se]=yy;
				if(f[se]>bi) bi=f[se];
			}	
		}
		zu=se;
		for(j=1;j<=q;j++)
		{
	     if(zs[j]>bi) break;
		   p=0;
		   t=true;
		   for(k=1;k<=zu;k++)
		   if(f[k]!=zs[j])
		   {
		  	 if(f[k]%zs[j]!=0) 
		  	 {
		 	  		p++;
		 	  		c[p]=f[k];
			   }
		 	  else t=false;
		 	}
		 	  if(!t)
		 	  {
			  	 for(k=1;k<=p;k++) f[k]=c[k];
			   	  p++;
		 	  	  f[p]=zs[j];
		 	  	  zu=p;
		  	  }
		}
		sort(f+1,f+zu+1);
		ans=zu;
		for(j=zu;j>=2;j--) 
		{
			t=dfs(j-1,0,f[j]);
			if(t==true) ans--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
