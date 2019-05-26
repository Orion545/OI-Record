#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int n,a[110],num,ans,t;
bool f;

void dfs1(int k,int p)
{
	int q;
	if (k==0) {f=true; return;}
	while(a[p]>k) --p;
	for(int i=p; i>=1; i--)
	{
	  q=1;
	  while(q*a[i]<=k)
	  {
	     dfs1(k-a[i]*q,i-1);	
		 ++q;	
	  }
	}
}

void dfs2(int k,int p)
{
	int q;
	if (k==0) {f=true; return;}
	while(a[p]>k) --p;
	for(int i=p; i>=1; i--)
	{
	  dfs2(k%a[i],i-1);	
    }
}


int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t)
	{
		--t;
		scanf("%d",&n);
    	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		if (a[1]==1) {printf("1\n"); continue;}
		if (n==2)
		{
			if (a[2]%a[1]==0) printf("1\n"); else printf("2\n");
		}
		 else
		{ 
 	      ans=n;
 	      for(int i=n; i>=2; i--)
 	      {
 	      	f=false;
 	      	dfs2(a[i],i-1);
 	      	if (f) --ans;
			else
			 {
			 	dfs1(a[i],i-1);
			 	if (f) --ans;
			 }   
 	      }
 	      printf("%d\n",ans);
	   }  
	}
	
	
	return 0;
}
