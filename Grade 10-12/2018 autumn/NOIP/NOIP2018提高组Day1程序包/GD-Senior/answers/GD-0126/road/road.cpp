#include <iostream>
#include <cstdio>
#define MAXN 100005
using namespace std;

int n,d[MAXN],mind=99999,r;
long long ans=0;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		if (d[i]<mind) mind=d[i];
	}
	ans+=mind;
	for (int i=1;i<=n;i++) d[i]-=mind;
	for (int i=1;i<=n;i++){
		while (d[i]>0){
			r=i;
			for (int j=i+1;j<=n;j++){
				if (d[j]==0) break;
				r=j;
			}
			ans+=1;
			for (int j=i;j<=r;j++){
				d[j]--;
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
