#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int n,m,c[100010],f[100010][2];
int big=1000000000;
string s;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(int i=1; i<=n; i++) scanf("%d",&c[i]);
	int x,y;
	for(int i=1; i<=n-1; i++) scanf("%d %d",&x,&y);
	int a,b;
	for(int g=1; g<=m; g++)
	{
		scanf("%d %d %d %d",&a,&x,&b,&y);
		f[a][1-x]=big;
		f[b][1-y]=big;
		for(int i=1; i<=n; i++)
		{
			f[i][0]=f[i-1][1];
			f[i][1]=min(f[i-1][0]+c[i],f[i-1][1]+c[i]);
		}
		if(min(f[n][0],f[n][1])>=big) cout<<-1<<endl;
		else cout<<min(f[n][0],f[n][1])<<endl;
	}
	return 0;
}
