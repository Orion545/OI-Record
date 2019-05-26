#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;

int n;
int a[MAXN];
int ans;
pair<int,int> s[MAXN];
int l[MAXN],r[MAXN],v[MAXN],visit[MAXN];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		s[i]=make_pair(a[i],i);
	}
	sort(s+1,s+n+1);
	for(int i=n;i>=1;i--){
		int x=s[i].second;
		visit[x]=1;
		l[x]=r[x]=x;
		if(visit[x-1]){
			ans+=v[l[x-1]]-a[x];
			r[l[x-1]]=x;
			l[x]=l[x-1];
		}
		if(visit[x+1]){
			ans+=v[x+1]-a[x];
			l[r[x+1]]=l[x];
			r[l[x]]=r[x+1];
		}
		v[l[x]]=a[x];
	}
	ans+=v[1];
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
