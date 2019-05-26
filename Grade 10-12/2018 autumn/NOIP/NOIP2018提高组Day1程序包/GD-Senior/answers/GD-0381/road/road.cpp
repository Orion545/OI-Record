#include <bits/stdc++.h>
using namespace std;

int rea()
{
	int x=0, f=1;
	char ch=getchar();
	while (!(isdigit(ch) || ch=='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=x * 10 + ch - 48, ch=getchar();
	return x * f;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int tmp=0 , ans=0 ,n = rea();
	for (int i=1; i<=n; i++)
	{
		int x = rea();
		if (x<=tmp) tmp=x;
		else
		{
			ans+=x - tmp;
			tmp=x;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
