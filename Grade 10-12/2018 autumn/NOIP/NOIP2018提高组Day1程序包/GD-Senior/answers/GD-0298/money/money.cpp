#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[105],t,n;
bool f;
void cha(int q,int z,int g)
{
	if(g==0){f=true;return;}
	if(q>z)return;
	if(f)return;
	if(a[q]==0)cha(q+1,z,g);
	int u=0;	

	while(a[q]*u<=g&&!f&&a[q]!=0)
	{
	
		cha(q+1,z,g-a[q]*u);
		u++;
    }
	return;
}
bool yu(int l,int r,int k)
{
	for(int i=l;i<=r;i++)
	{
	    if(a[i]!=0)if(k%a[i]==0)return true;
	}
	return false;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(int v=1;v<=t;v++)
	{
		cin>>n;
		bool odd=false;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]%2==1)odd=true;
		}
		sort(a+1,a+1+n);
		int p=n;
		if(a[1]==1){cout<<"1"<<endl;continue;}
		if(a[1]==2&&odd==true){cout<<"2"<<endl;continue;}
		if(a[1]==2&&odd==false){cout<<"1"<<endl;continue;}
	    for(int i=2;i<=n;i++)
		{
		   if(yu(1,i-1,a[i]))
		   {p--;a[i]=0;}
		    else
		    {
		    	f=false;
		   	  cha(1,i-1,a[i]);
		   	  if(f)p--;
		   	
		    }
		  }
	 cout<<p<<endl;
	}
  return 0;
}
