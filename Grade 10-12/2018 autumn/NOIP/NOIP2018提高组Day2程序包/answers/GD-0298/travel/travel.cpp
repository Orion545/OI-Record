#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,ans[5005],a,b,z,s[5005],the;
int f[5005][5005];
bool f1[5005];
bool pd(int g,int t)
{
	for(int i=1;i<=s[g];i++)
	 {
	 	if(f[g][i]<g)
	 	for(int j=1;j<=s[t];j++)
	     {
	     
	     	if(f[g][i]==f[t][j]&&!f1[f[t][j]]){the=j;return false;}
	     } 	
	 }
	return true;
}
void go(int st,int l)
{
	ans[z]=st;

	if(z>=n)return;

	sort(f[st]+1,f[st]+1+s[st]);
	for(int i=1;i<=s[st];i++)
	{
		if(!f1[f[st][i]])
		{
			the=0;
	          
			if(pd(f[st][i],l))
			{f1[f[st][i]]=true;
			  z++;
			  go(f[st][i],st);
			}
			else
			{
				f1[f[l][the]]=true;
				z++;
				go(f[l][the],l);
			}
		}
	}

	return ;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		s[a]++;s[b]++;
		f[a][s[a]]=b;
		f[b][s[b]]=a;
     }
     f1[1]=true;
     z=1;
	go(1,0);
	for(int i=1;i<=z;i++)
	cout<<ans[i]<<" ";
	return 0;
}
