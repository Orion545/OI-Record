#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define N 2005
#define M 30005
using namespace std;

int i,j,k,t,n,cnt,m,w,a[N],f[M];

int gi()
{
	int res,w=1;
	char ch;
	while(ch=getchar(),ch<'0'||ch>'9')if(ch=='-')w=-1;
	res=ch-48;
	while(ch=getchar(),ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+ch-48;
	return res*w;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=gi();
	while(t--){
		memset(f,0,sizeof(f));
		m=0;cnt=0;f[0]=1;
		n=gi();
		for(i=1;i<=n;i++){
			a[i]=gi();
		}
		sort(a+1,a+n+1);
		m=a[n];
		for(i=1;i<=n;i++){
			w=a[i];
			if(f[w]){
				continue;
			}
			cnt++;
			for(j=w;j<=m;j++){
				if(f[j-w])f[j]=1;
			}
		}
		printf("%d\n",cnt);
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
