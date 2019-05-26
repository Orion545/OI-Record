#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int map[5001][10],f[5001],ans[5001],k=0,n,num[5001];
int print()
{
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
}
void search(int i)
{      
	int mi=5002,check=0,ha=0;
		for(int j=0;j<=num[i]-1;j++)
	{
		   if(map[i][j]<mi&&f[map[i][j]]==0)
	      {
		     mi=min(mi,map[i][j]);
		     check=1;
	      }
	      
     }
         if(check==1)
	   {
	   	   if(f[i]==0)
	   	  {
	   		 k++;
     	     ans[k]=i;
	         f[i]=1;
		     if(k==n)print();
		     else search(mi);
	   	   }
		  else
		  {
		  	search(mi);
		  }
       }
       else
       {
       	int uy=0;
       	k++;
       	ans[k]=i;
       	f[i]=1;
       	for(int nc=k-1;nc>0;nc--)
       	{
       		for(int nb=0;nb<num[ans[nc]];nb++)
       		{
       			if(f[map[ans[nc]][nb]]==0)
				   {
				   	ha=ans[nc];
				   	uy=1;
				   	break;
				   }				   
       		}
       		if(uy==1)break;
       	}
       	if(k==n)print();
       	else search(ha);
       }
}
void pl(int i,int j)
{
	int k=0;
	while(map[i][k]!=0){k++;}
	map[i][k]=j;
	num[i]++;
}
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	memset(map,0,sizeof(map));
	memset(f,0,sizeof(f));
	memset(ans,0,sizeof(ans));
	memset(num,0,sizeof(num));
	int m,i=0,a,b;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>a>>b;
		pl(a,b);         //将城市放入map； 
		pl(b,a);
	}
	search(1);
	return 0;
}
