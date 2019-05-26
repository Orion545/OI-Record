#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
using namespace std;
#define MAXN 100+10
#define INF 0x7fffffff

int T, n, a[MAXN], ans, maxl, tot;
int mp[1000000+10], pos[1000000+10];

int main(){
	freopen("money.in","r", stdin);
	freopen("money.out","w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
			scanf("%d", &a[i]);
		sort(a+1, a+1+n), ans=n;
		//for(int i=1; i<=n; i++)
			//printf("%d ", a[i]);
		//printf("\n");
		if(n==1)  {printf("1\n"); continue;}
		maxl=a[n-1]*a[n]-a[n-1]-a[n];
		memset(mp, 0, sizeof(mp)), tot=0;
		for(int i=1; i<=n; i++){
			if(mp[a[i]]==1) {ans--; /*printf("%d ", a[i]);*/}
			//else printf("%d ", a[i]);
			else  mp[a[i]]=1, pos[++tot]=a[i];
			for(int j=1; j<=tot; j++){
				if(pos[j]+a[i]>maxl)  continue;
				if(mp[pos[j]+a[i]]==0 && mp[pos[j]]==1)
					mp[pos[j]+a[i]]=1, pos[++tot]=pos[j]+a[i], mp[pos[j]+a[i]]=1;
			}
		}
		//printf("\n%d %d\n")
		printf("%d\n", ans);
	}
	fclose(stdin);  fclose(stdout);
	return 0;
}
