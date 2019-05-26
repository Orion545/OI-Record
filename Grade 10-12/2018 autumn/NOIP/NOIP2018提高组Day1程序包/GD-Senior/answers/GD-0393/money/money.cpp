#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int t,n;
int rec[25005];
int n_copy;
bool cmp(int a,int b)
{
	return a>b;
}
void work(int x)
{
	int m;
	if(x%2==0) m=x/2;
	else m=x/2+1;
	for(int a=1;a<=m;a++)
	{
		int b=x-a;
		if(a<=0||b<=0) continue;
		for(int i=1;i<=n_copy;i++)
		{
			for(int j=1;j<=n_copy;j++)
			{
				if(a%rec[i]==0&&b%rec[j]==0||a%rec[j]==0&&b%rec[i]==0) 
				{
					n--;return;
				}
			}
		}
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>rec[i];
		n_copy=n;
		sort(rec+1,rec+n+1,cmp);
		for(int i=1;i<=n_copy-1;i++)
		{
			work(rec[i]);
		}
		cout<<n<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}


