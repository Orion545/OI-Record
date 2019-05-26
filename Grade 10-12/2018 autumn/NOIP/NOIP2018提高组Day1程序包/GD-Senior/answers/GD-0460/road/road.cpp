#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],k,n;bool c[100005]={false};int day;
/*void find0()
{
	p=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) p++;
		if(a[i]==0&&c[i]==true)
		{
			c[i]=false;
			if(a[i+1]!=0&&a[i-1]!=0&&i!=1&&i!=0) ++day;
		}
	}
}*/
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	day=b[n]; k=1;
	/*if(day==0)
	{
		cout<<'0'; return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=0)
		{
			k=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=1&&i!=n&&a[i+1]!=0&&a[i-1]!=0&&a[i]==0)
		{
			++day; c[i]=false;
		}
		if(a[i]!=0) a[i]=a[i]-b[k];
		if(a[i]==0&&c[i]==true)
		{
			c[i]=false;
			if(a[i+1]!=0&&a[i-1]!=0&&i!=1&&i!=n) ++day;
		}
	}*/	
	/*while(k<=n)
	{		
		k=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) k++;
			for(int j=1;j<=n;i++)
			{
				if(a[j]==0&&a[j+1]!=0&&a[j-1]!=0&&c[j]==false&&j!=1&&j!=n)
				{
					day++;
					c[j]=true;
				}
			}
			
		}
		for(int i=1;i<=n;i++) if(!c[i]) a[i]--;
	
	}	*/
	cout<<day;
	fclose(stdin); fclose(stdout);
	return 0;
}
