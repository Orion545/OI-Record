#include<iostream>
#include<cstdio>
using namespace std;
//const int N=10010;
//int a[N];
int main()
{
	//freopen("road.txt","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=1,ans=0,i=0,j=0;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	i=0;
	while(i<n)
	{
		while(a[i]==0 and i!=n)i++;
		if(i==n)break;
		j=i;
		while(1)
		{
			if(a[j]==0 or j==n)
			{
				ans++;
				break;
			}
			a[j]--;
			j++;
		}	
	}
	cout<<ans;
	return 0;
}
