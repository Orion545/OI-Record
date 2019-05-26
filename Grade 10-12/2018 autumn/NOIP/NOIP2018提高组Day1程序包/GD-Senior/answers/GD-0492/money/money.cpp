#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int line[102],cline[50002];
bool check[50002];
bool cmp(const int a,const int b)
{
	return a<b;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int iA,iB,k,t,n,ans,point=1;
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		ans=0;
		scanf("%d",&n);
		for(iA=1;iA<=n;iA++)
			scanf("%d",&line[iA]);
		sort(line+1,line+n+1,cmp);
		check[0]=true;cline[0]=k;
		for(iA=1;iA<=n;iA++)
		{
			if(check[line[iA]]==false || cline[line[iA]]!=k)
			{
				ans++;
				for(iB=0;iB+line[iA]<=line[n];iB++)
					if(check[iB]==true && cline[iB]==k)
					{
						check[iB+line[iA]]=true;
						cline[iB+line[iA]]=k;
					}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
