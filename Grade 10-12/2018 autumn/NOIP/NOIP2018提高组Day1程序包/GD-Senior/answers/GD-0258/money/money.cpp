#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
int T,n;
int b[110000],bb[110000],a[110],aa[110],c[110];
bool check(int k,int kk)
{
	int bjj=0;
	if(k!=kk) bjj=1;
	else 
	    {
	    for(int i=1;i<=k;i++)
	    if(b[i]!=bb[i]) {bjj=1;break;}
	    }
	if(bjj=1) return false;
	else return true;
}
void init()
{
	for(int i=1;i<=n;i++) a[i]=0,b[i]=0,c[i]=0,bb[i]=0;
}
int main()
{

	 freopen("money.in","r",stdin);
	 freopen("money.out","w",stdout);
	 scanf("%d",&T);
	 while(T!=0)
	 {
	 	T--;
		scanf("%d",&n);
	 	int ans,num=0,k=0,kk=0,_max=-100,d=0,u=0;
	 	for(int i=1;i<=n;i++) scanf("%d",&aa[i]);
	 	sort(aa+1,aa+n+1);
	 	for(int i=1;i<=n;i++)
	 	for(int j=i+1;j<=n;j++)
	 	{
	 	if(aa[i]==0) break;
	 	if(aa[j]%aa[i]==0) aa[j]=0;
	    }
	    for(int i=1;i<=n;i++) 
	    if(aa[i]!=0) a[++u]=aa[i];
	    
	    n=u;
	    ans=u;
	 	for(int i=1;i<=n;i++)
	 	for(int j=i+1;j<=n;j++)
	 	_max=max(_max,a[i]*a[j]-(a[i]+a[j]));
	 	
	 	/*for(int i=1;i<=_max;i++)
	 	{
	 	for(int j=1;j<=n;j++)
	 	  {
	 	  	if(a[j]>i&&a[j]%i!=0) num++;
	 		else if(i%a[j]!=0) num++;
	 	  }
	 	  if(num==n) b[++k]=i;
	 	  num=0;
	    }*/
	    
	   /* for(int i=0;i<(1<<n);i++)
	    {
	    	for(int j=0;j<n;j++)
	    	{
	    		if(i&(1<<j))
	    		{
	    			c[++d]=a[j];
	    		}
	    	}
	    	for(int p=1;p<=_max;p++)
			{
		 	 for(int j=1;j<=d;j++)
	         {
	        	if(c[j]%p!=0) num++;
	         }
	          if(num==n) bb[++kk]=p,num=0;
	        }
	        if(check(k,kk)) ans=min(ans,d);
	    }*/
	    
	    cout<<ans<<endl;
	    //init();
	 }
	 
	 return 0;
}

