#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[500001];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money,out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	    int b[500001]={0};
		int ans=0;
		int m;
		cin>>m;
		for(int j=1;j<=m;j++) cin>>a[j];
	    sort(a+1,a+n+1);
	    for(int k=1;k<=m;k++)
	     for(int l=1;l<k;l++)
	      if(a[k]%a[l]==0) 
		  {
		  	b[k]=1;
		  	break;
		  }
	    for(int k=1;k<=m;k++)
	     for(int l=1;l<k;l++)
	      for(int h=1;h<=m;h++)
             if(b[k]!=1)
			  if(b[h]!=1)   	      
	    	  if((a[k]-a[l])%a[h]==0) 
			  {
			  	b[k]=1;
			  	break;
			  }
	    for(int k=1;k<=m;k++) if(b[k]==0) ans++;
	    cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
	
