#include<iostream>
#include<cstdio>
using namespace std;
int a[100002];
int ans=0;
void search(int x,int y)
{
	if(x==y)
	{
		ans+=a[x];
		a[x]=0;
		return ;
	}
	int p=0;
	for(int i=x;i<=y;i++)
	if(a[i]<a[p])
	p=i;
	ans+=a[p];
	for(int i=x;i<=y;i++)
	if(i!=p)
	a[i]-=a[p];
	a[p]=0;
	if(x<p)
	search(x,p-1);
	if(p<y)
	search(p+1,y);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	bool p=false;
	for(int i=1;i<n;i++)
	if(a[i]>a[i+1])
	{
		p=true;
		break;
	}
	if(!p)
	cout<<a[n]<<endl;
	else
	{
		p=false;
		for(int i=1;i<n;i++)
		if(a[i]<a[i+1])
		{
			p=true;
			break;
		}
		if(!p)
		cout<<a[1]<<endl;
		else
		{	
			a[0]=0x7ffffff;
			search(1,n);
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
