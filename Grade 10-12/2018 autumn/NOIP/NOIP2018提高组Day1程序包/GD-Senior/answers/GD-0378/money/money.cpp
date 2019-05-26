#include<iostream>
#include<cstdio>
#include<algorithm>
#include<memory.h>
#include<vector>
#define MAXN 105
#define INF 100000007
using namespace std;
int a[MAXN],l[MAXN];
bool no[MAXN];
vector<int> q;
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,ans=0;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(l,0,sizeof(l));
		memset(no,0,sizeof(no));
		q.clear();
		for(int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) {
			if(!no[i]) {
				ans++;
				for(int j=1;j<=n;j++) {
					l[j]=a[j]%a[i];
					if(l[j]==0&&j!=i) no[j]=1;
				}
				for(int j=1;j<=n;j++) {
					if(!no[j]) {
						for(int k=j+1;k<=n;k++) {
							if(l[j]==l[k]) no[k]=1;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++) if(no[i]) a[i]=INF;
		sort(a+1,a+n+1);
		int maxx=a[ans];
		q.push_back(0);
		memset(no,0,sizeof(no));
		for(int i=1;i<=ans;i++) q.push_back(a[i]);	
		int cnt=ans,num=ans;
		for(int i=1;i<=num;i++) {
			for(int j=1;j<=cnt;j++) {
				if(q[i]+q[j]<=maxx) {
					q.push_back(q[i]+q[j]);cnt++;
				}
			}
		}
		for(int i=num+1;i<=cnt;i++) {
			for(int j=1;j<=num;j++) {
				if(!no[j]&&q[i]==a[j]) {
					no[j]=1;
					ans--;
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
