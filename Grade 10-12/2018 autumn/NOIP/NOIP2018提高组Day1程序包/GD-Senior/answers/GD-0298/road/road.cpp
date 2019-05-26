#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005],k[100005],n,l,r,ans,z;
void dig(int l1,int r1)
{   if(l1>r1)return;
  int y=l1;
   int rp=2147483645;
	for(int i=l1;i<=r1;i++)
	 rp=min(rp,a[i]);
	 ans+=rp;
  for(int i=l1;i<=r1;i++)
	{
       a[i]=a[i]-rp;
		if(a[i]==0){z++;k[z];dig(y,i-1);y=i+1;}
	}
	if(a[r1]!=0)
	dig(y,r1);
	else dig(y,r1-1);
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
		    z++;
			k[z]=i;
		}
	}

	if(z==0){dig(1,n);}
	else
	{
	   l=1;
	   for(int i=1;i<=z;i++)
	   {
	   	 dig(l,k[i]-1);
	   	 l=k[i]+1;
	   }	
	   dig(l,n);
	}
   cout<<ans;
	return 0;
}
