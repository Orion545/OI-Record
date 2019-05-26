#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
int T,n,a[101],m,f[1000001],v[1000001];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T>0)
	{   T--;
	    scanf("%d",&n);
	    for(int i=1;i<=n;i++)
	    {scanf("%d",&a[i]);
	    }
	    if(n==2)
	    {int j=a[1]*a[2]-a[1]-a[2];
	     if(j>=1)printf("%d\n",2);
	     else printf("%d\n",1);
	     continue;
	    }
	    if(n==3)
	    {   memset(f,0,sizeof(f));
	    	sort(a+1,a+4);
	    	int j=a[1]*a[2]-a[1]-a[2];
	    	if(j<1)
			 {printf("%d\n",1);continue;}
	    	f[0]=1;
	    	for(int i=a[1];i<=j;i++)
	    	if(f[i-a[1]] || (f[i-a[2]] && i>=a[2]) || (f[i-a[3]] && i>=a[3]))f[i]=1;
	    	bool p=false;
	    	for(int h=1;h<=j*10;h++)
	    	for(int k=1;k<=j*10;k++)
	    	{if(h*k-h-k>j)continue;
	    	 memset(v,0,sizeof(v));
	    	 v[0]=1;
			 for(int i=1;i<=j;i++)
	    	 {if((v[i-h] && i>=h) || (v[i-k] && i>=k))v[i]=1;
	    	  if(v[i]!=f[i])break;
	    	  if(i==j && v[i]==f[i])p=true;
	    	 }
	    	}
	    	if(p)printf("%d\n",2);
	    	else printf("%d\n",3);
	    	continue;
	    }
	
	}
	return 0;
}
