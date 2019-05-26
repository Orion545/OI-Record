#include<bits/stdc++.h>
using namespace std;
long long n,a[100100],c[100100],ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=a[i]-a[i-1];
	}
	c[n+1]=-a[n];
	while (1)
	{
		bool flag=false;long long kaishi=0,he=0,minn=2147483647;
		for (int i=1;i<=n+1;i++)
		{
			he+=c[i];
		//	cout<<he<<" ";
			if (he!=0)
			{
			  flag=true;
			  if (he==c[i])
			    {kaishi=i;}
			  minn=min(he,minn);
		    }else
			{
			   //cout<<i<<" "<<minn<<endl;
			   if (kaishi)
			   {			
			   ans+=minn;  
	   		   c[kaishi]-=minn;
			   c[i]+=minn;
			   kaishi=0;minn=2147483647;
		       }
		    }
		}
		if (!flag) break;
	//	cout<<clock()<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
