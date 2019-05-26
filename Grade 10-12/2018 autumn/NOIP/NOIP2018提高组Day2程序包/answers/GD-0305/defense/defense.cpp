#include<bits/stdc++.h>
using namespace std;
int w[2010];
struct node{
	bool use;
	int x;
};
node f[2010];
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n=read(),m=read();char c[10];gets(c);
	for(int i=1;i<=n;i++)w[i]=read();
    for(int i=1;i<=n-1;i++){int x=read(),y=read();}
    if(c[0]=='A')
    {
    	f[1].x=w[1];
    	f[1].use=1;
    	if(w[1]>w[2])
		{
			f[2].x=w[2];
			f[2].use=1;
		}
		else f[2].x=f[1].x;
    	for(int i=3;i<=n;i++)
		{
			if(!f[i-1].use)
		  {
			f[i].x=f[i-2].x+w[i];
			f[i].use=1;
		  }
		  else 
		  {
		  	if(f[i-1].x>f[i-2].x+w[i])
		  	{
		  		f[i].x=f[i-2].x+w[i];
		  		f[i].use=1;
		  	}
		  	else
		  	{
		  		f[i].x=f[i-1].x;
		  		f[i].use=0;	
		    }  
		  }
		}
    	for(int i=1;i<=m;i++)
      {
    	int a=read(),x=read(),b=read(),y=read();
    	if( (a==b+1||a==b-1) && (!x)&&(!y) )
		{
			printf("-1\n");
			continue;
		}
    	if(a>=2&&x)
		{
			if(f[a-2].x>f[a-1].x)
			{
			    f[a].x=f[a-1].x+w[a]; 
			}
			else f[a].x=f[a-2].x+w[a];
			f[a].use=1;
			for(int j=a+1;j<=n;j++)
		 {
			if(!f[j-1].use)
		  {
			f[j].x=f[j-2].x+w[j];
			f[j].use=1;
		  }
		  else 
		  {
		  	if(f[j-1].x>f[j-2].x+w[j])
		  	{
		  		f[j].x=f[j-2].x+w[j];
		  		f[j].use=1;
		  	}
		  	else
		  	{
		  		f[j].x=f[j-1].x;
		  		f[j].use=0;	
		    }  
		  }
		 } 		
		}
		if(a<2&&x)
		{
			f[a].x=w[a];
			f[a].use=1;
			for(int j=a+1;j<=n;j++)
		{
			if(!f[j-1].use)
		  {
			f[j].x=f[j-2].x+w[j];
			f[j].use=1;
		  }
		  else 
		  {
		  	if(f[j-1].x>f[j-2].x+w[j])
		  	{
		  		f[j].x=f[j-2].x+w[j];
		  		f[j].use=1;
		  	}
		  	else
		  	{
		  		f[j].x=f[j-1].x;
		  		f[j].use=0;	
		    }  
		  }
		}
		}
		if(!x)
		{
			f[a].use=0;
			if(f[a-1].use==0)f[a].x=f[a-2].x;
			for(int j=a+1;j<=n;j++)
		{
			if(!f[j-1].use)
		  {
			f[j].x=f[j-2].x+w[j];
			f[j].use=1;
		  }
		  else 
		  {
		  	if(f[j-1].x>f[j-2].x+w[j])
		  	{
		  		f[j].x=f[j-2].x+w[j];
		  		f[j].use=1;
		  	}
		  	else
		  	{
		  		f[j].x=f[j-1].x;
		  		f[j].use=0;	
		    }  
		  }
		}		
		}	
		if(b>=2&&y)
		{
			if(f[b-2].x>f[b-1].x)
			{
			    f[b].x=f[b-1].x+w[b]; 
			}
			else f[b].x=f[b-2].x+w[b];
			f[b].use=1;
			for(int j=b+1;j<=n;j++)
		 {
			if(!f[j-1].use)
		  {
			f[j].x=f[j-2].x+w[j];
			f[j].use=1;
		  }
		  else 
		  {
		  	if(f[j-1].x>f[j-2].x+w[j])
		  	{
		  		f[j].x=f[j-2].x+w[j];
		  		f[j].use=1;
		  	}
		  	else
		  	{
		  		f[j].x=f[j-1].x;
		  		f[j].use=0;	
		    }  
		  }
		 } 		
		}
		if(b<2&&y)
		{
			f[b].x=w[b];
			f[b].use=1;
			for(int j=b+1;j<=n;j++)
		{
			if(!f[j-1].use)
		  {
			f[j].x=f[j-2].x+w[j];
			f[j].use=1;
		  }
		  else 
		  {
		  	if(f[j-1].x>f[j-2].x+w[j])
		  	{
		  		f[j].x=f[j-2].x+w[j];
		  		f[j].use=1;
		  	}
		  	else
		  	{
		  		f[j].x=f[j-1].x;
		  		f[j].use=0;	
		    }  
		  }
		}
		}
		if(!y)
		{
			f[b].use=0;
			if(f[b-1].use==0)f[b].x=f[b-2].x;
			for(int j=b+1;j<=n;j++)
		{
			if(!f[j-1].use)
		  {
			f[j].x=f[j-2].x+w[j];
			f[j].use=1;
		  }
		  else 
		  {
		  	if(f[j-1].x>f[j-2].x+w[j])
		  	{
		  		f[j].x=f[j-2].x+w[j];
		  		f[j].use=1;
		  	}
		  	else
		  	{
		  		f[j].x=f[j-1].x;
		  		f[j].use=0;	
		    }  
		  }
		}		
		}
		for(int j=1;j<=n;j++) printf("%d\n",f[n].x); 
      }
    }
	else for(int i=1;i<=m;i++)printf("-1\n");
	fclose(stdin);fclose(stdout);
	
	return 0;
}
