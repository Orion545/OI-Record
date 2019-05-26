# include <bits/stdc++.h>

using namespace std;
const int maxN=105,MAX=25005;
int T,n,a[maxN],f[MAX+10];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
	    scanf("%d",&n);
	    for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	    sort(a+1,a+1+n);
	    int m=0;
	    memset(f,false,sizeof f);
	    f[0]=true;
	    for (int i=1; i<=n; i++)
	    if (!f[a[i]])
	    {
	    	m++;
	    	for (int j=0; j+a[i]<=MAX; j++)
	    	if (f[j]) f[j+a[i]]=true;
	    }
	    printf("%d\n",m);
	}
	return 0;
}
