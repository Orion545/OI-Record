#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,z;
}a[100000];
bool v[40000][40000];
bool cmp(node e,node f)
{
	return e.z<f.z;
}
priority_queue <int> q;
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-1;j++)
	    {
	    	if(i!=j&&!v[i][j]) 
			{
				q.push(a[i].z+a[j].z);
				v[i][j]=v[j][i]=1;
			}
	    }
	}
	int i=1;
	while(!q.empty())
	{
		if(i==m) 
		{
			printf("%d ",q.top());
			break;
		}
		else 
		{
			q.pop();
			i++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
