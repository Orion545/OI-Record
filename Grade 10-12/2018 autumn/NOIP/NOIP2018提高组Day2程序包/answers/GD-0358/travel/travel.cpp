#include<iostream>
#include<cstdio>
using namespace std;
int n,m,anss=0;
int a[5050][5],ans[5050];
bool ha[5050];
void zou(int s)
{
	ha[s]=false;
	ans[++anss]=s;
	for(int i=1;i<=a[s][0];i++)
	  for(int j=i+1;j<=a[s][0];j++)
	    if(a[s][i]>a[s][j])
	    if(ha[a[s][i]]&&ha[a[s][j]])
	    {
	    	int temp;
	    	temp=a[s][i];
			a[s][i]=a[s][j];
			a[s][j]=temp;	  
	    }
	for(int i=1;i<=a[s][0];i++)
	  if(ha[a[s][i]]!=false)
	    zou(a[s][i]);
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  ha[i]=true;
	for(int i=1;i<=n;i++)
	  a[i][0]=0;
	for(int i=1;i<=m;i++)
	{
		int b,c;
		cin>>b>>c;
		a[b][++a[b][0]]=c;
		a[c][++a[c][0]]=b;
	}
	zou(1);
	for(int i=1;i<=n-1;i++)
	  cout<<ans[i]<<" ";
	cout<<ans[n];
	return 0;
}
