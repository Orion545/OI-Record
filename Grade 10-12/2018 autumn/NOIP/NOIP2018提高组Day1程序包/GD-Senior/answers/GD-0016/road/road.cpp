#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int read();
int d[100000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int n=read();
    int minx=100001;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
    	d[i]=read();
    	if(d[i]<minx)minx=d[i];
    }
    sum=minx;
    for(int i=1;i<=n;i++)
    {
    	d[i]=d[i]-minx;
    }
    int flag=1;
    d[n+1]=0; 
    while(flag!=0)
    {
    	int cal=0;
    	flag=0;
    	int head=1000000,tail=0,minn=100000;
    	for(int i=1;i<=n+1;i++)
    	{
    		if(d[i]!=0)
    		{
    			head=min(head,i);
    			tail=i;
    			minn=min(minn,d[i]);
    			flag=1; 
    			cal=1;
    		} else{
    			if(cal==1)
    			{
    				
    				for(int j=head;j<=tail;j++)
    				{
    					d[j]=d[j]-minn;
    				}
    				sum+=minn;
    				head=100000,tail=0,minn=100000;
					cal=0;
    			}
    		}
    	}
    } cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
int read()
{	
	char ch=getchar();
	int x=0,f=1;
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
