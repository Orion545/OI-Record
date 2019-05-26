#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int N=100005;
int n,s[N],ans;



int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for (int a=1;a<=n;++a) cin>>s[a];
	for (int a=1;a<=n;++a)
	{
		if (s[a]>s[a-1]) ans+=s[a]-s[a-1];
	}
	cout<<ans;
	
	
	
	
	fclose(stdin);fclose(stdout);return 0;
}
