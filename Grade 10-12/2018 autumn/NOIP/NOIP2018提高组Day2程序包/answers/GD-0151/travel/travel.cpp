#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool s[5000][5000];
bool flag[5000];
int du[5001];
int z,n,m;
void find1(int st)
{ 
	flag[st]=true;du[z]=st;z++;
	for(int i=2;i<=n;i++)
		if(s[st][i]&&(!flag[i]))find1(i);
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	memset(s,false,sizeof(s));
	memset(flag,false,sizeof(flag));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		s[a][b]=s[b][a]=true;
	}
	z=1;
	find1(1);
	for(int i=1;i<=n;i++)printf("%d ",du[i]);
	fclose(stdin);fclose(stdout);
	return 0;
}
